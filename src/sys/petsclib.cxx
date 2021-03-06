
#ifdef BOUT_HAS_PETSC

#include <bout/petsclib.hxx>

#include <output.hxx>

// Define all the static member variables
int PetscLib::count = 0;
char PetscLib::help[] = "BOUT++: Uses finite difference methods to solve plasma fluid problems in curvilinear coordinates";
int PetscLib:: argc = 0;
char** PetscLib::argv = 0;
PetscLogEvent PetscLib::USER_EVENT = 0;

PetscLib::PetscLib() {
  if(count == 0) {
    // Initialise PETSc
    
    output << "Initialising PETSc\n";
    PetscInitialize(&argc,&argv,PETSC_NULL,help);
    PetscLogEventRegister("Total BOUT++",0,&USER_EVENT);
    PetscLogEventBegin(USER_EVENT,0,0,0,0);
  }
  count++;
}

PetscLib::~PetscLib() {
  count--;
  if(count == 0) {
    // Finalise PETSc
    output << "Finalising PETSc\n";
    PetscLogEventEnd(USER_EVENT,0,0,0,0);
    PetscFinalize();
  }
}

#endif // BOUT_HAS_PETSC

