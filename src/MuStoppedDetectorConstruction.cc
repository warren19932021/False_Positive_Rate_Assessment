#include "MuStoppedDetectorConstruction.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4VisAttributes.hh"
#include "G4SystemOfUnits.hh"
#include "G4NistManager.hh"
#include "MySensitiveDetector.hh"


MuStoppedDetectorConstruction::MuStoppedDetectorConstruction()
{
  DefineMaterials();
  senDet = new MySensitiveDetector("SensitiveDetector"); // I guess we can move this into the constructor
}

MuStoppedDetectorConstruction::~MuStoppedDetectorConstruction()
{}

MySensitiveDetector* MuStoppedDetectorConstruction::GetSenDet()
{
  if (!senDet) {
    G4cout << "There is no sensitive detector yet!" << G4endl;
    return 0;
  } else {
    return senDet;
  }
}

G4VPhysicalVolume* MuStoppedDetectorConstruction::Construct()
{

  G4Box* solidWorld = new G4Box("SolidWorld", 10.0 * m, 10.0 * m, 10.0 * m);
  G4LogicalVolume* logicalWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");
  G4VPhysicalVolume* physWorld = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicalWorld, "physWorld", 0, false, 0, true);
  
  // Set visualization attributes
  G4VisAttributes* worldVisAttributes = new G4VisAttributes(false); // transparent
  logicalWorld->SetVisAttributes(worldVisAttributes);


  //---- Concrete------
  //G4Box*  solidConcrete   =  new G4Box("solidConcrete",2.0*m,2.0*m,100.0*cm); 
  //logicalConcrete = new G4LogicalVolume(solidConcrete, ConcreteMat, "logical_concrete");
  //G4VPhysicalVolume* physConcrete = new G4PVPlacement(0, G4ThreeVector(0.,0.,200.*cm), logicalConcrete, "physConcrete", logicalWorld, false, 0, true);
  
  //---- Scintillator------
  G4Box*  solidScintillator  =  new G4Box("solidScintillator",0.5*m,0.5*m,3.0*cm); 
  G4Box*  solidScintillator_small  =  new G4Box("solidScintillator_small",10.*cm,10.*cm,0.75*cm); 
  
  logicalScintillator1 = new G4LogicalVolume(solidScintillator, ScintillatorMat, "logical_Scintillator1");
  G4VPhysicalVolume* physScintillator1 = new G4PVPlacement(0, G4ThreeVector(0.,0.,-3.0*cm), logicalScintillator1, "physScintillator1", logicalWorld, false, 0, true);

  logicalScintillator2 = new G4LogicalVolume(solidScintillator_small, ScintillatorMat, "logical_Scintillator2");
  G4VPhysicalVolume* physScintillator2 = new G4PVPlacement(0, G4ThreeVector(0.,0.,(22.7+0.75)*cm), logicalScintillator2, "physScintillator2", logicalWorld, false, 0, true);
  logicalScintillator3 = new G4LogicalVolume(solidScintillator_small, ScintillatorMat, "logical_Scintillator3");
  G4VPhysicalVolume* physScintillator3 = new G4PVPlacement(0, G4ThreeVector(0.,0.,(22.7+0.75+1.5+0.1)*cm), logicalScintillator3, "physScintillator3", logicalWorld, false, 0, true);

//  // Create a rotation matrix for a 90 degree rotation around the Y-axis
//  G4RotationMatrix* rotationMatrix = new G4RotationMatrix();
//  rotationMatrix->rotateY(45. * deg); // Rotate by 90 degrees
//  // Apply the rotation to the physical volume
//  physScintillator4->SetRotation(rotationMatrix);


  // Set visualization attributes
  G4VisAttributes* concreteVisAttributes = new G4VisAttributes(G4Color(0.6, 0.6, 0.6, 0.8)); // gray, opacity 0.8
  //logicalConcrete->SetVisAttributes(concreteVisAttributes);


  return physWorld;
}

void MuStoppedDetectorConstruction::DefineMaterials()
{

    G4NistManager * nist = G4NistManager::Instance();
    worldMat = nist->FindOrBuildMaterial("G4_AIR");
    ConcreteMat = nist->FindOrBuildMaterial("G4_CONCRETE");
    ScintillatorMat = nist->FindOrBuildMaterial("G4_POLYSTYRENE");
}    


void MuStoppedDetectorConstruction::ConstructSDandField()
{
  
    G4cout<<"This is Step 1 MuStoppedDetectorConstruction::ConstructSDandField"<<G4endl; 
    //logicalConcrete->SetSensitiveDetector(senDet);
    logicalScintillator1->SetSensitiveDetector(senDet);
    logicalScintillator2->SetSensitiveDetector(senDet);
    logicalScintillator3->SetSensitiveDetector(senDet);
    G4cout<<"This is Step 2 MuStoppedDetectorConstruction::ConstructSDandField"<<G4endl; 

}    