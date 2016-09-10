
#include <petscconf.h>
#include <stdio.h>
#include <fcntl.h>
#if defined(PETSC_HAVE_UNISTD_H)
#include <unistd.h>
#endif
#if defined(PETSC_HAVE_IO_H)
#include <io.h>
#endif
#include <stdlib.h>

/*
  Demonstrates dumping matrix/vector from heritage code for PETSc.
   Note does not do bit swapping, so will not generate proper PETSc files on some systems.
*/

void Store2DArray(int,int,double*,const char*,int*);
void Store1DArray(int,double*,const char*,int*);

#undef __FUNCT__
#define __FUNCT__ "main"
int main(int argc,char **args)
{
  double a[100],v[10];
  int    i,j,fd = 0;

  for (i=0; i<100; i++) {
    a[i] = i + 1;
  }
  for (j=0; j<10; j++) {
    v[j] = j;
  }

  Store2DArray(10,10,a,"array.dat",&fd);
  Store1DArray(10,v,"array.dat",&fd);
  return 0;
}

#undef __FUNCT__
#define __FUNCT__ "Store2DArray"
void Store2DArray(int m,int n,double *a,const char *filename,int *fdd)
{
  int     fd = *fdd;
  int     i,j;
  int     nz = -1,classid = 1211216;
  double  *vals;
  ssize_t nb;

  if (!fd) {
    fd = creat(filename,0666);
    if (fd == -1) {
      fprintf(stdout,"Unable to open binary file\n");
      exit(0);
    }
    *fdd = fd;
  }
  nb = write(fd,&classid,sizeof(int));if (nb != sizeof(int)) abort();
  nb = write(fd,&m,sizeof(int));if (nb != sizeof(int)) abort();
  nb = write(fd,&n,sizeof(int));if (nb != sizeof(int)) abort();
  nb = write(fd,&nz,sizeof(int));if (nb != sizeof(int)) abort();

  /*
     transpose the matrix, since it is stored by rows on the disk
   */
  vals = (double*) malloc(m*n*sizeof(double));
  if (!vals) {
    fprintf(stdout,"Out of memory ");
    exit(0);
  }
  for (i=0; i<m; i++) {
    for (j=0; j<n; j++) {
      vals[i+m*j] = a[j+i*n];
    }
  }
  nb = write(fd,vals,m*n*sizeof(double));if (nb != m*n*sizeof(double)) abort();
  free(vals);

}

#undef __FUNCT__
#define __FUNCT__ "Store1DArray"
void Store1DArray(int m,double *a,const char *filename,int *fdd)
{
  int     fd = *fdd;
  ssize_t nb;
  int     classid = 1211214;  /* classid for vectors */

  if (fd == -1) {
    fd = creat(filename,0666);
    if (fd == -1) {
      fprintf(stdout,"Unable to open binary file\n");
      exit(0);
    }
    *fdd = fd;
  }
  nb = write(fd,&classid,sizeof(int));if (nb != sizeof(int)) abort();
  nb = write(fd,&m,sizeof(int));if (nb != sizeof(int)) abort();
  nb = write(fd,a,m*sizeof(double));if (nb != m*sizeof(double)) abort();
}


