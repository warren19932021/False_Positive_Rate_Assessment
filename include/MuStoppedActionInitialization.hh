#ifndef MUSTOPPED_ACTION_INITIALIZATION_HH
#define MUSTOPPED_ACTION_INITIALIZATION_HH

#include "G4VUserActionInitialization.hh"

class MuStoppedActionInitialization : public G4VUserActionInitialization
{
public:
  MuStoppedActionInitialization();
  virtual ~MuStoppedActionInitialization();

  virtual void Build() const;
};

#endif // MUSTOPPED_ACTION_INITIALIZATION_HH

