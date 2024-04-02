#include "MuStoppedEventAction.hh"
#include "G4Event.hh"
#include "G4UnitsTable.hh"
#include "g4root.hh"

MuStoppedEventAction::MuStoppedEventAction(): G4UserEventAction()
,fScintillator1GotHit(0)
,fScintillator2GotHit(0)
,fScintillator3GotHit(0)
,fSetScintillator3Momentum(-1)
{
      
    G4cout<<"This is MuStoppedEventAction::MuStoppedEventAction"<<G4endl;
}

MuStoppedEventAction::~MuStoppedEventAction()
{
    G4cout<<"This is MuStoppedEventAction:~:MuStoppedEventAction"<<G4endl;
   

}

void MuStoppedEventAction::BeginOfEventAction(const G4Event* evt)
{

fScintillator1GotHit=0;
fScintillator2GotHit=0;
fScintillator3GotHit=0;
fSetScintillator3Momentum=-1;

   // G4cout<<"This is MuStoppedEventAction::BeginOfEventAction"<<G4endl;

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
    //G4cout<<"This is MuStoppedEventAction::EndOfEventAction"<<G4endl;

  // Add code to be executed at the end of each event

  // TODO: Evaluate which detectors were hit.
  //G4cout<<"fScintillator1GotHit: "<<fScintillator1GotHit<<G4endl; 
  //G4cout<<"fScintillator2GotHit: "<<fScintillator2GotHit<<G4endl; 
  //G4cout<<"fScintillator3GotHit: "<<fScintillator3GotHit<<G4endl; 
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();


  analysisManager->FillNtupleIColumn(4, 0,fScintillator1GotHit);   
  analysisManager->FillNtupleIColumn(4, 1,fScintillator2GotHit);   
  analysisManager->FillNtupleIColumn(4, 2,fScintillator3GotHit);   
  analysisManager->FillNtupleDColumn(4, 3,fSetScintillator3Momentum);   
  analysisManager->AddNtupleRow(4);

}

void MuStoppedEventAction::SetScintillator1GotHit(G4int Scintillator1GotHit)
{
    //G4cout<<"This is MuStoppedEventAction::SetScintillator1GotHit"<<G4endl;
    
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

void MuStoppedEventAction::SetScintillator3Momentum(G4double SetScintillator3Momentum)
{
    
    fSetScintillator3Momentum = SetScintillator3Momentum;

}