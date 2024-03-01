#include "MuStoppedEventAction.hh"
#include "G4Event.hh"
#include "G4UnitsTable.hh"
#include "g4root.hh"

MuStoppedEventAction::MuStoppedEventAction(): G4UserEventAction()
,fScintillator1GotHit(0)
{
      
    G4cout<<"This is MuStoppedEventAction::MuStoppedEventAction"<<G4endl;
}

MuStoppedEventAction::~MuStoppedEventAction()
{
    G4cout<<"This is MuStoppedEventAction:~:MuStoppedEventAction"<<G4endl;
   

}

void MuStoppedEventAction::BeginOfEventAction(const G4Event* evt)
{
    G4cout<<"This is MuStoppedEventAction::BeginOfEventAction"<<G4endl;

  // Add code to be executed at the beginning of each event
  G4double Ekin = evt->GetPrimaryVertex()->GetPrimary()->GetKineticEnergy();
  //G4cout<<"Ekin: "<<G4BestUnit(Ekin,"Energy")<<G4endl;
  
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
  if(!analysisManager) G4cout<<"nullptr of analysisManager in BeginOfEventAction!!!!!!!!!!!!!!!"<<G4endl;
  else 
  {
    analysisManager->FillNtupleDColumn(1, 0,Ekin);   
    analysisManager->AddNtupleRow(1);
  }

}

void MuStoppedEventAction::EndOfEventAction(const G4Event*)
{
    G4cout<<"This is MuStoppedEventAction::EndOfEventAction"<<G4endl;

  // Add code to be executed at the end of each event

  // TODO: Evaluate which detectors were hit.
  G4cout<<"fScintillator1GotHit: "<<fScintillator1GotHit<<G4endl; 

}

void MuStoppedEventAction::SetScintillator1GotHit(G4int Scintillator1GotHit)
{
    G4cout<<"This is MuStoppedEventAction::SetScintillator1GotHit"<<G4endl;
    
    fScintillator1GotHit = Scintillator1GotHit;

}

void MuStoppedEventAction::SetScintillator2GotHit(G4int Scintillator2GotHit)
{
    
    fScintillator2GotHit = Scintillator2GotHit;

}

void MuStoppedEventAction::SetScintillator3GotHit(G4int Scintillator3GotHit)
{
    
    fScintillator3GotHit = Scintillator3GotHit;

}