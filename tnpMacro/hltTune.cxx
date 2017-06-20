// Special class of tnpOn comparing a sig and a bkg
// Usage: root -l -b hltTune.cxx++

#include "TFile.h"
#include "TChain.h"
#include "TTree.h"
#include "TROOT.h"
#include "TBufferFile.h"
#include "TLorentzVector.h"
#include "TF1.h"

#include "hltWP.cxx"
#include "plotStuff.cxx"
#include "/home/afiqaize/root53434/macros/tdrstyle.C"

void hltTune() {
   gROOT->Reset();

   setTDRStyle();

   // Everything to tinker with should be here
   std::string outPre = "";

   // -------------------------------------------------- //

   const int nH = 2;

   std::string const inDir = "/home/afiqaize/Downloads/EGM/dev/e_90x/wpTune_110517/skim_v1/";
   std::string const fName = inDir + "../plot_v1/varTune_2/";

   std::pair <std::string, std::string> pairFileLeg[nH];
   pairFileLeg[0] = std::make_pair("skim_dy", "DY");
   pairFileLeg[1] = std::make_pair("skim_qcd_in", "QCD");

   TH1::SetDefaultSumw2(true);
   TH1 *eta_b[nH], *eta_e[nH], *phi_b[nH], *phi_e[nH], *eet_b[nH], *eet_e[nH];
   TH1 *sie_b[nH], *sie_e[nH], *hor_b[nH], *hor_e[nH];
   TH1 *ecr_b[nH], *ecr_e[nH], *hcr_b[nH], *hcr_e[nH];
   TH1 *ps2_b[nH], *ps2_e[nH];
   TH1 *eop_b[nH], *eop_e[nH], *esp_b[nH], *esp_e[nH], *chi_b[nH], *chi_e[nH], *mih_b[nH], *mih_e[nH];
   TH1 *des_b[nH], *des_e[nH], *det_b[nH], *det_e[nH], *dph_b[nH], *dph_e[nH], *tkr_b[nH], *tkr_e[nH];
   TH1 *lol_b[nH], *lol_e[nH];

   TH1 *hor0_b[nH], *hor0_e[nH], *ecr0_b[nH], *ecr0_e[nH];
   TH1 *hcr0_b[nH], *hcr0_e[nH], *tkr0_b[nH], *tkr0_e[nH];
   TH1 *hor1_b[nH], *hor1_e[nH], *ecr1_b[nH], *ecr1_e[nH];
   TH1 *hcr1_b[nH], *hcr1_e[nH], *tkr1_b[nH], *tkr1_e[nH];
   TH1 *hor2_b[nH], *hor2_e[nH], *ecr2_b[nH], *ecr2_e[nH];
   TH1 *hcr2_b[nH], *hcr2_e[nH], *tkr2_b[nH], *tkr2_e[nH];
   TH1 *hor3_b[nH], *hor3_e[nH], *ecr3_b[nH], *ecr3_e[nH];
   TH1 *hcr3_b[nH], *hcr3_e[nH], *tkr3_b[nH], *tkr3_e[nH];

   int kCols[nH] = {kAzure + 1, kRed + 1};
   int kColor, kFill, kMark;
   for (int iH = 0; iH < nH; iH++) {
     kColor = kCols[iH];
     kFill = 1001 * abs(iH - 1); kMark = 20 + iH;

     eta_b[iH] = new TH1D(("eta_b_" + toStr(iH)).c_str(), "#eta Distribution", mBin.at("eta").nBin_eb, mBin.at("eta").min_eb, mBin.at("eta").max_eb);
     eta_e[iH] = new TH1D(("eta_e_" + toStr(iH)).c_str(), "#eta Distribution", mBin.at("eta").nBin_ee, mBin.at("eta").min_ee, mBin.at("eta").max_ee);
     styleHist(eta_b[iH], kColor, kFill, kMark, 1, 1.5);
     styleHist(eta_e[iH], kColor, kFill, kMark, 1, 1.5);

     phi_b[iH] = new TH1D(("phi_b_" + toStr(iH)).c_str(), "#phi Distribution", mBin.at("phi").nBin_eb, mBin.at("phi").min_eb, mBin.at("phi").max_eb);
     phi_e[iH] = new TH1D(("phi_e_" + toStr(iH)).c_str(), "#phi Distribution", mBin.at("phi").nBin_ee, mBin.at("phi").min_ee, mBin.at("phi").max_ee);
     styleHist(phi_b[iH], kColor, kFill, kMark, 1, 1.5);
     styleHist(phi_e[iH], kColor, kFill, kMark, 1, 1.5);

     eet_b[iH] = new TH1D(("eet_b_" + toStr(iH)).c_str(), "E_{T} Distribution", mBin.at("eet").nBin_eb, mBin.at("eet").min_eb, mBin.at("eet").max_eb);
     eet_e[iH] = new TH1D(("eet_e_" + toStr(iH)).c_str(), "E_{T} Distribution", mBin.at("eet").nBin_ee, mBin.at("eet").min_ee, mBin.at("eet").max_ee);
     styleHist(eet_b[iH], kColor, kFill, kMark, 1, 1.5);
     styleHist(eet_e[iH], kColor, kFill, kMark, 1, 1.5);

     sie_b[iH] = new TH1D(("sie_b_" + toStr(iH)).c_str(), "Cluster Shape Distribution", mBin.at("sie").nBin_eb, mBin.at("sie").min_eb, mBin.at("sie").max_eb);
     sie_e[iH] = new TH1D(("sie_e_" + toStr(iH)).c_str(), "Cluster Shape Distribution", mBin.at("sie").nBin_ee, mBin.at("sie").min_ee, mBin.at("sie").max_ee);
     styleHist(sie_b[iH], kColor, kFill, kMark, 1, 1.5);
     styleHist(sie_e[iH], kColor, kFill, kMark, 1, 1.5);

     hor_b[iH] = new TH1D(("hor_b_" + toStr(iH)).c_str(), "Hadronic / EM Distribution", mBin.at("hor").nBin_eb, mBin.at("hor").min_eb, mBin.at("hor").max_eb);
     hor_e[iH] = new TH1D(("hor_e_" + toStr(iH)).c_str(), "Hadronic / EM Distribution", mBin.at("hor").nBin_ee, mBin.at("hor").min_ee, mBin.at("hor").max_ee);
     styleHist(hor_b[iH], kColor, kFill, kMark, 1, 1.5);
     styleHist(hor_e[iH], kColor, kFill, kMark, 1, 1.5);

     ecr_b[iH] = new TH1D(("ecr_b_" + toStr(iH)).c_str(), "Rel. EcalIso Distribution", mBin.at("ecr").nBin_eb, mBin.at("ecr").min_eb, mBin.at("ecr").max_eb);
     ecr_e[iH] = new TH1D(("ecr_e_" + toStr(iH)).c_str(), "Rel. EcalIso Distribution", mBin.at("ecr").nBin_ee, mBin.at("ecr").min_ee, mBin.at("ecr").max_ee);
     styleHist(ecr_b[iH], kColor, kFill, kMark, 1, 1.5);
     styleHist(ecr_e[iH], kColor, kFill, kMark, 1, 1.5);

     hcr_b[iH] = new TH1D(("hcr_b_" + toStr(iH)).c_str(), "Rel. HcalIso Distribution", mBin.at("hcr").nBin_eb, mBin.at("hcr").min_eb, mBin.at("hcr").max_eb);
     hcr_e[iH] = new TH1D(("hcr_e_" + toStr(iH)).c_str(), "Rel. HcalIso Distribution", mBin.at("hcr").nBin_ee, mBin.at("hcr").min_ee, mBin.at("hcr").max_ee);
     styleHist(hcr_b[iH], kColor, kFill, kMark, 1, 1.5);
     styleHist(hcr_e[iH], kColor, kFill, kMark, 1, 1.5);

     ps2_b[iH] = new TH1D(("ps2_b_" + toStr(iH)).c_str(), "PM s^{2} Distribution", mBin.at("ps2").nBin_eb, mBin.at("ps2").min_eb, mBin.at("ps2").max_eb);
     ps2_e[iH] = new TH1D(("ps2_e_" + toStr(iH)).c_str(), "PM s^{2} Distribution", mBin.at("ps2").nBin_ee, mBin.at("ps2").min_ee, mBin.at("ps2").max_ee);
     styleHist(ps2_b[iH], kColor, kFill, kMark, 1, 1.5);
     styleHist(ps2_e[iH], kColor, kFill, kMark, 1, 1.5);

     eop_b[iH] = new TH1D(("eop_b_" + toStr(iH)).c_str(), "SC 1/E - 1/P Distribution", mBin.at("eop").nBin_eb, mBin.at("eop").min_eb, mBin.at("eop").max_eb);
     eop_e[iH] = new TH1D(("eop_e_" + toStr(iH)).c_str(), "SC 1/E - 1/P Distribution", mBin.at("eop").nBin_ee, mBin.at("eop").min_ee, mBin.at("eop").max_ee);
     styleHist(eop_b[iH], kColor, kFill, kMark, 1, 1.5);
     styleHist(eop_e[iH], kColor, kFill, kMark, 1, 1.5);

     esp_b[iH] = new TH1D(("esp_b_" + toStr(iH)).c_str(), "Seed 1/E - 1/P Distribution", mBin.at("eop").nBin_eb, mBin.at("eop").min_eb, mBin.at("eop").max_eb);
     esp_e[iH] = new TH1D(("esp_e_" + toStr(iH)).c_str(), "Seed 1/E - 1/P Distribution", mBin.at("eop").nBin_ee, mBin.at("eop").min_ee, mBin.at("eop").max_ee);
     styleHist(esp_b[iH], kColor, kFill, kMark, 1, 1.5);
     styleHist(esp_e[iH], kColor, kFill, kMark, 1, 1.5);

     chi_b[iH] = new TH1D(("chi_b_" + toStr(iH)).c_str(), "Track #chi^{2} Distribution", mBin.at("chi").nBin_eb, mBin.at("chi").min_eb, mBin.at("chi").max_eb);
     chi_e[iH] = new TH1D(("chi_e_" + toStr(iH)).c_str(), "Track #chi^{2} Distribution", mBin.at("chi").nBin_ee, mBin.at("chi").min_ee, mBin.at("chi").max_ee);
     styleHist(chi_b[iH], kColor, kFill, kMark, 1, 1.5);
     styleHist(chi_e[iH], kColor, kFill, kMark, 1, 1.5);

     mih_b[iH] = new TH1D(("mih_b_" + toStr(iH)).c_str(), "Missing Hits Distribution", mBin.at("mih").nBin_eb, mBin.at("mih").min_eb, mBin.at("mih").max_eb);
     mih_e[iH] = new TH1D(("mih_e_" + toStr(iH)).c_str(), "Missing Hits Distribution", mBin.at("mih").nBin_ee, mBin.at("mih").min_ee, mBin.at("mih").max_ee);
     styleHist(mih_b[iH], kColor, kFill, kMark, 1, 1.5);
     styleHist(mih_e[iH], kColor, kFill, kMark, 1, 1.5);

     des_b[iH] = new TH1D(("des_b_" + toStr(iH)).c_str(), "Seed #Delta#eta Distribution", mBin.at("des").nBin_eb, mBin.at("des").min_eb, mBin.at("des").max_eb);
     des_e[iH] = new TH1D(("des_e_" + toStr(iH)).c_str(), "Seed #Delta#eta Distribution", mBin.at("des").nBin_ee, mBin.at("des").min_ee, mBin.at("des").max_ee);
     styleHist(des_b[iH], kColor, kFill, kMark, 1, 1.5);
     styleHist(des_e[iH], kColor, kFill, kMark, 1, 1.5);

     det_b[iH] = new TH1D(("det_b_" + toStr(iH)).c_str(), "SC #Delta#eta Distribution", mBin.at("des").nBin_eb, mBin.at("des").min_eb, mBin.at("des").max_eb);
     det_e[iH] = new TH1D(("det_e_" + toStr(iH)).c_str(), "SC #Delta#eta Distribution", mBin.at("des").nBin_ee, mBin.at("des").min_ee, mBin.at("des").max_ee);
     styleHist(det_b[iH], kColor, kFill, kMark, 1, 1.5);
     styleHist(det_e[iH], kColor, kFill, kMark, 1, 1.5);

     dph_b[iH] = new TH1D(("dph_b_" + toStr(iH)).c_str(), "SC #Delta#phi Distribution", mBin.at("dph").nBin_eb, mBin.at("dph").min_eb, mBin.at("dph").max_eb);
     dph_e[iH] = new TH1D(("dph_e_" + toStr(iH)).c_str(), "SC #Delta#phi Distribution", mBin.at("dph").nBin_ee, mBin.at("dph").min_ee, mBin.at("dph").max_ee);
     styleHist(dph_b[iH], kColor, kFill, kMark, 1, 1.5);
     styleHist(dph_e[iH], kColor, kFill, kMark, 1, 1.5);

     tkr_b[iH] = new TH1D(("tkr_b_" + toStr(iH)).c_str(), "Rel. TrackIso Distribution", mBin.at("tkr").nBin_eb, mBin.at("tkr").min_eb, mBin.at("tkr").max_eb);
     tkr_e[iH] = new TH1D(("tkr_e_" + toStr(iH)).c_str(), "Rel. TrackIso Distribution", mBin.at("tkr").nBin_ee, mBin.at("tkr").min_ee, mBin.at("tkr").max_ee);
     styleHist(tkr_b[iH], kColor, kFill, kMark, 1, 1.5);
     styleHist(tkr_e[iH], kColor, kFill, kMark, 1, 1.5);

     lol_b[iH] = new TH1D(("lol_b_" + toStr(iH)).c_str(), "Lolwtf Distribution", mBin.at("lol").nBin_eb, mBin.at("lol").min_eb, mBin.at("lol").max_eb);
     lol_e[iH] = new TH1D(("lol_e_" + toStr(iH)).c_str(), "Lolwtf Distribution", mBin.at("lol").nBin_ee, mBin.at("lol").min_ee, mBin.at("lol").max_ee);
     styleHist(lol_b[iH], kColor, kFill, kMark, 1, 1.5);
     styleHist(lol_e[iH], kColor, kFill, kMark, 1, 1.5);

     // rho corrected isos - 0 EA95 1 EA97 2 EANT95 3 EANT97
     hor0_b[iH] = new TH1D(("hor0_b_" + toStr(iH)).c_str(), "Hadronic / EM Distribution", mBin.at("hor").nBin_eb, mBin.at("hor").min_eb, mBin.at("hor").max_eb);
     hor0_e[iH] = new TH1D(("hor0_e_" + toStr(iH)).c_str(), "Hadronic / EM Distribution", mBin.at("hor").nBin_ee, mBin.at("hor").min_ee, mBin.at("hor").max_ee);
     styleHist(hor0_b[iH], kColor, kFill, kMark, 1, 1.5);
     styleHist(hor0_e[iH], kColor, kFill, kMark, 1, 1.5);

     ecr0_b[iH] = new TH1D(("ecr0_b_" + toStr(iH)).c_str(), "Rel. EcalIso Distribution", mBin.at("ecr").nBin_eb, mBin.at("ecr").min_eb, mBin.at("ecr").max_eb);
     ecr0_e[iH] = new TH1D(("ecr0_e_" + toStr(iH)).c_str(), "Rel. EcalIso Distribution", mBin.at("ecr").nBin_ee, mBin.at("ecr").min_ee, mBin.at("ecr").max_ee);
     styleHist(ecr0_b[iH], kColor, kFill, kMark, 1, 1.5);
     styleHist(ecr0_e[iH], kColor, kFill, kMark, 1, 1.5);

     hcr0_b[iH] = new TH1D(("hcr0_b_" + toStr(iH)).c_str(), "Rel. HcalIso Distribution", mBin.at("hcr").nBin_eb, mBin.at("hcr").min_eb, mBin.at("hcr").max_eb);
     hcr0_e[iH] = new TH1D(("hcr0_e_" + toStr(iH)).c_str(), "Rel. HcalIso Distribution", mBin.at("hcr").nBin_ee, mBin.at("hcr").min_ee, mBin.at("hcr").max_ee);
     styleHist(hcr0_b[iH], kColor, kFill, kMark, 1, 1.5);
     styleHist(hcr0_e[iH], kColor, kFill, kMark, 1, 1.5);

     tkr0_b[iH] = new TH1D(("tkr0_b_" + toStr(iH)).c_str(), "Rel. TrackIso Distribution", mBin.at("tkr").nBin_eb, mBin.at("tkr").min_eb, mBin.at("tkr").max_eb);
     tkr0_e[iH] = new TH1D(("tkr0_e_" + toStr(iH)).c_str(), "Rel. TrackIso Distribution", mBin.at("tkr").nBin_ee, mBin.at("tkr").min_ee, mBin.at("tkr").max_ee);
     styleHist(tkr0_b[iH], kColor, kFill, kMark, 1, 1.5);
     styleHist(tkr0_e[iH], kColor, kFill, kMark, 1, 1.5);

     hor1_b[iH] = new TH1D(("hor1_b_" + toStr(iH)).c_str(), "Hadronic / EM Distribution", mBin.at("hor").nBin_eb, mBin.at("hor").min_eb, mBin.at("hor").max_eb);
     hor1_e[iH] = new TH1D(("hor1_e_" + toStr(iH)).c_str(), "Hadronic / EM Distribution", mBin.at("hor").nBin_ee, mBin.at("hor").min_ee, mBin.at("hor").max_ee);
     styleHist(hor1_b[iH], kColor, kFill, kMark, 1, 1.5);
     styleHist(hor1_e[iH], kColor, kFill, kMark, 1, 1.5);

     ecr1_b[iH] = new TH1D(("ecr1_b_" + toStr(iH)).c_str(), "Rel. EcalIso Distribution", mBin.at("ecr").nBin_eb, mBin.at("ecr").min_eb, mBin.at("ecr").max_eb);
     ecr1_e[iH] = new TH1D(("ecr1_e_" + toStr(iH)).c_str(), "Rel. EcalIso Distribution", mBin.at("ecr").nBin_ee, mBin.at("ecr").min_ee, mBin.at("ecr").max_ee);
     styleHist(ecr1_b[iH], kColor, kFill, kMark, 1, 1.5);
     styleHist(ecr1_e[iH], kColor, kFill, kMark, 1, 1.5);

     hcr1_b[iH] = new TH1D(("hcr1_b_" + toStr(iH)).c_str(), "Rel. HcalIso Distribution", mBin.at("hcr").nBin_eb, mBin.at("hcr").min_eb, mBin.at("hcr").max_eb);
     hcr1_e[iH] = new TH1D(("hcr1_e_" + toStr(iH)).c_str(), "Rel. HcalIso Distribution", mBin.at("hcr").nBin_ee, mBin.at("hcr").min_ee, mBin.at("hcr").max_ee);
     styleHist(hcr1_b[iH], kColor, kFill, kMark, 1, 1.5);
     styleHist(hcr1_e[iH], kColor, kFill, kMark, 1, 1.5);

     tkr1_b[iH] = new TH1D(("tkr1_b_" + toStr(iH)).c_str(), "Rel. TrackIso Distribution", mBin.at("tkr").nBin_eb, mBin.at("tkr").min_eb, mBin.at("tkr").max_eb);
     tkr1_e[iH] = new TH1D(("tkr1_e_" + toStr(iH)).c_str(), "Rel. TrackIso Distribution", mBin.at("tkr").nBin_ee, mBin.at("tkr").min_ee, mBin.at("tkr").max_ee);
     styleHist(tkr1_b[iH], kColor, kFill, kMark, 1, 1.5);
     styleHist(tkr1_e[iH], kColor, kFill, kMark, 1, 1.5);

     hor2_b[iH] = new TH1D(("hor2_b_" + toStr(iH)).c_str(), "Hadronic / EM Distribution", mBin.at("hor").nBin_eb, mBin.at("hor").min_eb, mBin.at("hor").max_eb);
     hor2_e[iH] = new TH1D(("hor2_e_" + toStr(iH)).c_str(), "Hadronic / EM Distribution", mBin.at("hor").nBin_ee, mBin.at("hor").min_ee, mBin.at("hor").max_ee);
     styleHist(hor2_b[iH], kColor, kFill, kMark, 1, 1.5);
     styleHist(hor2_e[iH], kColor, kFill, kMark, 1, 1.5);

     ecr2_b[iH] = new TH1D(("ecr2_b_" + toStr(iH)).c_str(), "Rel. EcalIso Distribution", mBin.at("ecr").nBin_eb, mBin.at("ecr").min_eb, mBin.at("ecr").max_eb);
     ecr2_e[iH] = new TH1D(("ecr2_e_" + toStr(iH)).c_str(), "Rel. EcalIso Distribution", mBin.at("ecr").nBin_ee, mBin.at("ecr").min_ee, mBin.at("ecr").max_ee);
     styleHist(ecr2_b[iH], kColor, kFill, kMark, 1, 1.5);
     styleHist(ecr2_e[iH], kColor, kFill, kMark, 1, 1.5);

     hcr2_b[iH] = new TH1D(("hcr2_b_" + toStr(iH)).c_str(), "Rel. HcalIso Distribution", mBin.at("hcr").nBin_eb, mBin.at("hcr").min_eb, mBin.at("hcr").max_eb);
     hcr2_e[iH] = new TH1D(("hcr2_e_" + toStr(iH)).c_str(), "Rel. HcalIso Distribution", mBin.at("hcr").nBin_ee, mBin.at("hcr").min_ee, mBin.at("hcr").max_ee);
     styleHist(hcr2_b[iH], kColor, kFill, kMark, 1, 1.5);
     styleHist(hcr2_e[iH], kColor, kFill, kMark, 1, 1.5);

     tkr2_b[iH] = new TH1D(("tkr2_b_" + toStr(iH)).c_str(), "Rel. TrackIso Distribution", mBin.at("tkr").nBin_eb, mBin.at("tkr").min_eb, mBin.at("tkr").max_eb);
     tkr2_e[iH] = new TH1D(("tkr2_e_" + toStr(iH)).c_str(), "Rel. TrackIso Distribution", mBin.at("tkr").nBin_ee, mBin.at("tkr").min_ee, mBin.at("tkr").max_ee);
     styleHist(tkr2_b[iH], kColor, kFill, kMark, 1, 1.5);
     styleHist(tkr2_e[iH], kColor, kFill, kMark, 1, 1.5);

     hor3_b[iH] = new TH1D(("hor3_b_" + toStr(iH)).c_str(), "Hadronic / EM Distribution", mBin.at("hor").nBin_eb, mBin.at("hor").min_eb, mBin.at("hor").max_eb);
     hor3_e[iH] = new TH1D(("hor3_e_" + toStr(iH)).c_str(), "Hadronic / EM Distribution", mBin.at("hor").nBin_ee, mBin.at("hor").min_ee, mBin.at("hor").max_ee);
     styleHist(hor3_b[iH], kColor, kFill, kMark, 1, 1.5);
     styleHist(hor3_e[iH], kColor, kFill, kMark, 1, 1.5);

     ecr3_b[iH] = new TH1D(("ecr3_b_" + toStr(iH)).c_str(), "Rel. EcalIso Distribution", mBin.at("ecr").nBin_eb, mBin.at("ecr").min_eb, mBin.at("ecr").max_eb);
     ecr3_e[iH] = new TH1D(("ecr3_e_" + toStr(iH)).c_str(), "Rel. EcalIso Distribution", mBin.at("ecr").nBin_ee, mBin.at("ecr").min_ee, mBin.at("ecr").max_ee);
     styleHist(ecr3_b[iH], kColor, kFill, kMark, 1, 1.5);
     styleHist(ecr3_e[iH], kColor, kFill, kMark, 1, 1.5);

     hcr3_b[iH] = new TH1D(("hcr3_b_" + toStr(iH)).c_str(), "Rel. HcalIso Distribution", mBin.at("hcr").nBin_eb, mBin.at("hcr").min_eb, mBin.at("hcr").max_eb);
     hcr3_e[iH] = new TH1D(("hcr3_e_" + toStr(iH)).c_str(), "Rel. HcalIso Distribution", mBin.at("hcr").nBin_ee, mBin.at("hcr").min_ee, mBin.at("hcr").max_ee);
     styleHist(hcr3_b[iH], kColor, kFill, kMark, 1, 1.5);
     styleHist(hcr3_e[iH], kColor, kFill, kMark, 1, 1.5);

     tkr3_b[iH] = new TH1D(("tkr3_b_" + toStr(iH)).c_str(), "Rel. TrackIso Distribution", mBin.at("tkr").nBin_eb, mBin.at("tkr").min_eb, mBin.at("tkr").max_eb);
     tkr3_e[iH] = new TH1D(("tkr3_e_" + toStr(iH)).c_str(), "Rel. TrackIso Distribution", mBin.at("tkr").nBin_ee, mBin.at("tkr").min_ee, mBin.at("tkr").max_ee);
     styleHist(tkr3_b[iH], kColor, kFill, kMark, 1, 1.5);
     styleHist(tkr3_e[iH], kColor, kFill, kMark, 1, 1.5);
   }

   // -------------------------------------------------- //

   TChain *t1 = new TChain("hltTree");
   for (int iH = 0; iH < nH; iH++)
     t1->Add((inDir + pairFileLeg[iH].first + ".root").c_str());

   bool isMC = true;

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
   double normWgt;
   t1->SetBranchAddress("normWgt", &normWgt);
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

   int mc_nPUtrue, gp_n, mc_nPUobs;
   double genWgt, gp_pt[10], gp_eta[10], gp_phi[10];

    if (isMC) {
      t1->SetBranchAddress("genWgt", &genWgt);
      t1->SetBranchAddress("gp_n", &gp_n);
      t1->SetBranchAddress("gp_pt", gp_pt);
      t1->SetBranchAddress("gp_eta", gp_eta);
      t1->SetBranchAddress("gp_phi", gp_phi);
      t1->SetBranchAddress("mc_nPUtrue", &mc_nPUtrue);
      t1->SetBranchAddress("mc_nPUobs", &mc_nPUobs);
    }

   // -------------------------------------------------- //
   // The TnP version of efficiency checker

   TLorentzVector p4Tag, p4Prb;
   double finWgt = 1.;
   const std::string eaWP = "", itWP = "" /*"IterWP_etDep"*/;

   int nEvt0 = t1->GetEntries();
   std::cout << "nEvt0 = " << nEvt0 << std::endl;

   for (int evt0 = 0; evt0 < nEvt0; evt0++) {

     t1->GetEntry(evt0);

     finWgt = puWgt * normWgt;
     if (isMC) finWgt *= genWgt;

     for (int iTag = 0; iTag < n; iTag++) {
       if (et[iTag] < 35. or std::abs(eta[iTag]) > etaEE) continue;

       if (!checkCand("", vNoMask, rho,
                      e[iTag], et[iTag], eta[iTag], phi[iTag],
                      sie[iTag], hoe[iTag], eca[iTag], hca[iTag], eop[iTag],
                      chi[iTag], mih[iTag], des[iTag], dph[iTag], tks[iTag],
                      ps2[iTag])) continue;

       const bool cndPass = checkCand(itWP, vNoMask, rho,
                                      e[iTag], et[iTag], eta[iTag], phi[iTag],
                                      sie[iTag], hoe[iTag], eca[iTag], hca[iTag], eop[iTag],
                                      chi[iTag], mih[iTag], des[iTag], dph[iTag], tks[iTag],
                                      ps2[iTag]);

       if (type > 0 and cndPass /*and et[iTag] > 60.*/) {
         eta_b[1]->Fill(eta[iTag], finWgt);
         eta_e[1]->Fill(eta[iTag], finWgt);

         if (std::abs(eta[iTag]) < etaEB) {
           eet_b[1]->Fill( et[iTag], finWgt );
           phi_b[1]->Fill( phi[iTag], finWgt );
           sie_b[1]->Fill( sie[iTag], finWgt );
           hor_b[1]->Fill( doRhoCorrection(hoe[iTag], et[iTag], eta[iTag], rho, "EANT17_1_q0p97", "hoe") / e[iTag], finWgt );
           ecr_b[1]->Fill( doRhoCorrection(eca[iTag], et[iTag], eta[iTag], rho, "EANT17_1_q0p97", "eca") / et[iTag], finWgt );
           hcr_b[1]->Fill( doRhoCorrection(hca[iTag], et[iTag], eta[iTag], rho, "EANT17_1_q0p97", "hca") / et[iTag], finWgt );
           ps2_b[1]->Fill( ps2[iTag], finWgt );
           eop_b[1]->Fill( eop[iTag], finWgt );
           esp_b[1]->Fill( esp[iTag], finWgt );
           chi_b[1]->Fill( chi[iTag], finWgt );
           mih_b[1]->Fill( mih[iTag], finWgt );
           des_b[1]->Fill( des[iTag], finWgt );
           det_b[1]->Fill( det[iTag], finWgt );
           dph_b[1]->Fill( dph[iTag], finWgt );
           tkr_b[1]->Fill( doRhoCorrection(tks[iTag], et[iTag], eta[iTag], rho, "EANT17_1_q0p97", "tks") / et[iTag], finWgt );

           hor0_b[1]->Fill( doRhoCorrection(hoe[iTag], et[iTag], eta[iTag], rho, "EA17_1_q0p95", "hoe") / e[iTag], finWgt );
           ecr0_b[1]->Fill( doRhoCorrection(eca[iTag], et[iTag], eta[iTag], rho, "EA17_1_q0p95", "eca") / et[iTag], finWgt );
           hcr0_b[1]->Fill( doRhoCorrection(hca[iTag], et[iTag], eta[iTag], rho, "EA17_1_q0p95", "hca") / et[iTag], finWgt );
           tkr0_b[1]->Fill( doRhoCorrection(tks[iTag], et[iTag], eta[iTag], rho, "EA17_1_q0p95", "tks") / et[iTag], finWgt );

           hor1_b[1]->Fill( doRhoCorrection(hoe[iTag], et[iTag], eta[iTag], rho, "EA17_1_q0p97", "hoe") / e[iTag], finWgt );
           ecr1_b[1]->Fill( doRhoCorrection(eca[iTag], et[iTag], eta[iTag], rho, "EA17_1_q0p97", "eca") / et[iTag], finWgt );
           hcr1_b[1]->Fill( doRhoCorrection(hca[iTag], et[iTag], eta[iTag], rho, "EA17_1_q0p97", "hca") / et[iTag], finWgt );
           tkr1_b[1]->Fill( doRhoCorrection(tks[iTag], et[iTag], eta[iTag], rho, "EA17_1_q0p97", "tks") / et[iTag], finWgt );

           hor2_b[1]->Fill( doRhoCorrection(hoe[iTag], et[iTag], eta[iTag], rho, "EANT17_1_q0p95", "hoe") / e[iTag], finWgt );
           ecr2_b[1]->Fill( doRhoCorrection(eca[iTag], et[iTag], eta[iTag], rho, "EANT17_1_q0p95", "eca") / et[iTag], finWgt );
           hcr2_b[1]->Fill( doRhoCorrection(hca[iTag], et[iTag], eta[iTag], rho, "EANT17_1_q0p95", "hca") / et[iTag], finWgt );
           tkr2_b[1]->Fill( doRhoCorrection(tks[iTag], et[iTag], eta[iTag], rho, "EANT17_1_q0p95", "tks") / et[iTag], finWgt );

           hor3_b[1]->Fill( doRhoCorrection(hoe[iTag], et[iTag], eta[iTag], rho, "EANT17_1_q0p97", "hoe") / e[iTag], finWgt );
           ecr3_b[1]->Fill( doRhoCorrection(eca[iTag], et[iTag], eta[iTag], rho, "EANT17_1_q0p97", "eca") / et[iTag], finWgt );
           hcr3_b[1]->Fill( doRhoCorrection(hca[iTag], et[iTag], eta[iTag], rho, "EANT17_1_q0p97", "hca") / et[iTag], finWgt );
           tkr3_b[1]->Fill( doRhoCorrection(tks[iTag], et[iTag], eta[iTag], rho, "EANT17_1_q0p97", "tks") / et[iTag], finWgt );
         }

         if (std::abs(eta[iTag]) >= etaET) {
           eet_e[1]->Fill( et[iTag], finWgt );
           phi_e[1]->Fill( phi[iTag], finWgt );
           sie_e[1]->Fill( sie[iTag], finWgt );
           hor_e[1]->Fill( doRhoCorrection(hoe[iTag], et[iTag], eta[iTag], rho, "EANT17_1_q0p97", "hoe") / e[iTag], finWgt );
           ecr_e[1]->Fill( doRhoCorrection(eca[iTag], et[iTag], eta[iTag], rho, "EANT17_1_q0p97", "eca") / et[iTag], finWgt );
           hcr_e[1]->Fill( doRhoCorrection(hca[iTag], et[iTag], eta[iTag], rho, "EANT17_1_q0p97", "hca") / et[iTag], finWgt );
           ps2_e[1]->Fill( ps2[iTag], finWgt );
           eop_e[1]->Fill( eop[iTag], finWgt );
           esp_e[1]->Fill( esp[iTag], finWgt );
           chi_e[1]->Fill( chi[iTag], finWgt );
           mih_e[1]->Fill( mih[iTag], finWgt );
           des_e[1]->Fill( des[iTag], finWgt );
           det_e[1]->Fill( det[iTag], finWgt );
           dph_e[1]->Fill( dph[iTag], finWgt );
           tkr_e[1]->Fill( doRhoCorrection(tks[iTag], et[iTag], eta[iTag], rho, "EANT17_1_q0p97", "tks") / et[iTag], finWgt );

           hor0_e[1]->Fill( doRhoCorrection(hoe[iTag], et[iTag], eta[iTag], rho, "EA17_1_q0p95", "hoe") / e[iTag], finWgt );
           ecr0_e[1]->Fill( doRhoCorrection(eca[iTag], et[iTag], eta[iTag], rho, "EA17_1_q0p95", "eca") / et[iTag], finWgt );
           hcr0_e[1]->Fill( doRhoCorrection(hca[iTag], et[iTag], eta[iTag], rho, "EA17_1_q0p95", "hca") / et[iTag], finWgt );
           tkr0_e[1]->Fill( doRhoCorrection(tks[iTag], et[iTag], eta[iTag], rho, "EA17_1_q0p95", "tks") / et[iTag], finWgt );

           hor1_e[1]->Fill( doRhoCorrection(hoe[iTag], et[iTag], eta[iTag], rho, "EA17_1_q0p97", "hoe") / e[iTag], finWgt );
           ecr1_e[1]->Fill( doRhoCorrection(eca[iTag], et[iTag], eta[iTag], rho, "EA17_1_q0p97", "eca") / et[iTag], finWgt );
           hcr1_e[1]->Fill( doRhoCorrection(hca[iTag], et[iTag], eta[iTag], rho, "EA17_1_q0p97", "hca") / et[iTag], finWgt );
           tkr1_e[1]->Fill( doRhoCorrection(tks[iTag], et[iTag], eta[iTag], rho, "EA17_1_q0p97", "tks") / et[iTag], finWgt );

           hor2_e[1]->Fill( doRhoCorrection(hoe[iTag], et[iTag], eta[iTag], rho, "EANT17_1_q0p95", "hoe") / e[iTag], finWgt );
           ecr2_e[1]->Fill( doRhoCorrection(eca[iTag], et[iTag], eta[iTag], rho, "EANT17_1_q0p95", "eca") / et[iTag], finWgt );
           hcr2_e[1]->Fill( doRhoCorrection(hca[iTag], et[iTag], eta[iTag], rho, "EANT17_1_q0p95", "hca") / et[iTag], finWgt );
           tkr2_e[1]->Fill( doRhoCorrection(tks[iTag], et[iTag], eta[iTag], rho, "EANT17_1_q0p95", "tks") / et[iTag], finWgt );

           hor3_e[1]->Fill( doRhoCorrection(hoe[iTag], et[iTag], eta[iTag], rho, "EANT17_1_q0p97", "hoe") / e[iTag], finWgt );
           ecr3_e[1]->Fill( doRhoCorrection(eca[iTag], et[iTag], eta[iTag], rho, "EANT17_1_q0p97", "eca") / et[iTag], finWgt );
           hcr3_e[1]->Fill( doRhoCorrection(hca[iTag], et[iTag], eta[iTag], rho, "EANT17_1_q0p97", "hca") / et[iTag], finWgt );
           tkr3_e[1]->Fill( doRhoCorrection(tks[iTag], et[iTag], eta[iTag], rho, "EANT17_1_q0p97", "tks") / et[iTag], finWgt );
         }
       } // cand bkg

       if (type == -1 and n > 1) {
         //if (pass[iTag] != 1) continue;
         if (isMC and genMatch[iTag] != 1) continue;

         p4Tag.SetPtEtaPhiE(et[iTag], eta[iTag], phi[iTag], e[iTag]);

         for (int iPrb = 0; iPrb < n; iPrb++) {
           if (iPrb == iTag) continue;
           if (isMC and genMatch[iPrb] != 1) continue;
           if (et[iPrb] < 35. or std::abs(eta[iPrb]) > etaEE) continue;
           //if (et[iPrb] < 60.) continue;

           p4Prb.SetPtEtaPhiE(et[iPrb], eta[iPrb], phi[iPrb], e[iPrb]);

           if ((p4Tag + p4Prb).M() < 70. or (p4Tag + p4Prb).M() > 110.) continue;

           if (!checkCand(itWP, vNoMask, rho,
                          e[iPrb], et[iPrb], eta[iPrb], phi[iPrb],
                          sie[iPrb], hoe[iPrb], eca[iPrb], hca[iPrb], eop[iPrb],
                          chi[iPrb], mih[iPrb], des[iPrb], dph[iPrb], tks[iPrb],
                          ps2[iPrb])) continue;

           eta_b[0]->Fill( eta[iPrb], finWgt );
           eta_e[0]->Fill( eta[iPrb], finWgt );

           if (std::abs(eta[iPrb]) < etaEB) {
             eet_b[0]->Fill( et[iPrb], finWgt );
             phi_b[0]->Fill( phi[iPrb], finWgt );
             sie_b[0]->Fill( sie[iPrb], finWgt );
             hor_b[0]->Fill( doRhoCorrection(hoe[iPrb], et[iPrb], eta[iPrb], rho, "EANT17_1_q0p97", "hoe") / e[iPrb], finWgt );
             ecr_b[0]->Fill( doRhoCorrection(eca[iPrb], et[iPrb], eta[iPrb], rho, "EANT17_1_q0p97", "eca") / et[iPrb], finWgt );
             hcr_b[0]->Fill( doRhoCorrection(hca[iPrb], et[iPrb], eta[iPrb], rho, "EANT17_1_q0p97", "hca") / et[iPrb], finWgt );
             ps2_b[0]->Fill( ps2[iPrb], finWgt );
             eop_b[0]->Fill( eop[iPrb], finWgt );
             esp_b[0]->Fill( esp[iPrb], finWgt );
             chi_b[0]->Fill( chi[iPrb], finWgt );
             mih_b[0]->Fill( mih[iPrb], finWgt );
             des_b[0]->Fill( des[iPrb], finWgt );
             det_b[0]->Fill( det[iPrb], finWgt );
             dph_b[0]->Fill( dph[iPrb], finWgt );
             tkr_b[0]->Fill( doRhoCorrection(tks[iPrb], et[iPrb], eta[iPrb], rho, "EANT17_1_q0p97", "tks") / et[iPrb], finWgt );

             hor0_b[0]->Fill( doRhoCorrection(hoe[iPrb], et[iPrb], eta[iPrb], rho, "EA17_1_q0p95", "hoe") / e[iPrb], finWgt );
             ecr0_b[0]->Fill( doRhoCorrection(eca[iPrb], et[iPrb], eta[iPrb], rho, "EA17_1_q0p95", "eca") / et[iPrb], finWgt );
             hcr0_b[0]->Fill( doRhoCorrection(hca[iPrb], et[iPrb], eta[iPrb], rho, "EA17_1_q0p95", "hca") / et[iPrb], finWgt );
             tkr0_b[0]->Fill( doRhoCorrection(tks[iPrb], et[iPrb], eta[iPrb], rho, "EA17_1_q0p95", "tks") / et[iPrb], finWgt );

             hor1_b[0]->Fill( doRhoCorrection(hoe[iPrb], et[iPrb], eta[iPrb], rho, "EA17_1_q0p97", "hoe") / e[iPrb], finWgt );
             ecr1_b[0]->Fill( doRhoCorrection(eca[iPrb], et[iPrb], eta[iPrb], rho, "EA17_1_q0p97", "eca") / et[iPrb], finWgt );
             hcr1_b[0]->Fill( doRhoCorrection(hca[iPrb], et[iPrb], eta[iPrb], rho, "EA17_1_q0p97", "hca") / et[iPrb], finWgt );
             tkr1_b[0]->Fill( doRhoCorrection(tks[iPrb], et[iPrb], eta[iPrb], rho, "EA17_1_q0p97", "tks") / et[iPrb], finWgt );

             hor2_b[0]->Fill( doRhoCorrection(hoe[iPrb], et[iPrb], eta[iPrb], rho, "EANT17_1_q0p95", "hoe") / e[iPrb], finWgt );
             ecr2_b[0]->Fill( doRhoCorrection(eca[iPrb], et[iPrb], eta[iPrb], rho, "EANT17_1_q0p95", "eca") / et[iPrb], finWgt );
             hcr2_b[0]->Fill( doRhoCorrection(hca[iPrb], et[iPrb], eta[iPrb], rho, "EANT17_1_q0p95", "hca") / et[iPrb], finWgt );
             tkr2_b[0]->Fill( doRhoCorrection(tks[iPrb], et[iPrb], eta[iPrb], rho, "EANT17_1_q0p95", "tks") / et[iPrb], finWgt );

             hor3_b[0]->Fill( doRhoCorrection(hoe[iPrb], et[iPrb], eta[iPrb], rho, "EANT17_1_q0p97", "hoe") / e[iPrb], finWgt );
             ecr3_b[0]->Fill( doRhoCorrection(eca[iPrb], et[iPrb], eta[iPrb], rho, "EANT17_1_q0p97", "eca") / et[iPrb], finWgt );
             hcr3_b[0]->Fill( doRhoCorrection(hca[iPrb], et[iPrb], eta[iPrb], rho, "EANT17_1_q0p97", "hca") / et[iPrb], finWgt );
             tkr3_b[0]->Fill( doRhoCorrection(tks[iPrb], et[iPrb], eta[iPrb], rho, "EANT17_1_q0p97", "tks") / et[iPrb], finWgt );
           }

           if (std::abs(eta[iPrb]) >= etaET) {
             eet_e[0]->Fill( et[iPrb], finWgt );
             phi_e[0]->Fill( phi[iPrb], finWgt );
             sie_e[0]->Fill( sie[iPrb], finWgt );
             hor_e[0]->Fill( doRhoCorrection(hoe[iPrb], et[iPrb], eta[iPrb], rho, "EANT17_1_q0p97", "hoe") / e[iPrb], finWgt );
             ecr_e[0]->Fill( doRhoCorrection(eca[iPrb], et[iPrb], eta[iPrb], rho, "EANT17_1_q0p97", "eca") / et[iPrb], finWgt );
             hcr_e[0]->Fill( doRhoCorrection(hca[iPrb], et[iPrb], eta[iPrb], rho, "EANT17_1_q0p97", "hca") / et[iPrb], finWgt );
             ps2_e[0]->Fill( ps2[iPrb], finWgt );
             eop_e[0]->Fill( eop[iPrb], finWgt );
             esp_e[0]->Fill( esp[iPrb], finWgt );
             chi_e[0]->Fill( chi[iPrb], finWgt );
             mih_e[0]->Fill( mih[iPrb], finWgt );
             des_e[0]->Fill( des[iPrb], finWgt );
             det_e[0]->Fill( det[iPrb], finWgt );
             dph_e[0]->Fill( dph[iPrb], finWgt );
             tkr_e[0]->Fill( doRhoCorrection(tks[iPrb], et[iPrb], eta[iPrb], rho, "EANT17_1_q0p97", "tks") / et[iPrb], finWgt );

             hor0_e[0]->Fill( doRhoCorrection(hoe[iPrb], et[iPrb], eta[iPrb], rho, "EA17_1_q0p95", "hoe") / e[iPrb], finWgt );
             ecr0_e[0]->Fill( doRhoCorrection(eca[iPrb], et[iPrb], eta[iPrb], rho, "EA17_1_q0p95", "eca") / et[iPrb], finWgt );
             hcr0_e[0]->Fill( doRhoCorrection(hca[iPrb], et[iPrb], eta[iPrb], rho, "EA17_1_q0p95", "hca") / et[iPrb], finWgt );
             tkr0_e[0]->Fill( doRhoCorrection(tks[iPrb], et[iPrb], eta[iPrb], rho, "EA17_1_q0p95", "tks") / et[iPrb], finWgt );

             hor1_e[0]->Fill( doRhoCorrection(hoe[iPrb], et[iPrb], eta[iPrb], rho, "EA17_1_q0p97", "hoe") / e[iPrb], finWgt );
             ecr1_e[0]->Fill( doRhoCorrection(eca[iPrb], et[iPrb], eta[iPrb], rho, "EA17_1_q0p97", "eca") / et[iPrb], finWgt );
             hcr1_e[0]->Fill( doRhoCorrection(hca[iPrb], et[iPrb], eta[iPrb], rho, "EA17_1_q0p97", "hca") / et[iPrb], finWgt );
             tkr1_e[0]->Fill( doRhoCorrection(tks[iPrb], et[iPrb], eta[iPrb], rho, "EA17_1_q0p97", "tks") / et[iPrb], finWgt );

             hor2_e[0]->Fill( doRhoCorrection(hoe[iPrb], et[iPrb], eta[iPrb], rho, "EANT17_1_q0p95", "hoe") / e[iPrb], finWgt );
             ecr2_e[0]->Fill( doRhoCorrection(eca[iPrb], et[iPrb], eta[iPrb], rho, "EANT17_1_q0p95", "eca") / et[iPrb], finWgt );
             hcr2_e[0]->Fill( doRhoCorrection(hca[iPrb], et[iPrb], eta[iPrb], rho, "EANT17_1_q0p95", "hca") / et[iPrb], finWgt );
             tkr2_e[0]->Fill( doRhoCorrection(tks[iPrb], et[iPrb], eta[iPrb], rho, "EANT17_1_q0p95", "tks") / et[iPrb], finWgt );

             hor3_e[0]->Fill( doRhoCorrection(hoe[iPrb], et[iPrb], eta[iPrb], rho, "EANT17_1_q0p97", "hoe") / e[iPrb], finWgt );
             ecr3_e[0]->Fill( doRhoCorrection(eca[iPrb], et[iPrb], eta[iPrb], rho, "EANT17_1_q0p97", "eca") / et[iPrb], finWgt );
             hcr3_e[0]->Fill( doRhoCorrection(hca[iPrb], et[iPrb], eta[iPrb], rho, "EANT17_1_q0p97", "hca") / et[iPrb], finWgt );
             tkr3_e[0]->Fill( doRhoCorrection(tks[iPrb], et[iPrb], eta[iPrb], rho, "EANT17_1_q0p97", "tks") / et[iPrb], finWgt );
           }
         } // eol probe
       } // tnp sig
     } // eol tag
   } // eol evt

   // -------------------------------------------------- //

   const bool doNorm = true;
   const double yMin = .00002, yMax = .9999, iEt = 40.;
   const std::string yLbl = "a. u.", etBin = "_f0_etAll";
   std::string vName;
   std::vector< std::pair<double, int> > cutVC_b, cutVC_e;

   std::vector< std::pair<std::string, int> > pairWPCol;
   pairWPCol.push_back(std::make_pair( "Tight16", kBlack ));
   pairWPCol.push_back(std::make_pair( "IterTig_etAll", kGray + 1 ));
   pairWPCol.push_back(std::make_pair( "IterLoo_etAll", kCyan + 2 ));

   vName = "eta";
   fillWPCutVector(vName, iEt, cutVC_b, cutVC_e, pairWPCol);
   createEBEEPlot(pairFileLeg, vName + etBin, eta_b, eta_e, nH,
                  cutVC_b, cutVC_e, "", doNorm, -999., fName, "#eta", yLbl, false, -1, yMin, 0.059, yMin, 0.059);
   cutVC_b.clear(); cutVC_e.clear();

   vName = "eet";
   fillWPCutVector(vName, iEt, cutVC_b, cutVC_e, pairWPCol);
   createEBEEPlot(pairFileLeg, vName + etBin, eet_b, eet_e, nH,
                  cutVC_b, cutVC_e, "", doNorm, -999., fName, "E_{T} (GeV)", yLbl, false, -1, yMin, 0.239, yMin, 0.239);
   cutVC_b.clear(); cutVC_e.clear();

   vName = "phi";
   fillWPCutVector(vName, iEt, cutVC_b, cutVC_e, pairWPCol);
   createEBEEPlot(pairFileLeg, vName + etBin, phi_b, phi_e, nH,
                  cutVC_b, cutVC_e, "", doNorm, -999., fName, "#phi", yLbl, false, -1, yMin, 0.089, yMin, 0.089);
   cutVC_b.clear(); cutVC_e.clear();

   vName = "sie";
   fillWPCutVector(vName, iEt, cutVC_b, cutVC_e, pairWPCol);
   createEBEEPlot(pairFileLeg, vName + etBin, sie_b, sie_e, nH,
                  cutVC_b, cutVC_e, "", doNorm, -999., fName, "#sigma_{i#etai#eta}", yLbl, false, -1, yMin, 0.349, yMin, 0.239);
   createEBEEEffPlot(pairFileLeg, vName + etBin, sie_b, sie_e, nH,
                     cutVC_b, cutVC_e, "", doNorm, -999., fName, "#sigma_{i#etai#eta}", yLbl, false, 4, 0.001, 1.049, 0.001, 1.049);
   cutVC_b.clear(); cutVC_e.clear();

   vName = "hor";
   fillWPCutVector(vName, iEt, cutVC_b, cutVC_e, pairWPCol);
   createEBEEPlot(pairFileLeg, vName + etBin, hor_b, hor_e, nH,
                  cutVC_b, cutVC_e, "", doNorm, -999., fName, "H/E", yLbl, true, -1, yMin, 1.999, yMin, 1.999);
   createEBEEEffPlot(pairFileLeg, vName + etBin, hor_b, hor_e, nH,
                     cutVC_b, cutVC_e, "", doNorm, -999., fName, "H/E", yLbl, false, 4, 0.001, 1.049, 0.001, 1.049);
   cutVC_b.clear(); cutVC_e.clear();

   vName = "ecr";
   fillWPCutVector(vName, iEt, cutVC_b, cutVC_e, pairWPCol);
   createEBEEPlot(pairFileLeg, vName + etBin, ecr_b, ecr_e, nH,
                  cutVC_b, cutVC_e, "", doNorm, -999., fName, "Rel. EcalIso", yLbl, true, -1, yMin, 1.999, yMin, 1.999);
   createEBEEEffPlot(pairFileLeg, vName + etBin, ecr_b, ecr_e, nH,
                     cutVC_b, cutVC_e, "", doNorm, -999., fName, "Rel. EcalIso", yLbl, false, 4, 0.001, 1.049, 0.001, 1.049);
   cutVC_b.clear(); cutVC_e.clear();

   vName = "hcr";
   fillWPCutVector(vName, iEt, cutVC_b, cutVC_e, pairWPCol);
   createEBEEPlot(pairFileLeg, vName + etBin, hcr_b, hcr_e, nH,
                  cutVC_b, cutVC_e, "", doNorm, -999., fName, "Rel. HcalIso", yLbl, true, -1, yMin, 1.999, yMin, 1.999);
   createEBEEEffPlot(pairFileLeg, vName + etBin, hcr_b, hcr_e, nH,
                     cutVC_b, cutVC_e, "", doNorm, -999., fName, "Rel. HcalIso", yLbl, false, 4, 0.001, 1.049, 0.001, 1.049);
   cutVC_b.clear(); cutVC_e.clear();

   vName = "ps2";
   fillWPCutVector(vName, iEt, cutVC_b, cutVC_e, pairWPCol);
   createEBEEPlot(pairFileLeg, vName + etBin, ps2_b, ps2_e, nH,
                  cutVC_b, cutVC_e, "", doNorm, -999., fName, "PM s^{2}", yLbl, true, -1, yMin, 0.299, yMin, 0.399);
   createEBEEEffPlot(pairFileLeg, vName + etBin, ps2_b, ps2_e, nH,
                     cutVC_b, cutVC_e, "", doNorm, -999., fName, "PM s^{2}", yLbl, false, 4, 0.001, 1.049, 0.001, 1.049);
   cutVC_b.clear(); cutVC_e.clear();

   vName = "eop";
   fillWPCutVector(vName, iEt, cutVC_b, cutVC_e, pairWPCol);
   createEBEEPlot(pairFileLeg, vName + etBin, eop_b, eop_e, nH,
                  cutVC_b, cutVC_e, "", doNorm, -999., fName, "1/E - 1/P", yLbl, true, -1, yMin, 0.399, yMin, 0.499);
   createEBEEEffPlot(pairFileLeg, vName + etBin, eop_b, eop_e, nH,
                     cutVC_b, cutVC_e, "", doNorm, -999., fName, "1/E - 1/P", yLbl, false, 4, 0.001, 1.049, 0.001, 1.049);
   cutVC_b.clear(); cutVC_e.clear();

   vName = "esp";
   fillWPCutVector(vName, iEt, cutVC_b, cutVC_e, pairWPCol);
   createEBEEPlot(pairFileLeg, vName + etBin, esp_b, esp_e, nH,
                  cutVC_b, cutVC_e, "", doNorm, -999., fName, "1/E - 1/P", yLbl, true, -1, yMin, 0.399, yMin, 0.499);
   createEBEEEffPlot(pairFileLeg, vName + etBin, esp_b, esp_e, nH,
                     cutVC_b, cutVC_e, "", doNorm, -999., fName, "1/E - 1/P", yLbl, false, 4, 0.001, 1.049, 0.001, 1.049);
   cutVC_b.clear(); cutVC_e.clear();

   vName = "chi";
   fillWPCutVector(vName, iEt, cutVC_b, cutVC_e, pairWPCol);
   createEBEEPlot(pairFileLeg, vName + etBin, chi_b, chi_e, nH,
                  cutVC_b, cutVC_e, "", doNorm, -999., fName, "Track #chi^{2}", yLbl, false, -1, yMin, 0.139, yMin, 0.179);
   createEBEEEffPlot(pairFileLeg, vName + etBin, chi_b, chi_e, nH,
                     cutVC_b, cutVC_e, "", doNorm, -999., fName, "Track #chi^{2}", yLbl, false, 4, 0.001, 1.049, 0.001, 1.049);
   cutVC_b.clear(); cutVC_e.clear();

   vName = "mih";
   fillWPCutVector(vName, iEt, cutVC_b, cutVC_e, pairWPCol);
   createEBEEPlot(pairFileLeg, vName + etBin, mih_b, mih_e, nH,
                  cutVC_b, cutVC_e, "", doNorm, -999., fName, "Missing Hits", yLbl, false, -1, yMin, yMax, yMin, yMax);
   createEBEEEffPlot(pairFileLeg, vName + etBin, mih_b, mih_e, nH,
                     cutVC_b, cutVC_e, "", doNorm, -999., fName, "Missing Hits", yLbl, false, 4, 0.001, 1.049, 0.001, 1.049);
   cutVC_b.clear(); cutVC_e.clear();

   vName = "des";
   fillWPCutVector(vName, iEt, cutVC_b, cutVC_e, pairWPCol);
   createEBEEPlot(pairFileLeg, vName + etBin, des_b, des_e, nH,
                  cutVC_b, cutVC_e, "", doNorm, -999., fName, "#Delta#eta", yLbl, true, -1, yMin, 0.499, yMin, 0.299);
   createEBEEEffPlot(pairFileLeg, vName + etBin, des_b, des_e, nH,
                     cutVC_b, cutVC_e, "", doNorm, -999., fName, "#Delta#eta", yLbl, false, 4, 0.001, 1.049, 0.001, 1.049);
   cutVC_b.clear(); cutVC_e.clear();

   vName = "det";
   fillWPCutVector(vName, iEt, cutVC_b, cutVC_e, pairWPCol);
   createEBEEPlot(pairFileLeg, vName + etBin, det_b, det_e, nH,
                  cutVC_b, cutVC_e, "", doNorm, -999., fName, "#Delta#eta", yLbl, true, -1, yMin, 0.499, yMin, 0.299);
   createEBEEEffPlot(pairFileLeg, vName + etBin, det_b, det_e, nH,
                     cutVC_b, cutVC_e, "", doNorm, -999., fName, "#Delta#eta", yLbl, false, 4, 0.001, 1.049, 0.001, 1.049);
   cutVC_b.clear(); cutVC_e.clear();

   vName = "dph";
   fillWPCutVector(vName, iEt, cutVC_b, cutVC_e, pairWPCol);
   createEBEEPlot(pairFileLeg, vName + etBin, dph_b, dph_e, nH,
                  cutVC_b, cutVC_e, "", doNorm, -999., fName, "#Delta#phi", yLbl, true, -1, yMin, 0.299, yMin, 0.299);
   createEBEEEffPlot(pairFileLeg, vName + etBin, dph_b, dph_e, nH,
                     cutVC_b, cutVC_e, "", doNorm, -999., fName, "#Delta#phi", yLbl, false, 4, 0.001, 1.049, 0.001, 1.049);
   cutVC_b.clear(); cutVC_e.clear();

   vName = "tkr";
   fillWPCutVector(vName, iEt, cutVC_b, cutVC_e, pairWPCol);
   createEBEEPlot(pairFileLeg, vName + etBin, tkr_b, tkr_e, nH,
                  cutVC_b, cutVC_e, "", doNorm, -999., fName, "Rel. TrackIso", yLbl, true, -1, yMin, 1.999, yMin, 1.999);
   createEBEEEffPlot(pairFileLeg, vName + etBin, tkr_b, tkr_e, nH,
                     cutVC_b, cutVC_e, "", doNorm, -999., fName, "Rel. TrackIso", yLbl, false, 4, 0.001, 1.049, 0.001, 1.049);
   cutVC_b.clear(); cutVC_e.clear();

   /*/ rho corrected isos
   vName = "hor0";
   fillWPCutVector(vName, iEt, cutVC_b, cutVC_e, pairWPCol);
   createEBEEPlot(pairFileLeg, vName + etBin, hor0_b, hor0_e, nH,
                  cutVC_b, cutVC_e, "", doNorm, -999., fName, "H/E", yLbl, true, -1, yMin, 1.999, yMin, 1.999);
   createEBEEEffPlot(pairFileLeg, vName + etBin, hor0_b, hor0_e, nH,
                     cutVC_b, cutVC_e, "", doNorm, -999., fName, "H/E", yLbl, false, 4, 0.001, 1.049, 0.001, 1.049);
   cutVC_b.clear(); cutVC_e.clear();

   vName = "ecr0";
   fillWPCutVector(vName, iEt, cutVC_b, cutVC_e, pairWPCol);
   createEBEEPlot(pairFileLeg, vName + etBin, ecr0_b, ecr0_e, nH,
                  cutVC_b, cutVC_e, "", doNorm, -999., fName, "Rel. EcalIso", yLbl, true, -1, yMin, 1.999, yMin, 1.999);
   createEBEEEffPlot(pairFileLeg, vName + etBin, ecr0_b, ecr0_e, nH,
                     cutVC_b, cutVC_e, "", doNorm, -999., fName, "Rel. EcalIso", yLbl, false, 4, 0.001, 1.049, 0.001, 1.049);
   cutVC_b.clear(); cutVC_e.clear();

   vName = "hcr0";
   fillWPCutVector(vName, iEt, cutVC_b, cutVC_e, pairWPCol);
   createEBEEPlot(pairFileLeg, vName + etBin, hcr0_b, hcr0_e, nH,
                  cutVC_b, cutVC_e, "", doNorm, -999., fName, "Rel. HcalIso", yLbl, true, -1, yMin, 1.999, yMin, 1.999);
   createEBEEEffPlot(pairFileLeg, vName + etBin, hcr0_b, hcr0_e, nH,
                     cutVC_b, cutVC_e, "", doNorm, -999., fName, "Rel. HcalIso", yLbl, false, 4, 0.001, 1.049, 0.001, 1.049);
   cutVC_b.clear(); cutVC_e.clear();

   vName = "tkr0";
   fillWPCutVector(vName, iEt, cutVC_b, cutVC_e, pairWPCol);
   createEBEEPlot(pairFileLeg, vName + etBin, tkr0_b, tkr0_e, nH,
                  cutVC_b, cutVC_e, "", doNorm, -999., fName, "Rel. TrackIso", yLbl, true, -1, yMin, 1.999, yMin, 1.999);
   createEBEEEffPlot(pairFileLeg, vName + etBin, tkr0_b, tkr0_e, nH,
                     cutVC_b, cutVC_e, "", doNorm, -999., fName, "Rel. TrackIso", yLbl, false, 4, 0.001, 1.049, 0.001, 1.049);
   cutVC_b.clear(); cutVC_e.clear();

   vName = "hor1";
   fillWPCutVector(vName, iEt, cutVC_b, cutVC_e, pairWPCol);
   createEBEEPlot(pairFileLeg, vName + etBin, hor1_b, hor1_e, nH,
                  cutVC_b, cutVC_e, "", doNorm, -999., fName, "H/E", yLbl, true, -1, yMin, 1.999, yMin, 1.999);
   createEBEEEffPlot(pairFileLeg, vName + etBin, hor1_b, hor1_e, nH,
                     cutVC_b, cutVC_e, "", doNorm, -999., fName, "H/E", yLbl, false, 4, 0.001, 1.049, 0.001, 1.049);
   cutVC_b.clear(); cutVC_e.clear();

   vName = "ecr1";
   fillWPCutVector(vName, iEt, cutVC_b, cutVC_e, pairWPCol);
   createEBEEPlot(pairFileLeg, vName + etBin, ecr1_b, ecr1_e, nH,
                  cutVC_b, cutVC_e, "", doNorm, -999., fName, "Rel. EcalIso", yLbl, true, -1, yMin, 1.999, yMin, 1.999);
   createEBEEEffPlot(pairFileLeg, vName + etBin, ecr1_b, ecr1_e, nH,
                     cutVC_b, cutVC_e, "", doNorm, -999., fName, "Rel. EcalIso", yLbl, false, 4, 0.001, 1.049, 0.001, 1.049);
   cutVC_b.clear(); cutVC_e.clear();

   vName = "hcr1";
   fillWPCutVector(vName, iEt, cutVC_b, cutVC_e, pairWPCol);
   createEBEEPlot(pairFileLeg, vName + etBin, hcr1_b, hcr1_e, nH,
                  cutVC_b, cutVC_e, "", doNorm, -999., fName, "Rel. HcalIso", yLbl, true, -1, yMin, 1.999, yMin, 1.999);
   createEBEEEffPlot(pairFileLeg, vName + etBin, hcr1_b, hcr1_e, nH,
                     cutVC_b, cutVC_e, "", doNorm, -999., fName, "Rel. HcalIso", yLbl, false, 4, 0.001, 1.049, 0.001, 1.049);
   cutVC_b.clear(); cutVC_e.clear();

   vName = "tkr1";
   fillWPCutVector(vName, iEt, cutVC_b, cutVC_e, pairWPCol);
   createEBEEPlot(pairFileLeg, vName + etBin, tkr1_b, tkr1_e, nH,
                  cutVC_b, cutVC_e, "", doNorm, -999., fName, "Rel. TrackIso", yLbl, true, -1, yMin, 1.999, yMin, 1.999);
   createEBEEEffPlot(pairFileLeg, vName + etBin, tkr1_b, tkr1_e, nH,
                     cutVC_b, cutVC_e, "", doNorm, -999., fName, "Rel. TrackIso", yLbl, false, 4, 0.001, 1.049, 0.001, 1.049);
   cutVC_b.clear(); cutVC_e.clear();

   vName = "hor2";
   fillWPCutVector(vName, iEt, cutVC_b, cutVC_e, pairWPCol);
   createEBEEPlot(pairFileLeg, vName + etBin, hor2_b, hor2_e, nH,
                  cutVC_b, cutVC_e, "", doNorm, -999., fName, "H/E", yLbl, true, -1, yMin, 1.999, yMin, 1.999);
   createEBEEEffPlot(pairFileLeg, vName + etBin, hor2_b, hor2_e, nH,
                     cutVC_b, cutVC_e, "", doNorm, -999., fName, "H/E", yLbl, false, 4, 0.001, 1.049, 0.001, 1.049);
   cutVC_b.clear(); cutVC_e.clear();

   vName = "ecr2";
   fillWPCutVector(vName, iEt, cutVC_b, cutVC_e, pairWPCol);
   createEBEEPlot(pairFileLeg, vName + etBin, ecr2_b, ecr2_e, nH,
                  cutVC_b, cutVC_e, "", doNorm, -999., fName, "Rel. EcalIso", yLbl, true, -1, yMin, 1.999, yMin, 1.999);
   createEBEEEffPlot(pairFileLeg, vName + etBin, ecr2_b, ecr2_e, nH,
                     cutVC_b, cutVC_e, "", doNorm, -999., fName, "Rel. EcalIso", yLbl, false, 4, 0.001, 1.049, 0.001, 1.049);
   cutVC_b.clear(); cutVC_e.clear();

   vName = "hcr2";
   fillWPCutVector(vName, iEt, cutVC_b, cutVC_e, pairWPCol);
   createEBEEPlot(pairFileLeg, vName + etBin, hcr2_b, hcr2_e, nH,
                  cutVC_b, cutVC_e, "", doNorm, -999., fName, "Rel. HcalIso", yLbl, true, -1, yMin, 1.999, yMin, 1.999);
   createEBEEEffPlot(pairFileLeg, vName + etBin, hcr2_b, hcr2_e, nH,
                     cutVC_b, cutVC_e, "", doNorm, -999., fName, "Rel. HcalIso", yLbl, false, 4, 0.001, 1.049, 0.001, 1.049);
   cutVC_b.clear(); cutVC_e.clear();

   vName = "tkr2";
   fillWPCutVector(vName, iEt, cutVC_b, cutVC_e, pairWPCol);
   createEBEEPlot(pairFileLeg, vName + etBin, tkr2_b, tkr2_e, nH,
                  cutVC_b, cutVC_e, "", doNorm, -999., fName, "Rel. TrackIso", yLbl, true, -1, yMin, 1.999, yMin, 1.999);
   createEBEEEffPlot(pairFileLeg, vName + etBin, tkr2_b, tkr2_e, nH,
                     cutVC_b, cutVC_e, "", doNorm, -999., fName, "Rel. TrackIso", yLbl, false, 4, 0.001, 1.049, 0.001, 1.049);
   cutVC_b.clear(); cutVC_e.clear();

   vName = "hor3";
   fillWPCutVector(vName, iEt, cutVC_b, cutVC_e, pairWPCol);
   createEBEEPlot(pairFileLeg, vName + etBin, hor3_b, hor3_e, nH,
                  cutVC_b, cutVC_e, "", doNorm, -999., fName, "H/E", yLbl, true, -1, yMin, 1.999, yMin, 1.999);
   createEBEEEffPlot(pairFileLeg, vName + etBin, hor3_b, hor3_e, nH,
                     cutVC_b, cutVC_e, "", doNorm, -999., fName, "H/E", yLbl, false, 4, 0.001, 1.049, 0.001, 1.049);
   cutVC_b.clear(); cutVC_e.clear();

   vName = "ecr3";
   fillWPCutVector(vName, iEt, cutVC_b, cutVC_e, pairWPCol);
   createEBEEPlot(pairFileLeg, vName + etBin, ecr3_b, ecr3_e, nH,
                  cutVC_b, cutVC_e, "", doNorm, -999., fName, "Rel. EcalIso", yLbl, true, -1, yMin, 1.999, yMin, 1.999);
   createEBEEEffPlot(pairFileLeg, vName + etBin, ecr3_b, ecr3_e, nH,
                     cutVC_b, cutVC_e, "", doNorm, -999., fName, "Rel. EcalIso", yLbl, false, 4, 0.001, 1.049, 0.001, 1.049);
   cutVC_b.clear(); cutVC_e.clear();

   vName = "hcr3";
   fillWPCutVector(vName, iEt, cutVC_b, cutVC_e, pairWPCol);
   createEBEEPlot(pairFileLeg, vName + etBin, hcr3_b, hcr3_e, nH,
                  cutVC_b, cutVC_e, "", doNorm, -999., fName, "Rel. HcalIso", yLbl, true, -1, yMin, 1.999, yMin, 1.999);
   createEBEEEffPlot(pairFileLeg, vName + etBin, hcr3_b, hcr3_e, nH,
                     cutVC_b, cutVC_e, "", doNorm, -999., fName, "Rel. HcalIso", yLbl, false, 4, 0.001, 1.049, 0.001, 1.049);
   cutVC_b.clear(); cutVC_e.clear();

   vName = "tkr3";
   fillWPCutVector(vName, iEt, cutVC_b, cutVC_e, pairWPCol);
   createEBEEPlot(pairFileLeg, vName + etBin, tkr3_b, tkr3_e, nH,
                  cutVC_b, cutVC_e, "", doNorm, -999., fName, "Rel. TrackIso", yLbl, true, -1, yMin, 1.999, yMin, 1.999);
   createEBEEEffPlot(pairFileLeg, vName + etBin, tkr3_b, tkr3_e, nH,
                     cutVC_b, cutVC_e, "", doNorm, -999., fName, "Rel. TrackIso", yLbl, false, 4, 0.001, 1.049, 0.001, 1.049);
   cutVC_b.clear(); cutVC_e.clear();
   */

   gROOT->ProcessLine(".q");  
}

int main() {
  hltTune();
  return 0;
}



