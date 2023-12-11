#include "MuStoppedEventAction.hh"
#include "G4Event.hh"
#include "G4UnitsTable.hh"
#include "g4root.hh"

MuStoppedEventAction::MuStoppedEventAction()
{}

MuStoppedEventAction::~MuStoppedEventAction()
{}

void MuStoppedEventAction::BeginOfEventAction(const G4Event* evt)
{
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
  // Add code to be executed at the end of each event
}

