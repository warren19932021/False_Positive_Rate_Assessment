#ifndef MUSTOPPED_PRIMARY_GENERATOR_ACTION_HH
#define MUSTOPPED_PRIMARY_GENERATOR_ACTION_HH

#include "G4VUserPrimaryGeneratorAction.hh"
#include "EcoMug.h"
#include "G4ParticleGun.hh"



#include "globals.hh"
#include "G4ParticleDefinition.hh"


class MuStoppedPrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
public:
  MuStoppedPrimaryGeneratorAction();
  virtual ~MuStoppedPrimaryGeneratorAction();

  virtual void GeneratePrimaries(G4Event*);
  G4ParticleGun*  fParticleGun; // pointer a to G4 gun class
  G4ParticleDefinition *mu_plus, *mu_minus;
  EcoMug fMuonGen;
 
};

#endif // MUSTOPPED_PRIMARY_GENERATOR_ACTION_HH

