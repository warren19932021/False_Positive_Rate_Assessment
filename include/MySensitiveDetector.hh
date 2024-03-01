#ifndef DETECTOR_HH
#define DETECTOR_HH

#include "G4VSensitiveDetector.hh"
#include "MuStoppedEventAction.hh"

//class MuStoppedEventAction;

class MySensitiveDetector : public G4VSensitiveDetector
{
public:
    MySensitiveDetector(G4String);
    //MySensitiveDetector(G4String,MuStoppedEventAction * evtAction);

    ~MySensitiveDetector();
    void SetEventAction(MuStoppedEventAction* evtAction);

private:
    virtual G4bool ProcessHits(G4Step *, G4TouchableHistory *);
    MuStoppedEventAction * eventAction;

};



#endif
