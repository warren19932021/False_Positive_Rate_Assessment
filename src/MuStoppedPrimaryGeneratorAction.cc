#include "MuStoppedPrimaryGeneratorAction.hh"
#include "G4ParticleTable.hh"
#include "Randomize.hh"


/*
double J(double p, double theta) {
  double A = 0.14*pow(p, -2.7);
  double B = 1. / (1. + 1.1*p*cos(theta)/115.);
  double C = 0.054 / (1. + 1.1*p*cos(theta)/850.);
  return A*(B+C);
}
*/

double J(double Energy, double Muon_Theta) {

    // Constants
    double alpha = 0.0025;
    double lambda = 120;
    double kappa = 2.645;
    double bp = 0.771;
    double jp = 148.16;
    double rho = 0.76;
    double y0 = 1000;
    double Bm = 1.041231831;

    // Calculate Ep1 based on your formula
    double Ep1 = (Energy + alpha * y0 * (1.0 / cos(Muon_Theta) - 0.1)) * (1.0 / rho);

    // Calculate Pm1 based on your formula
    double Pm1 = pow(0.1 * cos(Muon_Theta) * (1.0 - (alpha * (y0 * (1.0 / cos(Muon_Theta)) - 100) / (rho * Ep1))), Bm / ((rho * Ep1 + 100 * alpha) * cos(Muon_Theta)));

    // Calculate N based on your formula
    double N = alpha * Pm1 * pow(Ep1, -kappa) * lambda * bp * jp / (Ep1 * cos(Muon_Theta) + bp * jp);

    return N;
}



MuStoppedPrimaryGeneratorAction::MuStoppedPrimaryGeneratorAction()
: G4VUserPrimaryGeneratorAction(),
  fParticleGun(0), 
  mu_plus(NULL),
  mu_minus(NULL)
{
  fMuonGen.SetUseHSphere(); // half-spherical surface generation
  fMuonGen.SetHSphereRadius(4.*CLHEP::m); // half-sphere radius
  // (x,y,z) position of the center of the half-sphere
  fMuonGen.SetHSphereCenterPosition({{0., 0., 0.*CLHEP::cm}});
  fMuonGen.SetDifferentialFlux(&J);

  fParticleGun  = new G4ParticleGun(1);
  G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
   mu_minus
    = particleTable->FindParticle("mu-");
   mu_plus
    = particleTable->FindParticle("mu+");

}

MuStoppedPrimaryGeneratorAction::~MuStoppedPrimaryGeneratorAction()
{
}

void MuStoppedPrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{

  // Define and initialize the seed
  long seed = 12345; // Choose any integer value
  // Set a random seed
  G4Random::setTheSeed(seed);
  
  fMuonGen.GenerateFromCustomJ(); // generate from user-defined J
   //fMuonGen.Generate();
   std::array<double,3> muon_pos = fMuonGen.GetGenerationPosition();
   //G4ThreeVector muon_pos = fMuonGen.GetGenerationPosition();
   double muon_ptot = fMuonGen.GetGenerationMomentum(); // is in MeV or GeV?????!!
   double muon_theta = fMuonGen.GetGenerationTheta();
   double muon_phi   = fMuonGen.GetGenerationPhi();
   fParticleGun->SetParticlePosition(
     G4ThreeVector(muon_pos[0]*CLHEP::mm,muon_pos[1]*CLHEP::mm,muon_pos[2]*CLHEP::mm));
  
   G4ThreeVector myMomentum = G4ThreeVector(
                       sin(muon_theta)*cos(muon_phi)
                      ,sin(muon_theta)*sin(muon_phi)
                      ,cos(muon_theta));
  
   fParticleGun->SetParticleMomentumDirection(myMomentum);
   fParticleGun->SetParticleMomentum(muon_ptot*CLHEP::GeV);
 /*
   std::cout << "muon_pos: (" << muon_pos[0]
        << ", " << muon_pos[1] 
        << ", " << muon_pos[2] << ")";
   std::cout << " | muon_ptot: ("<< myMomentum.x() 
        << ", " << myMomentum.y() 
        << ", " << myMomentum.z() << ")" << std::endl;
   std::cout << "G4 ptot: "<< fParticleGun->GetParticleMomentum()/CLHEP::MeV << "MeV"
        << "| G4 energy: "<< fParticleGun->GetParticleEnergy()/CLHEP::MeV << "MeV"
        << "| Dir: (" << fParticleGun->GetParticleMomentumDirection().x() 
        << ", " << fParticleGun->GetParticleMomentumDirection().y() 
        << ", " << fParticleGun->GetParticleMomentumDirection().z() << ")" << std::endl;
*/
  if(fMuonGen.GetCharge()<0){ 
    fParticleGun->SetParticleDefinition(mu_minus);    
   }
   else{
    fParticleGun->SetParticleDefinition(mu_plus); 
   }
  fParticleGun->GeneratePrimaryVertex(anEvent);


}


