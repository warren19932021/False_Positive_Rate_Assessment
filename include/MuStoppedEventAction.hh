#ifndef MUSTOPPED_EVENT_ACTION_HH
#define MUSTOPPED_EVENT_ACTION_HH

#include "G4UserEventAction.hh"
#include "globals.hh"

class MuStoppedEventAction : public G4UserEventAction
{
 public:
   MuStoppedEventAction();
   virtual ~MuStoppedEventAction();
 
   virtual void BeginOfEventAction(const G4Event*);
   virtual void EndOfEventAction(const G4Event*);
 
   void SetScintillator1GotHit(G4int Scintillator1GotHit); 
   void SetScintillator2GotHit(G4int Scintillator2GotHit); 
   void SetScintillator3GotHit(G4int Scintillator3GotHit); 
 
 private:

  G4int fScintillator1GotHit;
  G4int fScintillator2GotHit;
  G4int fScintillator3GotHit;
};

#endif // MUSTOPPED_EVENT_ACTION_HH

