#ifndef MUSTOPPED_DETECTOR_CONSTRUCTION_HH
#define MUSTOPPED_DETECTOR_CONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"
#include "G4Material.hh"
#include "MySensitiveDetector.hh"

class MuStoppedDetectorConstruction : public G4VUserDetectorConstruction
{
public:
  MuStoppedDetectorConstruction();
  virtual ~MuStoppedDetectorConstruction();

  virtual G4VPhysicalVolume* Construct();
  MySensitiveDetector* senDet;
private:
    G4Material * worldMat;
    G4Material * ConcreteMat;  
    void DefineMaterials();
    virtual void ConstructSDandField();
    G4LogicalVolume* logicalConcrete;
};

#endif // MUSTOPPED_DETECTOR_CONSTRUCTION_HH

