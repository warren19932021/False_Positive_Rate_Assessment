#ifndef MUSTOPPED_PRIMARY_GENERATOR_ACTION_HH
#define MUSTOPPED_PRIMARY_GENERATOR_ACTION_HH

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4GeneralParticleSource.hh"

class MuStoppedPrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
public:
  MuStoppedPrimaryGeneratorAction();
  virtual ~MuStoppedPrimaryGeneratorAction();

  virtual void GeneratePrimaries(G4Event*);
  G4double GetSourceParticleEnergy();

private:
  G4GeneralParticleSource* fG4GeneralParticleSource;
};

#endif // MUSTOPPED_PRIMARY_GENERATOR_ACTION_HH

