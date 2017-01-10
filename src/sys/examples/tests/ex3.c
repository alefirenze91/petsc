
static char help[] = "Tests catching of floating point exceptions.\n\n";

#include <petscsys.h>

int CreateError(PetscReal x)
{
  PetscErrorCode ierr;

  PetscFunctionBegin;
  x    = 1.0/x;
  ierr = PetscPrintf(PETSC_COMM_SELF,"x = %g\n",(double)x);CHKERRQ(ierr);
  PetscFunctionReturn(0);
}

int main(int argc,char **argv)
{
  PetscErrorCode ierr;
  ierr = PetscInitialize(&argc,&argv,(char*)0,help);if (ierr) return ierr;
  ierr = PetscPrintf(PETSC_COMM_SELF,"This is a contrived example to test floating pointing\n");CHKERRQ(ierr);
  ierr = PetscPrintf(PETSC_COMM_SELF,"It is not a true error.\n");CHKERRQ(ierr);
  ierr = PetscPrintf(PETSC_COMM_SELF,"Run with -fp_trap to catch the floating point error\n");CHKERRQ(ierr);
  ierr = CreateError(0.0);CHKERRQ(ierr);
  return 0;
}



/*TEST

   test:
      args: -fp_trap
      filter: grep "Floating point exception"

TEST*/
