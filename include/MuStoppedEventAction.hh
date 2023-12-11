#ifndef MUSTOPPED_EVENT_ACTION_HH
#define MUSTOPPED_EVENT_ACTION_HH

#include "G4UserEventAction.hh"

class MuStoppedEventAction : public G4UserEventAction
{
public:
  MuStoppedEventAction();
  virtual ~MuStoppedEventAction();

  virtual void BeginOfEventAction(const G4Event*);
  virtual void EndOfEventAction(const G4Event*);
};

#endif // MUSTOPPED_EVENT_ACTION_HH

