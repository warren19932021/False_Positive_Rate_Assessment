#include <stdio.h>
#include <dirent.h>
#include "TF1.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TTree.h"
#include "TRandom3.h"
#include "TCanvas.h"
using namespace std;

void readRootFile() {


        // Open the ROOT file
        TFile* file = new TFile("/home/iktp/Geant4-Work/NewStart/buildForFalse_Positive_Rate_Assessment/out.root", "READ");
        if (!file || file->IsZombie()) {
            cerr << "Error: Cannot open file " << endl;
        }

        // Get the TTree from the file
        TTree* tmptree = (TTree*)file->Get("GotHit");
        if (!tmptree) {
            cerr << "Error: Cannot find TTree 'Data' in file " << endl;
            file->Close();
        }
        else
	{
	   tmptree->Print();
	}
      

    TCanvas *canvas_momentum = new TCanvas("canvas_momentum", "Histograms", 800, 600);
    gStyle->SetOptStat(0);
    gPad->SetLogy();

    TH1F *hist_b = new TH1F("hist_b", "Histogram for momentum", 100, 0, 100);

    tmptree->Draw("fMomentum>>hist_b", "fMomentum>-10", "goff");

    hist_b->GetXaxis()->SetTitle("Momentum [GeV/c]");
    hist_b->GetYaxis()->SetTitle("Number");
    hist_b->SetLineColor(kBlack);

    hist_b->Draw("");

    // Update and draw the canvas
    canvas_momentum->Update();
    canvas_momentum->Draw();



    // Close the file
    file->Close();
}

