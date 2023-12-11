#include "MuStoppedTrackingAction.hh"

#include "G4ParticleDefinition.hh"
#include "G4Step.hh"


MuStoppedTrackingAction::MuStoppedTrackingAction()
{}

MuStoppedTrackingAction::~MuStoppedTrackingAction()
{}

void MuStoppedTrackingAction::PreUserTrackingAction(const G4Track*)
{
  // Add code to be executed before tracking a particle
}

void MuStoppedTrackingAction::PostUserTrackingAction(const G4Track* track)
{

}

