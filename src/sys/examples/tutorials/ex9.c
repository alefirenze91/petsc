static char help[] = "Example for PetscOptionsInsertFileYAML\n";
/*T
   requires: yaml
T*/

#include <petscsys.h>
#include <petscviewer.h>

int main(int argc,char **argv)
{
  PetscErrorCode  ierr;
  char            filename[PETSC_MAX_PATH_LEN];
  PetscBool       flg;

  ierr = PetscInitialize(&argc,&argv,(char*)0,help);if (ierr) return ierr;
  ierr = PetscOptionsGetString(NULL,NULL,"-f",filename,sizeof(filename),&flg);
  if (flg) {
    ierr = PetscOptionsInsertFileYAML(PETSC_COMM_WORLD,filename,PETSC_TRUE);CHKERRQ(ierr);
  }
  ierr = PetscOptionsView(PETSC_NULL,PETSC_VIEWER_STDOUT_WORLD);CHKERRQ(ierr);
  ierr = PetscFinalize();
  return ierr;
}



/*TEST
   
   test:
      suffix: 1
      args: -f petsc.yml
      localrunfiles: petsc.yml
   
   test:
      suffix: 2
      requires: yaml
      args: -options_file_yaml petsc.yml
      localrunfiles: petsc.yml

TEST*/
