#include "TFile.h"
#include "TTree.h"
#include "TProfile.h"
#include "TF1.h"
#include "TH1F.h"
#include "TMath.h"
#include "TCanvas.h"
#include "TEfficiency.h"

#include <iostream>

float deltaPhi(Float_t p1, Float_t p2) {

  float dp = p1-p2; 
  if (dp > float(TMath::Pi())) 
    dp-=(2*float(TMath::Pi()));  
  return dp;
}

float deltaR(Float_t e1, Float_t p1, Float_t e2, Float_t p2) {

  float dp = fabs(p1-p2); 
  if (dp > float(TMath::Pi())) 
    dp-=(2*float(TMath::Pi()));  
  return (e1-e2)*(e1-e2) + dp*dp;
}

void lcCheck(const char* filename) {
  TFile* file = new TFile(filename);
  TTree* t = (TTree*)file->Get("tree");
  
  Int_t n, recon;
  Float_t recoeta[10], recoet[10], recophi[10];
  Float_t eta[10], et[10], phi[10];

  t->SetBranchAddress("recon", &recon);
  t->SetBranchAddress("recoeta", &recoeta);
  t->SetBranchAddress("recopt", &recoet);
  t->SetBranchAddress("recophi", &recophi);

  t->SetBranchAddress("n", &n);
  t->SetBranchAddress("eta", &eta);
  t->SetBranchAddress("et", &et);
  t->SetBranchAddress("phi", &phi);

  Int_t entries = t->GetEntries();

  TH1F* het_b = new TH1F("het_b", "het_b", 100, 0, 100);
  TH1F* hethlt_b = new TH1F("hethlt_b", "hethlt_b", 100, 0, 100);
  TH1F* het_e = new TH1F("het_e", "het_e", 100, 0, 100);
  TH1F* hethlt_e = new TH1F("hethlt_e", "hethlt_e", 100, 0, 100);

  TH1F* hde_b = new TH1F("hde_b", "hde_b", 100, -.15, .15);
  TH1F* hde_e = new TH1F("hde_e", "hde_e", 100, -.15, .15);

  for (int z=0; z<entries; ++z) {
    t->GetEntry(z);

    for (int i=0; i<recon; ++i) {
      Int_t index = -1;
      Float_t minDr = 0.1;
      for (int j=0; j<n; j++) {
	//if (et[j]<0.)
	//    continue;
	Float_t dR = deltaR(eta[j], phi[j], recoeta[i], recophi[i]);
	if (dR < minDr) {
	  minDr = dR;
	  index = j;
	}
      }
	
      if (index != -1) {
	if (fabs(recoeta[i])<1.479) {
	  het_b->Fill(recoet[i]);
	  hethlt_b->Fill(et[index]);
	  hde_b->Fill((-recoet[i]+et[index])/recoet[i]);
	} else {
	  het_e->Fill(recoet[i]);
	  hethlt_e->Fill(et[index]);
	  hde_e->Fill((-recoet[i]+et[index])/recoet[i]);
	} 
      }
    }
  }

  TCanvas* c1 = new TCanvas();
  c1->Divide(2,1);
  c1->cd(1);
  het_b->SetFillColor(kRed);
  het_b->Draw("HIST");
  hethlt_b->SetMarkerStyle(20);
  hethlt_b->Draw("PESAME");
  c1->cd(2);
  het_e->SetFillColor(kRed);
  het_e->Draw("HIST");
  hethlt_e->SetMarkerStyle(20);
  hethlt_e->Draw("PESAME");
  
  TF1* f1 = new TF1("f1", "gaus", -0.07, 0.07);
  TCanvas* c2 = new TCanvas();
  c2->Divide(2,1);
  c2->cd(1);
  hde_b->Draw();
  hde_b->Fit("f1", "R");
  c2->cd(2);
  hde_e->Draw();
  hde_e->Fit("f1", "R");
}
