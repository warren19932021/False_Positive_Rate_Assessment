#include "MySensitiveDetector.hh"
#include "G4Gamma.hh"
#include "G4UnitsTable.hh"
#include "g4root.hh"
#include "G4RunManager.hh"


MySensitiveDetector::MySensitiveDetector(G4String name): G4VSensitiveDetector(name)
{
}

MySensitiveDetector::~MySensitiveDetector()
{

}

G4bool MySensitiveDetector::ProcessHits(G4Step * aStep, G4TouchableHistory * ROhist)//
{
    // Get the G4RunManager instance
    G4RunManager* runManager = G4RunManager::GetRunManager();
    // Get the current event being processed
    const G4Event* event = runManager->GetCurrentEvent();

    G4Track * track =  aStep->GetTrack();

    G4StepPoint * postStepPoint = aStep->GetPostStepPoint();

    G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();

    // Check if the track is a primary muon (adjust track ID as needed)
    if (track->GetParentID() == 0 ) {
      // Check if the step status is "GeomBoundary" (reached the boundary)
      if (aStep->GetPostStepPoint()->GetStepStatus() == fGeomBoundary) {
  
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
      

      }
    }

  return true;

}



