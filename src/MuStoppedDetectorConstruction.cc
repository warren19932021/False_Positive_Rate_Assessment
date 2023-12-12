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
}

MuStoppedDetectorConstruction::~MuStoppedDetectorConstruction()
{}

G4VPhysicalVolume* MuStoppedDetectorConstruction::Construct()
{

  G4Box* solidWorld = new G4Box("SolidWorld", 4.0 * m, 4.0 * m, 4.0 * m);
  G4LogicalVolume* logicalWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");
  G4VPhysicalVolume* physWorld = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicalWorld, "physWorld", 0, false, 0, true);
  
  // Set visualization attributes
  G4VisAttributes* worldVisAttributes = new G4VisAttributes(false); // transparent
  logicalWorld->SetVisAttributes(worldVisAttributes);


  //---- Concrete------
  G4Box*  solidConcrete   =  new G4Box("solidConcrete",2.0*m,2.0*m,100.0*cm); 
  logicalConcrete = new G4LogicalVolume(solidConcrete, ConcreteMat, "logical_concrete");
  G4VPhysicalVolume* physConcrete = new G4PVPlacement(0, G4ThreeVector(0.,0.,200.*cm), logicalConcrete, "physConcrete", logicalWorld, false, 0, true);
  
  //---- Scintillator------
  G4Box*  solidScintillator  =  new G4Box("solidScintillator",2.0*m,2.0*m,80.0*cm); 
  logicalScintillator = new G4LogicalVolume(solidScintillator, ScintillatorMat, "logical_Scintillator");
  G4VPhysicalVolume* physScintillator = new G4PVPlacement(0, G4ThreeVector(0.,0.,0.*cm), logicalScintillator, "physScintillator", logicalWorld, false, 0, true);

  // Set visualization attributes
  G4VisAttributes* concreteVisAttributes = new G4VisAttributes(G4Color(0.6, 0.6, 0.6, 0.8)); // gray, opacity 0.8

  logicalConcrete->SetVisAttributes(concreteVisAttributes);


  return physWorld;
}

void MuStoppedDetectorConstruction::DefineMaterials()
{

    G4NistManager * nist = G4NistManager::Instance();
    worldMat = nist->FindOrBuildMaterial("G4_AIR");
    ConcreteMat = nist->FindOrBuildMaterial("G4_CONCRETE");
    ScintillatorMat = nist->FindOrBuildMaterial("G4_CONCRETE");
}    


void MuStoppedDetectorConstruction::ConstructSDandField()
{

    senDet = new MySensitiveDetector("SensitiveDetector");
    logicalConcrete->SetSensitiveDetector(senDet);
    logicalScintillator->SetSensitiveDetector(senDet);

}    