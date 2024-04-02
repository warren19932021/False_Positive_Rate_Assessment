#include "MuStoppedRunAction.hh"
#include "g4root.hh"

MuStoppedRunAction::MuStoppedRunAction()
: OutFileName("out.root") 
{
  fMessenger = new G4GenericMessenger(this,"/run_action/","Run Action Messenger");
  fMessenger->DeclareProperty("out_file_name",OutFileName,"Output File Name");

  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
  analysisManager->SetFirstNtupleId(1);       
 
  analysisManager->CreateNtuple("MuonSourceEnergy", "Muon Source Energy");
  analysisManager->CreateNtupleDColumn("E");    //column 0
  analysisManager->FinishNtuple(1);

  analysisManager->CreateNtuple("Eboundary", "Muon Energy after escaping from the concrete surface");
  analysisManager->CreateNtupleDColumn("Eboundary");    //column 0
  analysisManager->FinishNtuple(2);

  analysisManager->CreateNtuple("Flag", "The flag to differentiate which scintillator the muon hit for a specific hit");
  //Flag1,2,3 ==> scintillator1,scintillator2,scintillator3
  analysisManager->CreateNtupleIColumn("Flag1");    //column 0; 
  analysisManager->CreateNtupleIColumn("Flag2");    //column 1; 
  analysisManager->CreateNtupleIColumn("Flag3");    //column 2; 
  analysisManager->FinishNtuple(3);

  analysisManager->CreateNtuple("GotHit", "The variable is used to differentiate scintillators the muon passed through");
  //GotHit1==> muon hit scintillator1; GotHit2==> muon hit scintillator2; GotHit3==> muon hit scintillator3;   
  analysisManager->CreateNtupleIColumn("GotHit1");    //column 0; 
  analysisManager->CreateNtupleIColumn("GotHit2");    //column 1; 
  analysisManager->CreateNtupleIColumn("GotHit3");    //column 2; 
  analysisManager->CreateNtupleDColumn("fMomentum");    //column 3; 
  analysisManager->FinishNtuple(4);


}

MuStoppedRunAction::~MuStoppedRunAction()
{
      delete G4AnalysisManager::Instance();
}

void MuStoppedRunAction::BeginOfRunAction(const G4Run*)
{
  // Add code to be executed at the beginning of each run
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
  analysisManager->OpenFile(OutFileName);

}

void MuStoppedRunAction::EndOfRunAction(const G4Run*)
{
  // Add code to be executed at the end of each run
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
  analysisManager->Write();
  analysisManager->CloseFile();
}

