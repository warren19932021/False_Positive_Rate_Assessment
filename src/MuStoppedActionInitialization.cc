#include "MuStoppedActionInitialization.hh"
#include "MuStoppedPrimaryGeneratorAction.hh"
#include "MuStoppedRunAction.hh"
#include "MuStoppedEventAction.hh"
#include "MuStoppedTrackingAction.hh"

MuStoppedActionInitialization::MuStoppedActionInitialization()
: G4VUserActionInitialization()
{}

MuStoppedActionInitialization::~MuStoppedActionInitialization()
{}


void MuStoppedActionInitialization::Build() const
{
  SetUserAction(new MuStoppedPrimaryGeneratorAction);
  SetUserAction(new MuStoppedRunAction);
  SetUserAction(new MuStoppedEventAction);
  SetUserAction(new MuStoppedTrackingAction);
}

