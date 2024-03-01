#include "MuStoppedActionInitialization.hh"
#include "MuStoppedPrimaryGeneratorAction.hh"
#include "MuStoppedRunAction.hh"
#include "MuStoppedEventAction.hh"
#include "MuStoppedTrackingAction.hh"
#include "MySensitiveDetector.hh"

MuStoppedActionInitialization::MuStoppedActionInitialization()
: G4VUserActionInitialization()
{}

MuStoppedActionInitialization::~MuStoppedActionInitialization()
{}

void MuStoppedActionInitialization::SetSensitiveDetector(MySensitiveDetector* senDet)
{
  sensitiveDetector = senDet;
}

void MuStoppedActionInitialization::Build() const
{
  SetUserAction(new MuStoppedPrimaryGeneratorAction);
  
  SetUserAction(new MuStoppedRunAction);
  
  MuStoppedEventAction* eventAction = new MuStoppedEventAction;
  SetUserAction(eventAction);
  sensitiveDetector->SetEventAction(eventAction);
  
  SetUserAction(new MuStoppedTrackingAction);
}

