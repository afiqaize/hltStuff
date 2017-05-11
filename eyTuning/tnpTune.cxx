// Updated to use hltWP
// For the tnp hlt vs reco electron plotting
// Usage: root -l -b tnpTune.cxx++

#include "TFile.h"
#include "TChain.h"
#include "TTree.h"
#include "TROOT.h"
#include "TBufferFile.h"
#include "TLorentzVector.h"
#include "TF1.h"

#include "hltWP.cxx"
#include "/home/afiqaize/root53434/macros/tdrstyle.C"

double effCalc(int nStep, TH1D* hist) {
  double eff = 0.;
  int lim = 0;

  for (int j = nStep; j > lim; j--)
    eff += hist->GetBinContent(j);

  return eff;
}

void tnpTune() {

   gROOT->Reset();

   setTDRStyle();

   // Everything to tinker with should be here
   Double_t yMin_b = .0001, yMax_b = .9999;
   Double_t yMin_e = .0001, yMax_e = .9999;

   string varName[5], outPre, legHead;
   varName[0] = "tki";
   outPre = "hlt_";
   legHead = "";

   Bool_t drawLog = true;
   Double_t cut_b = 0.06, cut_e = 0.06;

   // -------------------------------------------------- //

   //varName[3] = "Evt / bin";
   varName[3] = "a. u.";

   if (varName[0] == "sie") {
     varName[1] = "Cluster Shape";
     varName[2] = "#sigma_{i#etai#eta}";
   }

   if (varName[0] == "hor") {
     varName[1] = "Hadronic / EM";
     varName[2] = "H/E";
   }

   if (varName[0] == "ecr") {
     varName[1] = "Relative EcalIso";
     varName[2] = "EcalIso / E_{T}";
   }

   if (varName[0] == "hcr") {
     varName[1] = "Relative HcalIso";
     varName[2] = "HcalIso / E_{T}";
   }

   if (varName[0] == "eop") {
     varName[1] = "1/E - 1/P";
     varName[2] = "1/E - 1/P (GeV^{-1})";
   }

   if (varName[0] == "mih") {
     varName[1] = "Missing Tracker Hits";
     varName[2] = "Missing Hits";
   }

   if (varName[0] == "des") {
     varName[1] = "Track - Seed Cluster #Delta#eta";
     varName[2] = "#Delta#eta_{seed}";
   }

   if (varName[0] == "det") {
     varName[1] = "Track - SC #Delta#eta";
     varName[2] = "#Delta#eta";
   }

   if (varName[0] == "dph") {
     varName[1] = "Track - SC #Delta#phi";
     varName[2] = "#Delta#phi";
   }

   if (varName[0] == "chi") {
     varName[1] = "Track Fit #chi^{2}";
     varName[2] = "Fit #chi^{2}";
   }

   if (varName[0] == "tkr") {
     varName[1] = "Relative TrkIso";
     varName[2] = "TrkIso / E_{T}";
   }

   if (varName[0] == "lol") {
     varName[1] = "Testing";
     varName[2] = "Whatever";
   }

   // -------------------------------------------------- //

   TH1::SetDefaultSumw2(true);
   //TGaxis::SetMaxDigits(3););

   TH1D* eet_1b = new TH1D("eet_1b", (varName[1] + " Distribution").c_str(), eetb_nBin, eetb_min, eetb_max);
   TH1D* eet_1e = new TH1D("eet_1e", (varName[1] + " Distribution").c_str(), eete_nBin, eete_min, eete_max);
   styleHist(eet_1b, kRed + 1, 0, 20, 1, 2.0);
   styleHist(eet_1e, kRed + 1, 0, 20, 1, 2.0);

   TH1D* sie_1b = new TH1D("sie_1b", (varName[1] + " Distribution").c_str(), sieb_nBin, sieb_min, sieb_max);
   TH1D* sie_1e = new TH1D("sie_1e", (varName[1] + " Distribution").c_str(), siee_nBin, siee_min, siee_max);
   styleHist(sie_1b, kRed + 1, 0, 20, 1, 2.0);
   styleHist(sie_1e, kRed + 1, 0, 20, 1, 2.0);

   TH1D* hor_1b = new TH1D("hor_1b", (varName[1] + " Distribution").c_str(), horb_nBin, horb_min, horb_max);
   TH1D* hor_1e = new TH1D("hor_1e", (varName[1] + " Distribution").c_str(), hore_nBin, hore_min, hore_max);
   styleHist(hor_1b, kRed + 1, 0, 20, 1, 2.0);
   styleHist(hor_1e, kRed + 1, 0, 20, 1, 2.0);

   TH1D* ecr_1b = new TH1D("ecr_1b", (varName[1] + " Distribution").c_str(), ecrb_nBin, ecrb_min, ecrb_max);
   TH1D* ecr_1e = new TH1D("ecr_1e", (varName[1] + " Distribution").c_str(), ecre_nBin, ecre_min, ecre_max);
   styleHist(ecr_1b, kRed + 1, 0, 20, 1, 2.0);
   styleHist(ecr_1e, kRed + 1, 0, 20, 1, 2.0);

   TH1D* hcr_1b = new TH1D("hcr_1b", (varName[1] + " Distribution").c_str(), hcrb_nBin, hcrb_min, hcrb_max);
   TH1D* hcr_1e = new TH1D("hcr_1e", (varName[1] + " Distribution").c_str(), hcre_nBin, hcre_min, hcre_max);
   styleHist(hcr_1b, kRed + 1, 0, 20, 1, 2.0);
   styleHist(hcr_1e, kRed + 1, 0, 20, 1, 2.0);

   TH1D* eop_1b = new TH1D("eop_1b", (varName[1] + " Distribution").c_str(), eopb_nBin, eopb_min, eopb_max);
   TH1D* eop_1e = new TH1D("eop_1e", (varName[1] + " Distribution").c_str(), eope_nBin, eope_min, eope_max);
   styleHist(eop_1b, kRed + 1, 0, 20, 1, 2.0);
   styleHist(eop_1e, kRed + 1, 0, 20, 1, 2.0);

   TH1D* chi_1b = new TH1D("chi_1b", (varName[1] + " Distribution").c_str(), chib_nBin, chib_min, chib_max);
   TH1D* chi_1e = new TH1D("chi_1e", (varName[1] + " Distribution").c_str(), chie_nBin, chie_min, chie_max);
   styleHist(chi_1b, kRed + 1, 0, 20, 1, 2.0);
   styleHist(chi_1e, kRed + 1, 0, 20, 1, 2.0);

   TH1D* mih_1b = new TH1D("mih_1b", (varName[1] + " Distribution").c_str(), mihb_nBin, mihb_min, mihb_max);
   TH1D* mih_1e = new TH1D("mih_1e", (varName[1] + " Distribution").c_str(), mihe_nBin, mihe_min, mihe_max);
   styleHist(mih_1b, kRed + 1, 0, 20, 1, 2.0);
   styleHist(mih_1e, kRed + 1, 0, 20, 1, 2.0);

   TH1D* des_1b = new TH1D("des_1b", (varName[1] + " Distribution").c_str(), desb_nBin, desb_min, desb_max);
   TH1D* des_1e = new TH1D("des_1e", (varName[1] + " Distribution").c_str(), dese_nBin, dese_min, dese_max);
   styleHist(des_1b, kRed + 1, 0, 20, 1, 2.0);
   styleHist(des_1e, kRed + 1, 0, 20, 1, 2.0);

   TH1D* dph_1b = new TH1D("dph_1b", (varName[1] + " Distribution").c_str(), dphb_nBin, dphb_min, dphb_max);
   TH1D* dph_1e = new TH1D("dph_1e", (varName[1] + " Distribution").c_str(), dphe_nBin, dphe_min, dphe_max);
   styleHist(dph_1b, kRed + 1, 0, 20, 1, 2.0);
   styleHist(dph_1e, kRed + 1, 0, 20, 1, 2.0);

   TH1D* tki_1b = new TH1D("tki_1b", (varName[1] + " Distribution").c_str(), tkib_nBin, tkib_min, tkib_max);
   TH1D* tki_1e = new TH1D("tki_1e", (varName[1] + " Distribution").c_str(), tkie_nBin, tkie_min, tkie_max);
   styleHist(tki_1b, kRed + 1, 0, 20, 1, 2.0);
   styleHist(tki_1e, kRed + 1, 0, 20, 1, 2.0);

   // -------------------------------------------------- //

   TH1D* eet_2b = new TH1D("eet_2b", (varName[1] + " Distribution").c_str(), eetb_nBin, eetb_min, eetb_max);
   TH1D* eet_2e = new TH1D("eet_2e", (varName[1] + " Distribution").c_str(), eete_nBin, eete_min, eete_max);
   styleHist(eet_2b, kAzure + 1, 1001, 2, 1, 2.0);
   styleHist(eet_2e, kAzure + 1, 1001, 2, 1, 2.0);

   TH1D* sie_2b = new TH1D("sie_2b", (varName[1] + " Distribution").c_str(), sieb_nBin, sieb_min, sieb_max);
   TH1D* sie_2e = new TH1D("sie_2e", (varName[1] + " Distribution").c_str(), siee_nBin, siee_min, siee_max);
   styleHist(sie_2b, kAzure + 1, 1001, 2, 1, 2.0);
   styleHist(sie_2e, kAzure + 1, 1001, 2, 1, 2.0);

   TH1D* hor_2b = new TH1D("hor_2b", (varName[1] + " Distribution").c_str(), horb_nBin, horb_min, horb_max);
   TH1D* hor_2e = new TH1D("hor_2e", (varName[1] + " Distribution").c_str(), hore_nBin, hore_min, hore_max);
   styleHist(hor_2b, kAzure + 1, 1001, 2, 1, 2.0);
   styleHist(hor_2e, kAzure + 1, 1001, 2, 1, 2.0);

   TH1D* ecr_2b = new TH1D("ecr_2b", (varName[1] + " Distribution").c_str(), ecrb_nBin, ecrb_min, ecrb_max);
   TH1D* ecr_2e = new TH1D("ecr_2e", (varName[1] + " Distribution").c_str(), ecre_nBin, ecre_min, ecre_max);
   styleHist(ecr_2b, kAzure + 1, 1001, 2, 1, 2.0);
   styleHist(ecr_2e, kAzure + 1, 1001, 2, 1, 2.0);

   TH1D* hcr_2b = new TH1D("hcr_2b", (varName[1] + " Distribution").c_str(), hcrb_nBin, hcrb_min, hcrb_max);
   TH1D* hcr_2e = new TH1D("hcr_2e", (varName[1] + " Distribution").c_str(), hcre_nBin, hcre_min, hcre_max);
   styleHist(hcr_2b, kAzure + 1, 1001, 2, 1, 2.0);
   styleHist(hcr_2e, kAzure + 1, 1001, 2, 1, 2.0);

   TH1D* eop_2b = new TH1D("eop_2b", (varName[1] + " Distribution").c_str(), eopb_nBin, eopb_min, eopb_max);
   TH1D* eop_2e = new TH1D("eop_2e", (varName[1] + " Distribution").c_str(), eope_nBin, eope_min, eope_max);
   styleHist(eop_2b, kAzure + 1, 1001, 2, 1, 2.0);
   styleHist(eop_2e, kAzure + 1, 1001, 2, 1, 2.0);

   TH1D* chi_2b = new TH1D("chi_2b", (varName[1] + " Distribution").c_str(), chib_nBin, chib_min, chib_max);
   TH1D* chi_2e = new TH1D("chi_2e", (varName[1] + " Distribution").c_str(), chie_nBin, chie_min, chie_max);
   styleHist(chi_2b, kAzure + 1, 1001, 2, 1, 2.0);
   styleHist(chi_2e, kAzure + 1, 1001, 2, 1, 2.0);

   TH1D* mih_2b = new TH1D("mih_2b", (varName[1] + " Distribution").c_str(), mihb_nBin, mihb_min, mihb_max);
   TH1D* mih_2e = new TH1D("mih_2e", (varName[1] + " Distribution").c_str(), mihe_nBin, mihe_min, mihe_max);
   styleHist(mih_2b, kAzure + 1, 1001, 2, 1, 2.0);
   styleHist(mih_2e, kAzure + 1, 1001, 2, 1, 2.0);

   TH1D* des_2b = new TH1D("des_2b", (varName[1] + " Distribution").c_str(), desb_nBin, desb_min, desb_max);
   TH1D* des_2e = new TH1D("des_2e", (varName[1] + " Distribution").c_str(), dese_nBin, dese_min, dese_max);
   styleHist(des_2b, kAzure + 1, 1001, 2, 1, 2.0);
   styleHist(des_2e, kAzure + 1, 1001, 2, 1, 2.0);

   TH1D* dph_2b = new TH1D("dph_2b", (varName[1] + " Distribution").c_str(), dphb_nBin, dphb_min, dphb_max);
   TH1D* dph_2e = new TH1D("dph_2e", (varName[1] + " Distribution").c_str(), dphe_nBin, dphe_min, dphe_max);
   styleHist(dph_2b, kAzure + 1, 1001, 2, 1, 2.0);
   styleHist(dph_2e, kAzure + 1, 1001, 2, 1, 2.0);

   TH1D* tki_2b = new TH1D("tki_2b", (varName[1] + " Distribution").c_str(), tkib_nBin, tkib_min, tkib_max);
   TH1D* tki_2e = new TH1D("tki_2e", (varName[1] + " Distribution").c_str(), tkie_nBin, tkie_min, tkie_max);
   styleHist(tki_2b, kAzure + 1, 1001, 2, 1, 2.0);
   styleHist(tki_2e, kAzure + 1, 1001, 2, 1, 2.0);

   // -------------------------------------------------- //

   std::string const inDir = "";

   std::pair <std::string, std::string> pairFileLeg[2];
   pairFileLeg[0] = std::make_pair("", "");
   pairFileLeg[1] = std::make_pair("", "");

   TChain *t1 = new TChain("hltTree");
   for (int iH = 0; iH < 2; iH++)
     t1->Add((inDir + pairFileLeg[iH].first + ".root").c_str());

   bool isMC = false;

   int nRun;
   t1->SetBranchAddress("nRun", &nRun);
   int nLumi;
   t1->SetBranchAddress("nLumi", &nLumi);
   int nEvt;
   t1->SetBranchAddress("nEvt", &nEvt);
   int nBX;
   t1->SetBranchAddress("nBX", &nBX);
   int nOrb;
   t1->SetBranchAddress("nOrb", &nOrb);
   int nSto;
   t1->SetBranchAddress("nSto", &nSto);

   int type;
   t1->SetBranchAddress("itype", &type);
   double weight;
   t1->SetBranchAddress("weight", &weight);
   double puWgt;
   t1->SetBranchAddress("puWgt", &puWgt);
   int nVtx;
   t1->SetBranchAddress("nVtx", &nVtx);
   double rho;
   t1->SetBranchAddress("rho", &rho);

   int pass[10];
   t1->SetBranchAddress("passHLT", pass);
   int genMatch[10];
   t1->SetBranchAddress("genMatch", genMatch);
   int n;
   t1->SetBranchAddress("hlt_n", &n);
   double et[10];
   t1->SetBranchAddress("hlt_et", et);
   double etr[10];
   t1->SetBranchAddress("hlt_etr", etr);
   double e[10];
   t1->SetBranchAddress("hlt_e", e);
   double er[10];
   t1->SetBranchAddress("hlt_er", er);
   double eta[10];
   t1->SetBranchAddress("hlt_eta", eta);
   double phi[10];
   t1->SetBranchAddress("hlt_phi", phi);
   double sie[10];
   t1->SetBranchAddress("hlt_sie", sie);
   double hoe[10];
   t1->SetBranchAddress("hlt_hoe", hoe);
   double eca[10];
   t1->SetBranchAddress("hlt_eca", eca);
   double hca[10];
   t1->SetBranchAddress("hlt_hca", hca);
   double ps2[10];
   t1->SetBranchAddress("hlt_ps2", ps2);
   double eop[10];
   t1->SetBranchAddress("hlt_eop", eop);
   double esp[10];
   t1->SetBranchAddress("hlt_esp", esp);
   double chi[10];
   t1->SetBranchAddress("hlt_chi", chi);
   double mih[10];
   t1->SetBranchAddress("hlt_mih", mih);
   double det[10];
   t1->SetBranchAddress("hlt_det", det);
   double des[10];
   t1->SetBranchAddress("hlt_des", des);
   double dph[10];
   t1->SetBranchAddress("hlt_dph", dph);
   double tks[10];
   t1->SetBranchAddress("hlt_tks", tks);

   int mc_nBX, mc_nPUtrue, gp_n;
   int mc_BX[100], mc_nPUobs[100];
   double genWgt, gp_pt[10], gp_eta[10], gp_phi[10];

    if (isMC) {
      t1->SetBranchAddress("genWgt", &genWgt);
      t1->SetBranchAddress("gp_n", &gp_n);
      t1->SetBranchAddress("gp_pt", gp_pt);
      t1->SetBranchAddress("gp_eta", gp_eta);
      t1->SetBranchAddress("gpphi", gp_phi);
      t1->SetBranchAddress("mc_nBX", &mc_nBX);
      t1->SetBranchAddress("mc_BX", mc_BX);
      t1->SetBranchAddress("mc_nPUtrue", &mc_nPUtrue);
      t1->SetBranchAddress("mc_nPUobs", mc_nPUobs);
    }

   // -------------------------------------------------- //

   TLorentzVector p4Tag, p4Probe;
   Float_t finWgt = 1.;

   int nEvt1 = t1->GetEntries();
   cout << "nEvt1 = " << nEvt1 << endl;

   for (int evt1 = 0; evt1 < nEvt1; evt1++) {

     t1->GetEntry(evt1);
     finWgt = puWgt * weight;

     // Loop for QCD-like things considering all cands
     if (type == -2) {

       for (int iCand = 0; iCand < n; iCand++) {

         if (et[iCand] < 20. or std::abs(eta[iCand] > 2.5)) continue;

         if (!checkCand("", -1, rho,
                        e[iCand], et[iCand], eta[iCand], phi[iCand],
                        sie[iCand], hoe[iCand], eca[iCand], hca[iCand], eop[iCand],
                        chi[iCand], mih[iCand], des[iCand], dph[iCand], tks[iCand])) continue;

         if (std::abs(eta[iCand]) < etaEB) {
           sie_1b->Fill(sie[iCand], finWgt);
           hor_1b->Fill(hoe[iCand], finWgt);
           ecr_1b->Fill(ecr[iCand], finWgt);
           hcr_1b->Fill(hcr[iCand], finWgt);
           eop_1b->Fill(eop[iCand], finWgt);
           chi_1b->Fill(chi[iCand], finWgt);
           mih_1b->Fill(mih[iCand], finWgt);
           des_1b->Fill(des[iCand], finWgt);
           dph_1b->Fill(dph[iCand], finWgt);
           tkr_1b->Fill(tkr[iCand], finWgt);
         }

         if (std::abs(eta[iCand]) >= etaET) {
           sie_1e->Fill(sie[iCand], finWgt);
           hor_1e->Fill(hoe[iCand], finWgt);
           ecr_1e->Fill(ecr[iCand], finWgt);
           hcr_1e->Fill(hcr[iCand], finWgt);
           eop_1e->Fill(eop[iCand], finWgt);
           chi_1e->Fill(chi[iCand], finWgt);
           mih_1e->Fill(mih[iCand], finWgt);
           des_1e->Fill(des[iCand], finWgt);
           dph_1e->Fill(dph[iCand], finWgt);
           tkr_1e->Fill(tkr[iCand], finWgt);
         }
       }
     }

     // Loop TnP-style so that the object is likely an electron
     if (type == -1) {

       for (int iTag = 0; iTag < n; iTag++) {

         if (pass[iTag] != 1) continue;
         if (isMC and genMatch[iTag] != 1) continue;
         if ((et[iTag] < 25.) or (eta[iTag] > 2.5)) continue;

         p4Tag.SetPtEtaPhiE(et[iTag], eta[iTag], phi[iTag], e[iTag]);

         for (int iProbe = 0; iProbe < n; iProbe++) {

           if (iProbe == iTag) continue;
           if (isMC and genMatch[iProbe] != 1) continue;
           if (et[iProbe] < 20. or std::abs(eta[iProbe] > 2.5)) continue;

           p4Probe.SetPtEtaPhiE(et[iProbe], eta[iProbe], phi[iProbe], e[iProbe]);

           if ((p4Tag + p4Probe).M() < 70. or (p4Tag + p4Probe).M() > 110.) continue;

           if (!checkCand("", -1, rho,
                          e[iProbe], et[iProbe], eta[iProbe], phi[iProbe],
                          sie[iProbe], hoe[iProbe], eca[iProbe], hca[iProbe], eop[iProbe],
                          chi[iProbe], mih[iProbe], des[iProbe], dph[iProbe], tks[iProbe])) continue;

           if (std::abs(eta[iProbe]) < etaEB) {
             sie_2b->Fill(sie[iProbe], finWgt);
             hor_2b->Fill(hoe[iProbe], finWgt);
             ecr_2b->Fill(ecr[iProbe], finWgt);
             hcr_2b->Fill(hcr[iProbe], finWgt);
             eop_2b->Fill(eop[iProbe], finWgt);
             chi_2b->Fill(chi[iProbe], finWgt);
             mih_2b->Fill(mih[iProbe], finWgt);
             des_2b->Fill(des[iProbe], finWgt);
             dph_2b->Fill(dph[iProbe], finWgt);
             tkr_2b->Fill(tkr[iProbe], finWgt);
           }

           if (std::abs(eta[iProbe]) >= etaET) {
             sie_2e->Fill(sie[iProbe], finWgt);
             hor_2e->Fill(hoe[iProbe], finWgt);
             ecr_2e->Fill(ecr[iProbe], finWgt);
             hcr_2e->Fill(hcr[iProbe], finWgt);
             eop_2e->Fill(eop[iProbe], finWgt);
             chi_2e->Fill(chi[iProbe], finWgt);
             mih_2e->Fill(mih[iProbe], finWgt);
             des_2e->Fill(des[iProbe], finWgt);
             dph_2e->Fill(dph[iProbe], finWgt);
             tkr_2e->Fill(tkr[iProbe], finWgt);
           }
         }
       }
     }
   }

   // -------------------------------------------------- //

   //cout << tkr_1b->GetEntries() << " " << tkr_2b->GetEntries() << endl;
   //cout << tkr_1e->GetEntries() << " " << tkr_2e->GetEntries() << endl;

   tkr_1b->Scale( 1. / tkr_1b->Integral()); tkr_1e->Scale( 1. / tkr_1e->Integral());
   tkr_2b->Scale( 1. / tkr_2b->Integral()); tkr_2e->Scale( 1. / tkr_2e->Integral());

   static const int nStep_b = tkrb_nBin + 1, nStep_e = tkre_nBin + 1;
   double sStep_b = (tkrb_max - tkrb_min) / tkrb_nBin, sStep_e = (tkre_max - tkre_min) / tkre_nBin;

   // Array size must be the same as bin + 1
   double eff_xb[nStep_b], eff_y1b[nStep_b], eff_y2b[nStep_b];
   double eff_xe[nStep_e], eff_y1e[nStep_e], eff_y2e[nStep_e];
   double std_xb[nStep_b], std_xe[nStep_e], std_yb[nStep_b], std_ye[nStep_e];
   double sig_b = 0., bkg_b = 0., sig_e = 0., bkg_e = 0.;

   //std::cout << "Barrel" << "\n" << "Cut" << "\t" << "Eff bkg" << "\t" << "Eff sig" << std::endl;

   for (int p = 0; p < nStep_b; p++) {

     eff_xb[p] = (p * sStep_b) + tkrb_min;
     eff_y1b[p] = effCalc(p, tkr_1b);
     eff_y2b[p] = effCalc(p, tkr_2b);

     if (std::abs(eff_xb[p] - cut_b) < sStep_b / 2.) {
       sig_b = eff_y2b[p];
       bkg_b = eff_y1b[p];
     }

     std_xb[p] = cut_b;
     if (p == 0) std_yb[p] = 10.;
     else if (p == nStep_b - 1) std_yb[p] = 0.;
     else std_yb[p] = (1. - ((double) (p + 1) / (double) nStep_b));

     //if (eff_y2b[p] <= 1.)
     //  std::cout << std::setprecision(4) << std::fixed << eff_xb[p] << "\t" << std::setprecision(3) << eff_y1b[p] * 100. << "\t" << eff_y2b[p] * 100. << std::endl;

   }

   //std::cout << "\n" << "Endcap" << "\n" << "Cut" << "\t" << "Eff bkg" << "\t" << "Eff sig" << std::endl;

   for (int q = 0; q < nStep_e; q++) {

     eff_xe[q] = (q * sStep_e) + tkre_min;
     eff_y1e[q] = effCalc(q, tkr_1e);
     eff_y2e[q] = effCalc(q, tkr_2e);

     if (std::abs(eff_xe[q] - cut_e) < sStep_e / 2.) {
       sig_e = eff_y2e[q];
       bkg_e = eff_y1e[q];
     }

     std_xe[q] = cut_e;
     if (q == 0) std_ye[q] = 10.;
     else if (q == nStep_e - 1) std_ye[q] = 0.;
     else std_ye[q] = (1. - ((double) (q + 1)  / (double) nStep_e));

     //if (eff_y2e[q] <= 1.)
     //  std::cout << std::setprecision(4) << std::fixed <<  eff_xe[q] << "\t" << std::setprecision(3) << eff_y1e[q] * 100. << "\t" << eff_y2e[q] * 100. << std::endl;

   }

   //std::cout << std::endl;

   // -------------------------------------------------- //;

   TGraph* eff_1b = new TGraph(nStep_b, eff_xb, eff_y1b);
   TGraph* eff_1e = new TGraph(nStep_e, eff_xe, eff_y1e);
   styleGr(eff_1b, kRed + 1, 0, 0, 0, 3.0);
   styleGr(eff_1e, kRed + 1, 0, 0, 0, 3.0);

   TGraph* eff_2b = new TGraph(nStep_b, eff_xb, eff_y2b);
   eff_2b->SetTitle((varName[1] + " EB Efficiency").c_str());
   styleGr(eff_2b, kAzure + 1, 0, 0, 0, 3.0);
   axGr(eff_2b, 0., 1.049, "Efficiency", 0.027, 0.95, 0.025, varName[2], 0.027, 1.15, 0.025);
   eff_2b->GetXaxis()->SetLimits(tkrb_min, tkrb_max);

   TGraph* eff_2e = new TGraph(nStep_e, eff_xe, eff_y2e);
   eff_2e->SetTitle((varName[1] + " EE Efficiency").c_str());
   styleGr(eff_2e, kAzure + 1, 0, 0, 0, 3.0);
   axGr(eff_2e, 0., 1.049, "Efficiency", 0.027, 0.95, 0.025, varName[2], 0.027, 1.15, 0.025);
   eff_2e->GetXaxis()->SetLimits(tkre_min, tkre_max);

   TGraph* stdb = new TGraph(nStep_b, std_xb, std_yb);
   stdb->SetLineColor(kBlack);
   stdb->SetLineWidth(3);

   TGraph* stde = new TGraph(nStep_e, std_xe, std_ye);
   stde->SetLineColor(kBlack);
   stde->SetLineWidth(3);

   TGraph* pntWPb = new TGraph();
   pntWPb->SetPoint(0, bkg_b, sig_b);
   pntWPb->SetMarkerStyle(29);
   pntWPb->SetMarkerSize(3);
   pntWPb->SetMarkerColor(kAzure - 1);

   TGraph* pntWPe = new TGraph();
   pntWPe->SetPoint(0, bkg_e, sig_e);
   pntWPe->SetMarkerStyle(29);
   pntWPe->SetMarkerSize(3);
   pntWPe->SetMarkerColor(kAzure - 1);

   TGraph* rocb = new TGraph(nStep_b, eff_y1b, eff_y2b);
   rocb->SetTitle((varName[1] + " EB Efficiency").c_str());
   styleGr(rocb, kRed, 0, 0, 0, 3.0);
   axGr(rocb, 0., 1.099, (sigLeg + " Efficiency").c_str(), 0.027, 1.05, 0.025, (bkgLeg + " Efficiency").c_str(), 0.027, 1.15, 0.025);
   rocb->GetXaxis()->SetLimits(0., 1.);

   TGraph* roce = new TGraph(nStep_b, eff_y1e, eff_y2e);
   roce->SetTitle((varName[1] + " EE Efficiency").c_str());
   styleGr(roce, kRed, 0, 0, 0, 3.0);
   axGr(roce, 0., 1.099, (sigLeg + " Efficiency").c_str(), 0.027, 1.05, 0.025, (bkgLeg + " Efficiency").c_str(), 0.027, 1.15, 0.025);
   roce->GetXaxis()->SetLimits(0., 1.);

   // -------------------------------------------------- //

   if (drawLog) {
     yMin_b = yMin_b / 5.;
     yMin_e = yMin_e / 5.;
   }

   axHist(tkr_2b, yMin_b, yMax_b, varName[3], 0.027, 1.05, 0.025, varName[2], 0.027, 1.15, 0.025);
   axHist(tkr_2e, yMin_e, yMax_e, varName[3], 0.027, 1.05, 0.025, varName[2], 0.027, 1.15, 0.025);

   TLatex txt;
   txt.SetTextSize(0.035);
   txt.SetTextAlign(13);
   std::string topLeft, topRight;
   topLeft = "#bf{CMS} #it{Simulation Preliminary}";
   topRight = "(13 TeV)";

   TLegend *leg01 = new TLegend(.69, .67, .87, .85);
   leg01->SetHeader((legHead + "#left|#eta^{e}#right| < 1.444").c_str());
   leg01->AddEntry(tkr_2b, (sigLeg).c_str(), "l");
   leg01->AddEntry(tkr_1b, (bkgLeg).c_str(), "l");
   leg01->SetFillColor(0);
   leg01->SetBorderSize(0);
   leg01->SetTextSize(0.03);
   leg01->SetTextFont(42);

   TLegend *leg02 = new TLegend(.69, .67, .87, .85);
   leg02->SetHeader((legHead + "1.566 < #left|#eta^{e}#right| < 2.5").c_str());
   leg02->AddEntry(tkr_2e, (sigLeg).c_str(), "l");
   leg02->AddEntry(tkr_1e, (bkgLeg).c_str(), "l");
   leg02->SetFillColor(0);
   leg02->SetBorderSize(0);
   leg02->SetTextSize(0.03);
   leg02->SetTextFont(42);

   // -------------------------------------------------- //

   std::string const outDir = inDir + "/opt_v0/plot/";

   TCanvas *cv1 = new TCanvas("cv1", "cv1", 200, 10, 1000, 1000);
   TCanvas *cv2 = new TCanvas("cv2", "cv2", 200, 10, 1000, 1000);
   TCanvas *ce1 = new TCanvas("ce1", "ce1", 200, 10, 1000, 1000);
   TCanvas *ce2 = new TCanvas("ce2", "ce2", 200, 10, 1000, 1000);
   TCanvas *cr1 = new TCanvas("cr1", "cr1", 200, 10, 1000, 1000);
   TCanvas *cr2 = new TCanvas("cr2", "cr2", 200, 10, 1000, 1000);

   cv1->cd();

   if (drawLog) cv1->SetLogy();
   tkr_2b->Draw("hist");
   tkr_1b->Draw("histsame");
   stdb->Draw("same");

   leg01->Draw();
   //txt.DrawLatexNDC(0.06, 0.928, topLeft.c_str());
   //txt.DrawLatexNDC(0.763, 0.933, topRight.c_str());
   //txt.DrawLatexNDC(0.06, 0.935, topLeft.c_str());
   //txt.DrawLatexNDC(0.728, 0.940, topRight.c_str());
   cv1->SaveAs((outDir + outPre + varName[0] + "_var_eb.pdf").c_str());

   cv2->cd();

   if (drawLog) cv2->SetLogy();
   tkr_2e->Draw("hist");
   tkr_1e->Draw("histsame");
   stde->Draw("same");

   leg02->Draw();
   //txt.DrawLatexNDC(0.06, 0.928, topLeft.c_str());
   //txt.DrawLatexNDC(0.763, 0.933, topRight.c_str());
   //txt.DrawLatexNDC(0.06, 0.935, topLeft.c_str());
   //txt.DrawLatexNDC(0.728, 0.940, topRight.c_str());
   cv2->SaveAs((outDir + outPre + varName[0] + "_var_ee.pdf").c_str());

   ce1->cd();
   ce1->SetGrid();
   eff_2b->Draw("AL");
   eff_1b->Draw("same");
   stdb->Draw("same");
   //txt.DrawLatexNDC(0.06, 0.928, topLeft.c_str());
   //txt.DrawLatexNDC(0.763, 0.933, topRight.c_str());
   //txt.DrawLatexNDC(0.06, 0.935, topLeft.c_str());
   //txt.DrawLatexNDC(0.728, 0.940, topRight.c_str());
   ce1->SaveAs((outDir + outPre + varName[0] + "_eff_eb.pdf").c_str());

   ce2->cd();
   ce2->SetGrid();
   eff_2e->Draw("AL");
   eff_1e->Draw("same");
   stde->Draw("same");
   //txt.DrawLatexNDC(0.06, 0.928, topLeft.c_str());
   //txt.DrawLatexNDC(0.763, 0.933, topRight.c_str());
   //txt.DrawLatexNDC(0.06, 0.935, topLeft.c_str());
   //txt.DrawLatexNDC(0.728, 0.940, topRight.c_str());
   ce2->SaveAs((outDir + outPre + varName[0] + "_eff_ee.pdf").c_str());

   cr1->cd();
   cr1->SetGrid();
   rocb->Draw("AL");
   pntWPb->Draw("psame");
   //txt.DrawLatexNDC(0.06, 0.928, topLeft.c_str());
   //txt.DrawLatexNDC(0.763, 0.933, topRight.c_str());
   //txt.DrawLatexNDC(0.06, 0.935, topLeft.c_str());
   //txt.DrawLatexNDC(0.728, 0.940, topRight.c_str());
   //cr1->SaveAs((outDir + outPre + varName[0] + "_roc_eb.pdf").c_str());

   cr2->cd();
   cr2->SetGrid();
   roce->Draw("AL");
   pntWPe->Draw("psame");
   //txt.DrawLatexNDC(0.06, 0.928, topLeft.c_str());
   //txt.DrawLatexNDC(0.763, 0.933, topRight.c_str());
   //txt.DrawLatexNDC(0.06, 0.935, topLeft.c_str());
   //txt.DrawLatexNDC(0.728, 0.940, topRight.c_str());
   //cr2->SaveAs((outDir + outPre + varName[0] + "_roc_ee.pdf").c_str());

   // -------------------------------------------------- //

   cv1->Close(); cv2->Close();
   ce1->Close(); ce2->Close();
   cr1->Close(); cr2->Close();
   gROOT->ProcessLine(".q");
   
}

int main() {
  tnpTune();
  return 0;
}



