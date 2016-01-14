#include "TFile.h"
#include "TTree.h"
#include "TProfile.h"
#include "TH1F.h"
#include "TH2F.h"
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

void plotMacro(const char* filename) {
  TFile* file = new TFile(filename);
  TTree* t = (TTree*)file->Get("tree");
  
  Int_t gpn, n, npf;
  Float_t gpeta[10], gppt[10], gpphi[10];
  Float_t eta[10], et[10], phi[10];
  Float_t etapf[10], etpf[10], phipf[10];
  Float_t tkpt[10], tkptpf[10];
  Float_t deta[10], detapf[10];
  Float_t dphi[10], dphipf[10];

  t->SetBranchAddress("gpn", &gpn);
  t->SetBranchAddress("gpeta", &gpeta);
  t->SetBranchAddress("gppt", &gppt);
  t->SetBranchAddress("gpphi", &gpphi);

  t->SetBranchAddress("n", &n);
  t->SetBranchAddress("eta", &eta);
  t->SetBranchAddress("et", &et);
  t->SetBranchAddress("phi", &phi);
  t->SetBranchAddress("tkpt", &tkpt);
  t->SetBranchAddress("deta", &deta);
  t->SetBranchAddress("dphi", &dphi);

  t->SetBranchAddress("npf", &npf);
  t->SetBranchAddress("etapf", &etapf);
  t->SetBranchAddress("etpf", &etpf);
  t->SetBranchAddress("phipf", &phipf);
  t->SetBranchAddress("tkptpf", &tkptpf);
  t->SetBranchAddress("detapf", &detapf);
  t->SetBranchAddress("dphipf", &dphipf);

  Int_t entries = t->GetEntries();

  TProfile* p = new TProfile("p", "p", 50, 15, 70);
  TProfile* ppf = new TProfile("ppf", "ppf", 50, 15, 70);

  TH1F* hpt = new TH1F("hpt", "hpt", 100, 0, 100);
  TH1F* heta = new TH1F("heta", "heta", 50, -2.5, 2.5);
  TH1F* hptpf = new TH1F("hptpf", "hptpf", 100, 0, 100);
  TH1F* hetapf = new TH1F("hetapf", "hetapf", 50, -2.5, 2.5);

  TH1F* hetden = new TH1F("hetden", "hetden", 50, 0, 100);
  TH1F* hetaden = new TH1F("hetaden", "hetaden", 50, -2.5, 2.5);
  TH1F* hetnum = new TH1F("hetnum", "hetnum", 50, 0, 100);
  TH1F* hetanum = new TH1F("hetanum", "hetanum", 50, -2.5, 2.5);
  TH1F* hetnumpf = new TH1F("hetnumpf", "hetnumpf", 50, 0, 100);
  TH1F* hetanumpf = new TH1F("hetanumpf", "hetanumpf", 50, -2.5, 2.5);
  
  TH1F* drSC = new TH1F("drSC", "drSC", 100, 0.0, 0.01);
  TH1F* dESC = new TH1F("dESC", "dESC", 100, -1., 1.);
  TH2F* dEdEta = new TH2F("dEdEta", "dEdEta", 100, -1., 1., 100, -0.05, 0.05);
  TH2F* dEtadEta = new TH2F("dEtdEta", "dEtadEta", 100, -0.04, 0.04, 100, -0.05, 0.05);
  TH2F* dEdPhi = new TH2F("dEdPhi", "dEdPhi", 100, -1., 1., 100, -0.05, 0.05);
  TH1F* dPhi = new TH1F("dPhi", "dPhi", 100, -0.05, 0.05);
  TH1F* dEta = new TH1F("dEta", "dEta", 100, -0.05, 0.05);
  TH1F* dpt = new TH1F("dpt", "dpt", 100, -1., 1.);

  for (int z=0; z<entries; ++z) {
    t->GetEntry(z);

    for (int i=0; i<n; i++) { 
      hpt->Fill(et[i]);
      heta->Fill(eta[i]);
    }

    for (int i=0; i<npf; i++) { 
      hptpf->Fill(etpf[i]);
      hetapf->Fill(etapf[i]);
    }

    for (int i=0; i<gpn; ++i) {
      hetden->Fill(gppt[i]);
      hetaden->Fill(gpeta[i]);
      Int_t index = -1;
      Float_t minDr = 0.1;
      for (int j=0; j<n; j++) {
	Float_t dR = deltaR(eta[j], phi[j], gpeta[i], gpphi[i]);
	if (dR < minDr) {
	  minDr = dR;
	  index = j;
	}
      }
      
      if (index != -1) {
	Float_t theta = 2*atan(exp(-eta[index]));
	Float_t theta_mc = 2*atan(exp(-gpeta[i]));
	Float_t resolution = ((et[index]/sin(theta))/(gppt[i]/sin(theta_mc)));
	p->Fill(gppt[i], resolution);
	hetnum->Fill(gppt[i]);
	hetanum->Fill(gpeta[i]);
      }
   
      Int_t indexpf = -1;
      minDr = 0.1;
      for (int j=0; j<npf; j++) {
	Float_t dR = deltaR(etapf[j], phipf[j], gpeta[i], gpphi[i]);
	if (dR < minDr) {
	  minDr = dR;
	  indexpf = j;
	}
      }
      
      if (indexpf != -1) {
	Float_t theta = 2*atan(exp(-etapf[indexpf]));
	Float_t theta_mc = 2*atan(exp(-gpeta[i]));
	Float_t resolution = ((etpf[indexpf]/sin(theta))/(gppt[i]/sin(theta_mc)));
	ppf->Fill(gppt[i], resolution);
	hetnumpf->Fill(gppt[i]);
	hetanumpf->Fill(gpeta[i]);
      }
    
      if (indexpf != -1 && index != -1) {
	float dR = deltaR(eta[index], phi[index], etapf[indexpf], phipf[indexpf]);
	//std::cout << deltaR(eta[index], phi[index], etapf[indexpf], phipf[indexpf]) << std::endl;
	drSC->Fill(dR);
	Float_t thetapf = 2*atan(exp(-etapf[indexpf]));
	Float_t theta = 2*atan(exp(-eta[index]));
	Float_t dE = (et[index]/theta-etpf[indexpf]/thetapf)/(et[index]/theta);
	dESC->Fill(dE);
	
	//std::cout << tkpt[index] << " " << tkptpf[indexpf] << std::endl;
	//std::cout << deta[index] << " " << detapf[indexpf] << std::endl;
	if (deta[index] < 9999. && detapf[indexpf] < 9999.) {
	  dEdEta->Fill(dE, deta[index] - detapf[indexpf]);
	  dEtadEta->Fill(eta[index]-etapf[indexpf], deta[index] - detapf[indexpf]);
	  dEta->Fill(deta[index] - detapf[indexpf]);
	}


	if (dphi[index] < 9999. && dphipf[indexpf] < 9999.) {
	  dEdPhi->Fill(dE, deltaPhi(dphi[index], dphipf[indexpf]));
	  dPhi->Fill(deltaPhi(dphi[index], dphipf[indexpf]));
	}

	if (tkpt[index] < 9999. && tkptpf[indexpf] < 9999.) {
	  dpt->Fill((tkpt[index]-tkptpf[indexpf])/tkpt[index]);
	  //std::cout << (tkpt[index]-tkptpf[indexpf])/tkpt[index] << " " << tkpt[index] << " " << tkptpf[indexpf] << std::endl;
	}
      }
    }
  }

  TCanvas* c1 = new TCanvas();
  p->SetLineColor(kRed);
  p->Draw();
  ppf->SetLineColor(kBlue);
  ppf->Draw("SAME");  
  TCanvas* c2 = new TCanvas();
  dEdEta->Draw("COLZ");
  TCanvas* c3 = new TCanvas();
  dpt->Draw();
  TCanvas* c4 = new TCanvas();
  dEdPhi->Draw("COLZ");
  TCanvas* c5 = new TCanvas();
  dPhi->Draw();
  TCanvas* c6 = new TCanvas();
  dEta->Draw();
  TCanvas* c7 = new TCanvas();
  dEtadEta->Draw("COLZ");
  TCanvas* c8 = new TCanvas();
  drSC->Draw();
  TCanvas* c9 = new TCanvas();
  dESC->Draw();
  TCanvas* c10 = new TCanvas();
  hpt->SetLineColor(kRed);
  hptpf->SetLineColor(kBlue);
  hpt->Draw();
  hptpf->Draw("SAME");
  TCanvas* c11 = new TCanvas();
  heta->SetLineColor(kRed);
  hetapf->SetLineColor(kBlue);
  heta->Draw();
  hetapf->Draw("SAME");
  TCanvas* c12 = new TCanvas();
  TEfficiency* eff1 = new TEfficiency(*hetnum, *hetden);
  eff1->SetLineColor(kRed);
  TEfficiency* eff2 = new TEfficiency(*hetnumpf, *hetden);
  eff2->SetLineColor(kBlue);
  eff1->Draw();
  eff2->Draw("SAME");
  TCanvas* c13 = new TCanvas();
  TEfficiency* eff3 = new TEfficiency(*hetanum, *hetaden);
  eff3->SetLineColor(kRed);
  TEfficiency* eff4 = new TEfficiency(*hetanumpf, *hetaden);
  eff4->SetLineColor(kBlue);
  eff3->Draw();
  eff4->Draw("SAME");
  

}
