#include "MuStoppedPrimaryGeneratorAction.hh"
#include "G4GeneralParticleSource.hh"

MuStoppedPrimaryGeneratorAction::MuStoppedPrimaryGeneratorAction()
: G4VUserPrimaryGeneratorAction(),
  fG4GeneralParticleSource(0)
{
  fG4GeneralParticleSource = new G4GeneralParticleSource();
}

MuStoppedPrimaryGeneratorAction::~MuStoppedPrimaryGeneratorAction()
{
  delete fG4GeneralParticleSource;
}

void MuStoppedPrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
  // Generate primary particles using fG4GeneralParticleSource
  fG4GeneralParticleSource->GeneratePrimaryVertex(anEvent);
}

G4double MuStoppedPrimaryGeneratorAction::GetSourceParticleEnergy()
{
  return fG4GeneralParticleSource->GetParticleEnergy();
}

