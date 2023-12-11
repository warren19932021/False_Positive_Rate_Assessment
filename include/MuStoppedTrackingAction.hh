#ifndef MUSTOPPED_TRACKING_ACTION_HH
#define MUSTOPPED_TRACKING_ACTION_HH

#include "G4UserTrackingAction.hh"

class MuStoppedTrackingAction : public G4UserTrackingAction
{
public:
  MuStoppedTrackingAction();
  virtual ~MuStoppedTrackingAction();

  virtual void PreUserTrackingAction(const G4Track*);
  virtual void PostUserTrackingAction(const G4Track*);
};

#endif // MUSTOPPED_TRACKING_ACTION_HH

