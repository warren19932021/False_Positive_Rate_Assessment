#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

#include "MuStoppedActionInitialization.hh"
#include "MuStoppedDetectorConstruction.hh"
#include "MySensitiveDetector.hh"
#include "QBBC.hh"


int main(int argc, char** argv)
{
  // Detect interactive mode (if no arguments) and define UI session
  G4UIExecutive* ui = nullptr;
  if (argc == 1) {
    ui = new G4UIExecutive(argc, argv);
  }



  // Construct the run manager
  G4RunManager* runManager = new G4RunManager;

  // Set mandatory initialization classes
  MuStoppedDetectorConstruction* detectorConstruction = new MuStoppedDetectorConstruction;
  runManager->SetUserInitialization(detectorConstruction);

  // Physics list
  G4VModularPhysicsList* physicsList = new QBBC;
  physicsList->SetVerboseLevel(1);
  runManager->SetUserInitialization(physicsList);
  MuStoppedActionInitialization* action = new MuStoppedActionInitialization();
  action->SetSensitiveDetector(detectorConstruction->GetSenDet());
  runManager->SetUserInitialization(action);

  // Initialize visualization
  G4VisManager* visManager = new G4VisExecutive;
  visManager->Initialize();

  // Get the pointer to the User Interface manager
  G4UImanager* UImanager = G4UImanager::GetUIpointer();

  if (!ui) {
    // Batch mode
    G4String command = "/control/execute ";
    G4String fileName = argv[1];
    UImanager->ApplyCommand(command + fileName);
  }
  else {
    // Interactive mode
    UImanager->ApplyCommand("/control/execute init_vis.mac");
    ui->SessionStart();
    delete ui;
  }

  // Job termination
  delete visManager;
  delete runManager;

  return 0;
}
