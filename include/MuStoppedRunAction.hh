#ifndef MUSTOPPED_RUN_ACTION_HH
#define MUSTOPPED_RUN_ACTION_HH

#include "G4UserRunAction.hh"
#include "G4GenericMessenger.hh"

class MuStoppedRunAction : public G4UserRunAction
{
public:
  MuStoppedRunAction();
  virtual ~MuStoppedRunAction();

  virtual void BeginOfRunAction(const G4Run*);
  virtual void EndOfRunAction(const G4Run*);

private:
  G4GenericMessenger *fMessenger;
  G4String OutFileName;
};

#endif // MUSTOPPED_RUN_ACTION_HH

