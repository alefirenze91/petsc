#include <petsc-private/fortranimpl.h>
#include <petscdmcomplex.h>
#include <../src/sys/f90-src/f90impl.h>

#ifdef PETSC_HAVE_FORTRAN_CAPS
#define dmcomplexgetcone_                  DMCOMPLEXGETCONE
#define dmcomplexrestorecone_              DMCOMPLEXRESTORECONE
#define dmcomplexgetconeorientation_       DMCOMPLEXGETCONEORIENTATION
#define dmcomplexrestoreconeorientation_   DMCOMPLEXRESTORECONEORIENTATION
#define dmcomplexgetsupport_               DMCOMPLEXGETSUPPORT
#define dmcomplexrestoresupport_           DMCOMPLEXRESTORESUPPORT
#define dmcomplexgettransitiveclosure_     DMCOMPLEXGETTRANSITIVECLOSURE
#define dmcomplexrestoretransitiveclosure_ DMCOMPLEXRESTORETRANSITIVECLOSURE
#define dmcomplexvecgetclosure_            DMCOMPLEXVECGETCLOSURE
#define dmcomplexvecrestoreclosure_        DMCOMPLEXVECRESTORECLOSURE
#define dmcomplexvecsetclosure_            DMCOMPLEXVECSETCLOSURE
#define dmcomplexcreatesection_            DMCOMPLEXCREATESECTION
#define dmcomplexcomputecellgeometry_      DMCOMPLEXCOMPUTECELLGEOMETRY
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define dmcomplexgetcone_                  dmcomplexgetcone
#define dmcomplexrestorecone_              dmcomplexrestorecone
#define dmcomplexgetconeorientation_       dmcomplexgetconeorientation
#define dmcomplexrestoreconeorientation_   dmcomplexrestoreconeorientation
#define dmcomplexgetsupport_               dmcomplexgetsupport
#define dmcomplexrestoresupport_           dmcomplexrestoresupport
#define dmcomplexgettransitiveclosure_     dmcomplexgettransitiveclosure
#define dmcomplexrestoretransitiveclosure_ dmcomplexrestoretransitiveclosure
#define dmcomplexvecgetclosure_            dmcomplexvecgetclosure
#define dmcomplexvecrestoreclosure_        dmcomplexvecrestoreclosure
#define dmcomplexvecsetclosure_            dmcomplexvecsetclosure
#define dmcomplexcreatesection_            dmcomplexcreatesection
#define dmcomplexcomputecellgeometry_      dmcomplexcomputecellgeometry
#endif

/* Definitions of Fortran Wrapper routines */
EXTERN_C_BEGIN

void PETSC_STDCALL dmcomplexgetcone_(DM *dm, PetscInt *p, F90Array1d *ptr, int *__ierr PETSC_F90_2PTR_PROTO(ptrd))
{
  const PetscInt *v;
  PetscInt        n;

  *__ierr = DMComplexGetConeSize(*dm, *p, &n);if (*__ierr) return;
  *__ierr = DMComplexGetCone(*dm, *p, &v);if (*__ierr) return;
  *__ierr = F90Array1dCreate((void *) v, PETSC_INT, 1, n, ptr PETSC_F90_2PTR_PARAM(ptrd));
}

void PETSC_STDCALL dmcomplexrestorecone_(DM *dm, PetscInt *p, F90Array1d *ptr, int *__ierr PETSC_F90_2PTR_PROTO(ptrd))
{
  *__ierr = F90Array1dDestroy(ptr, PETSC_INT PETSC_F90_2PTR_PARAM(ptrd));if (*__ierr) return;
}

void PETSC_STDCALL dmcomplexgetconeorientation_(DM *dm, PetscInt *p, F90Array1d *ptr, int *__ierr PETSC_F90_2PTR_PROTO(ptrd))
{
  const PetscInt *v;
  PetscInt        n;

  *__ierr = DMComplexGetConeSize(*dm, *p, &n);if (*__ierr) return;
  *__ierr = DMComplexGetConeOrientation(*dm, *p, &v);if (*__ierr) return;
  *__ierr = F90Array1dCreate((void *) v, PETSC_INT, 1, n, ptr PETSC_F90_2PTR_PARAM(ptrd));
}

void PETSC_STDCALL dmcomplexrestoreconeorientation_(DM *dm, PetscInt *p, F90Array1d *ptr, int *__ierr PETSC_F90_2PTR_PROTO(ptrd))
{
  *__ierr = F90Array1dDestroy(ptr, PETSC_INT PETSC_F90_2PTR_PARAM(ptrd));if (*__ierr) return;
}

void PETSC_STDCALL dmcomplexgetsupport_(DM *dm, PetscInt *p, F90Array1d *ptr, int *__ierr PETSC_F90_2PTR_PROTO(ptrd))
{
  const PetscInt *v;
  PetscInt        n;

  *__ierr = DMComplexGetSupportSize(*dm, *p, &n);if (*__ierr) return;
  *__ierr = DMComplexGetSupport(*dm, *p, &v);if (*__ierr) return;
  *__ierr = F90Array1dCreate((void *) v, PETSC_INT, 1, n, ptr PETSC_F90_2PTR_PARAM(ptrd));
}

void PETSC_STDCALL dmcomplexrestoresupport_(DM *dm, PetscInt *p, F90Array1d *ptr, int *__ierr PETSC_F90_2PTR_PROTO(ptrd))
{
  *__ierr = F90Array1dDestroy(ptr, PETSC_INT PETSC_F90_2PTR_PARAM(ptrd));if (*__ierr) return;
}

void PETSC_STDCALL dmcomplexgettransitiveclosure_(DM *dm, PetscInt *p, PetscBool *useCone, F90Array1d *ptr, int *__ierr PETSC_F90_2PTR_PROTO(ptrd))
{
  PetscInt *v;
  PetscInt  n;

  *__ierr = DMComplexGetTransitiveClosure(*dm, *p, *useCone, &n, &v);if (*__ierr) return;
  *__ierr = F90Array1dCreate((void *) v, PETSC_INT, 1, n, ptr PETSC_F90_2PTR_PARAM(ptrd));
}

void PETSC_STDCALL dmcomplexrestoretransitiveclosure_(DM *dm, PetscInt *p, F90Array1d *ptr, int *__ierr PETSC_F90_2PTR_PROTO(ptrd))
{
  *__ierr = F90Array1dDestroy(ptr, PETSC_INT PETSC_F90_2PTR_PARAM(ptrd));if (*__ierr) return;
}

void PETSC_STDCALL dmcomplexvecgetclosure_(DM *dm, PetscSection *section, Vec *x, PetscInt *point, F90Array1d *ptr, int *__ierr PETSC_F90_2PTR_PROTO(ptrd))
{
  const PetscScalar *v;
  PetscInt           n;

  *__ierr = DMComplexVecGetClosure(*dm, *section, *x, *point, &n, &v);if (*__ierr) return;
  *__ierr = F90Array1dCreate((void *) v, PETSC_SCALAR, 1, n, ptr PETSC_F90_2PTR_PARAM(ptrd));
}

void PETSC_STDCALL dmcomplexvecrestoreclosure_(DM *dm, PetscSection *section, Vec *v, PetscInt *point, F90Array1d *ptr, int *__ierr PETSC_F90_2PTR_PROTO(ptrd))
{
  *__ierr = F90Array1dDestroy(ptr, PETSC_INT PETSC_F90_2PTR_PARAM(ptrd));if (*__ierr) return;
}

void PETSC_STDCALL dmcomplexvecsetclosure_(DM *dm, PetscSection *section, Vec *v, PetscInt *point, F90Array1d *ptr, InsertMode *mode, int *__ierr PETSC_F90_2PTR_PROTO(ptrd))
{
  PetscScalar *array;

  *__ierr = F90Array1dAccess(ptr, PETSC_SCALAR, (void **) &array PETSC_F90_2PTR_PARAM(ptrd));if (*__ierr) return;
  *__ierr = DMComplexVecSetClosure(*dm, *section, *v, *point, array, *mode);
}

void PETSC_STDCALL dmcomplexcreatesection_(DM *dm, PetscInt *dim, PetscInt *numFields, F90Array1d *ptrC, F90Array1d *ptrD, PetscInt *numBC, F90Array1d *ptrF, F90Array1d *ptrP, PetscSection *section, int *__ierr PETSC_F90_2PTR_PROTO(ptrCd) PETSC_F90_2PTR_PROTO(ptrDd) PETSC_F90_2PTR_PROTO(ptrFd) PETSC_F90_2PTR_PROTO(ptrPd))
{
  PetscInt *numComp;
  PetscInt *numDof;
  PetscInt *bcField;
  IS       *bcPoints;

  *__ierr = F90Array1dAccess(ptrC, PETSC_INT, (void **) &numComp PETSC_F90_2PTR_PARAM(ptrCd));if (*__ierr) return;
  *__ierr = F90Array1dAccess(ptrD, PETSC_INT, (void **) &numDof  PETSC_F90_2PTR_PARAM(ptrDd));if (*__ierr) return;
  *__ierr = F90Array1dAccess(ptrF, PETSC_INT, (void **) &bcField PETSC_F90_2PTR_PARAM(ptrFd));if (*__ierr) return;
  *__ierr = F90Array1dAccess(ptrP, PETSC_FORTRANADDR, (void **) &bcPoints PETSC_F90_2PTR_PARAM(ptrPd));if (*__ierr) return;
  *__ierr = DMComplexCreateSection(*dm, *dim, *numFields, numComp, numDof, *numBC, bcField, bcPoints, section);
}

void PETSC_STDCALL dmcomplexcomputecellgeometry_(DM *dm, PetscInt *cell, F90Array1d *ptrV, F90Array1d *ptrJ, F90Array1d *ptrIJ, PetscReal *detJ, int *__ierr PETSC_F90_2PTR_PROTO(ptrVd) PETSC_F90_2PTR_PROTO(ptrJd) PETSC_F90_2PTR_PROTO(ptrIJd))
{
  PetscReal *v0;
  PetscReal *J;
  PetscReal *invJ;

  *__ierr = F90Array1dAccess(ptrV,  PETSC_REAL, (void **) &v0   PETSC_F90_2PTR_PARAM(ptrVd));if (*__ierr) return;
  *__ierr = F90Array1dAccess(ptrJ,  PETSC_REAL, (void **) &J    PETSC_F90_2PTR_PARAM(ptrJd));if (*__ierr) return;
  *__ierr = F90Array1dAccess(ptrIJ, PETSC_REAL, (void **) &invJ PETSC_F90_2PTR_PARAM(ptrIJd));if (*__ierr) return;
  *__ierr = DMComplexComputeCellGeometry(*dm, *cell, v0, J, invJ, detJ);
}

EXTERN_C_END