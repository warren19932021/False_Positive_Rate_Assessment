#include "MySensitiveDetector.hh"
#include "G4Gamma.hh"
#include "G4UnitsTable.hh"
#include "g4root.hh"
#include "G4RunManager.hh"


MySensitiveDetector::MySensitiveDetector(G4String name): G4VSensitiveDetector(name)
//MySensitiveDetector::MySensitiveDetector(G4String name, MuStoppedEventAction * evtAction) : G4VSensitiveDetector(name),
//eventAction(evtAction)
{
     G4cout<<"This is MySensitiveDetector::MySensitiveDetector"<<G4endl;

}

MySensitiveDetector::~MySensitiveDetector()
{
     G4cout<<"This is MySensitiveDetector::~MySensitiveDetector"<<G4endl;

}

void MySensitiveDetector::SetEventAction(MuStoppedEventAction* evtAction)
{
  eventAction = evtAction;
}

G4bool MySensitiveDetector::ProcessHits(G4Step * aStep, G4TouchableHistory * ROhist)//
{

    // G4cout<<"This is MySensitiveDetector::ProcessHits"<<G4endl;

    // Get the G4RunManager instance
    G4RunManager* runManager = G4RunManager::GetRunManager();
    // Get the current event being processed
    const G4Event* event = runManager->GetCurrentEvent();

    G4Track * track =  aStep->GetTrack();

    G4StepPoint * preStepPoint = aStep->GetPreStepPoint();
    G4StepPoint * postStepPoint = aStep->GetPostStepPoint();

    // Get the volume where the hit occurred
    G4VPhysicalVolume* volume = track->GetVolume();
    G4LogicalVolume* logicalVolume = volume->GetLogicalVolume();
   
    // Get the logical volume of the hit
    G4String logicalVolumeName =  logicalVolume->GetName();

    G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();

    // Check if the track is a primary muon (adjust track ID as needed)
    if (track->GetParentID() == 0 ) {


    //if(logicalVolumeName=="logical_Scintillator1")
    //G4cout << "logicalVolumeName: " << logicalVolumeName << G4endl;

      if (preStepPoint->GetStepStatus() == fGeomBoundary) {
  
        G4double initialEnergy = track->GetVertexKineticEnergy();
        // Get the energy of the primary particle when it reaches the boundary
        G4double energyAtBoundary = track->GetKineticEnergy();
        // Calculate the energy loss due to passing through the concrete
        G4double energyLoss = initialEnergy - energyAtBoundary;
        
        // You can now do something with the energy loss value, e.g., print it
       // G4cout << "initialEnergy: " << initialEnergy << G4endl;
       // G4cout << "energyAtBoundary: " << energyAtBoundary << G4endl;
       // G4cout << "energyLoss: " << energyLoss << G4endl;
       // G4cout<<"Position: "<<postStepPoint->GetPosition()<<G4endl;
        analysisManager->FillNtupleDColumn(2, 0,energyAtBoundary);   
        analysisManager->AddNtupleRow(2);
      
        G4String PreStep_physVolumeName = preStepPoint->GetTouchableHandle()->GetVolume()->GetName();
        G4String PostStep_physVolumeName = postStepPoint->GetTouchableHandle()->GetVolume()->GetName();
        
        //G4cout<<"PreStep_physVolumeName: "<< PreStep_physVolumeName<<"; "
        //<<"PostStep_physVolumeName: "<< PostStep_physVolumeName
        //<<G4endl;

        G4int fFlag1 = 0;
        G4int fFlag2 = 0;
        G4int fFlag3 = 0;

        if(PostStep_physVolumeName=="physScintillator1")
        //muon hit Scintillator 1, does not mean (or we say, we don't know it will) pass through Scintillator 1
          {
            fFlag1 = 1;
            // TODO: Save this hit in the eventAction
            // Is there something like ActionClassHandler::GetEventAction?
             eventAction->SetScintillator1GotHit(1);
          } 
        if(PostStep_physVolumeName=="physScintillator2")
          {
            fFlag2 = 1;
            // same...
             eventAction->SetScintillator2GotHit(1);

          } 
        if(PostStep_physVolumeName=="physScintillator3")
          {
            fFlag3 = 1;
             eventAction->SetScintillator3GotHit(1);
            
          } 


        analysisManager->FillNtupleIColumn(3, 0,fFlag1);   
        analysisManager->FillNtupleIColumn(3, 1,fFlag2);   
        analysisManager->FillNtupleIColumn(3, 2,fFlag3);   
        analysisManager->AddNtupleRow(3);

      }



    }

  return true;

}



