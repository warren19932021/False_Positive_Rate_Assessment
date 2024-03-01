#include "MuStoppedTrackingAction.hh"

#include "G4ParticleDefinition.hh"
#include "G4Step.hh"
#include "g4root.hh"

MuStoppedTrackingAction::MuStoppedTrackingAction()
{
     G4cout<<"This is MuStoppedTrackingAction::MuStoppedTrackingAction"<<G4endl;


}

MuStoppedTrackingAction::~MuStoppedTrackingAction()
{

     G4cout<<"This is MuStoppedTrackingAction::~MuStoppedTrackingAction"<<G4endl;


}

void MuStoppedTrackingAction::PreUserTrackingAction(const G4Track*)
{
  // Add code to be executed before tracking a particle
     G4cout<<"This is MuStoppedTrackingAction::PreUserTrackingAction"<<G4endl;

}

void MuStoppedTrackingAction::PostUserTrackingAction(const G4Track* track)
{
     G4cout<<"This is MuStoppedTrackingAction::PostUserTrackingAction"<<G4endl;
}

/*
void MuStoppedTrackingAction::PostUserTrackingAction(const G4Track* track) {
    // Check if the track is a primary muon
    if (track->GetParentID() == 0) {
            // Initialize flags for checking passage through each scintillator
            G4bool passedScintillator3 = false;
            G4bool passedScintillator2 = false;

            // Get the number of steps of the track
            G4int numSteps = track->GetCurrentStepNumber();

           G4cout<<"numSteps: "<<numSteps<<G4endl;

            // Loop through each step of the track
            for (G4int i = 0; i < numSteps; ++i) {
                const G4Step* step = track->GetStep();
                G4StepPoint * preStepPoint = step->GetPreStepPoint();

               G4cout<<"i: "<<i<<"; step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetName(): "
               <<step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetName()<<G4endl;

              if (step->GetPreStepPoint()->GetStepStatus() == fGeomBoundary)
              { 
                const G4String& physVolumeName = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetName();

                // Check if the step is within physScintillator3
                if (physVolumeName == "physScintillator3" && !passedScintillator3) {
                    passedScintillator3 = true;
                }

                // If physScintillator3 is passed, then check for passage through physScintillator2 in subsequent steps
                if (passedScintillator3) {
                    // Check if the step is within physScintillator2
                    if (physVolumeName == "physScintillator2") {
                        passedScintillator2 = true;
                        // Break out of the loop once we confirm passage through physScintillator2
                        break;
                    }
                }
                
                // Move to the next step
                //track->SetTrackStatus(fStopAndKill);
                //track->SetTrackStatus(fAlive);
            }

            // Set the value of a new variable based on whether both scintillators were passed
            G4int bothPassedValue = (passedScintillator3 && passedScintillator2) ? 1 : 0;
            // Record the value in your analysis manager or use it as needed
            G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
            analysisManager->FillNtupleIColumn(4, 0, bothPassedValue);
            analysisManager->AddNtupleRow(4);
          }
        }
    }
*/