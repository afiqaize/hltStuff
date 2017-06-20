// To derive the effective areas with percentile method
// Usage with ROOT6 root -l -b hltEA.cxx++

#include "TH2D.h"
#include "TProfile.h"
#include "TF1.h"
#include "TFitResult.h"

#include "hltWP.cxx"
#include "plotStuff.cxx"
#include "/home/afiqaize/root53434/macros/tdrstyle.C"

struct isoH2Pr {
  std::pair<double, double> etBin;
  std::pair<double, double> absEtaBin;
  std::pair<int, std::string> sample;
  TH2D* h2;
  TProfile* pr;
};

int findBinIndex(TH1* hist, const std::pair<double, double> xBin, const std::pair<double, double> yBin) {
  double xPnt = (xBin.first + xBin.second) / 2.;
  double yPnt = (yBin.first + yBin.second) / 2.;

  return hist->FindBin(xPnt, yPnt);
}

void hltEA() {
  gROOT->Reset();
  //setTDRStyle();
  gStyle->SetOptStat(0);
  gStyle->SetPaintTextFormat(".3f");

  // Declare the options like binning and such
  const std::string inDir = "/home/afiqaize/Downloads/EGM/dev/e_90x/wpTune_110517/skim_v1/";
  const std::string outDir = inDir + "../plot_v1/eaFit_test/";

  const std::vector<double> quantVal = {0.93, 0.95, 0.97};

  const std::vector<std::string> puVar = {"rho"};
  const std::vector<std::pair<std::string, std::string> > isoVar = {std::make_pair("hlt_hoe", "H/E"),
                                                                    std::make_pair("hlt_eca", "EcalIso"),
                                                                    std::make_pair("hlt_hca", "HcalIso"),
                                                                    std::make_pair("hlt_tks", "TrackIso")};
  //const std::vector<std::pair<std::string, std::string> > isoVar = {std::make_pair("hlt_hca", "HcalIso")};

  const std::vector<std::pair<int, std::string> > sampleType = {std::make_pair(-1, "DY #rightarrow ee")/*,
                                                                std::make_pair(-2, "DY #rightarrow ee (high E_{T})")*/};

  const std::vector<std::pair<double, double> > etBins = {std::make_pair(35., 125.)/*,
                                                          std::make_pair(60., 125.)*/};

  const std::vector<std::pair<double, double> > absEtaBins = {std::make_pair(0., 1.),
                                                              std::make_pair(1., 1.4442),
                                                              std::make_pair(1.4442, 1.566),
                                                              std::make_pair(1.566, 2.1),
                                                              std::make_pair(2.1, 2.5)};

  std::cout << std::fixed << std::setprecision(3);

  // Input and output files; branches to be read
  TFile *fOut = new TFile((outDir + "isoRho.root").c_str(), "recreate");

  TChain *t1 = new TChain("hltTree");
  t1->Add((inDir + "skim_dy.root").c_str());

  // Needed to prevent address mixing in case of looped SetBranchAddress
  TBranch *b_pu, *b_iso;

  int n, itype, genMatch[10];
  double normWgt, genWgt, et[10], eta[10], isoX[10], puX;

  t1->SetBranchAddress("hlt_n", &n);
  t1->SetBranchAddress("hlt_et", et);
  t1->SetBranchAddress("hlt_eta", eta);
  t1->SetBranchAddress("genMatch", genMatch);
  t1->SetBranchAddress("itype", &itype);
  t1->SetBranchAddress("normWgt", &normWgt);
  t1->SetBranchAddress("genWgt", &genWgt);

  for (const auto &pu : puVar) {
    t1->SetBranchAddress(pu.c_str(), &puX, &b_pu);
    for (const auto &iso : isoVar) {
      t1->SetBranchAddress(iso.first.c_str(), isoX, &b_iso);

      for (const auto &sample : sampleType) {
        std::map<std::string, isoH2Pr> m_isoHist;

        // Prepare histograms per bin
        for (const auto &etBin : etBins) {
          for (const auto &absEtaBin : absEtaBins) {

            std::string binName = iso.first + "_" + toStr(sample.first) + "_Et_" +
                                  toStr(etBin.first) + "To" + toStr(etBin.second) +
                                  "_AbsEta_" + toStr(absEtaBin.first) + "To" + toStr(absEtaBin.second);
            std::replace(binName.begin(), binName.end(), '.', 'p');
            std::replace(binName.begin(), binName.end(), '-', 'm');

            isoH2Pr isoH;
            isoH.sample = sample;
            isoH.h2 = new TH2D(("h2_" + binName).c_str(), ("h2_" + binName).c_str(), 80, 0., 40., 200, 0., 20.); // rho vs iso
            isoH.pr = new TProfile(("pr_" + binName).c_str(), ("pr_" + binName).c_str(), 80, 0., 40.);
            isoH.etBin = etBin;
            isoH.absEtaBin = absEtaBin;

            m_isoHist[binName] = isoH;

          }
        }

        // Read the tree; fill histograms
        const int nEvt0 = t1->GetEntries();
        for (int evt0 = 0; evt0 < nEvt0; evt0++) {
          t1->GetEntry(evt0);

          for (int iEle = 0; iEle < n; iEle++) {
            for (auto &isoH : m_isoHist) {
              const bool accEle = (itype == isoH.second.sample.first and genMatch[iEle] == 1 and
                                   et[iEle] >= isoH.second.etBin.first and et[iEle] <= isoH.second.etBin.second and
                                   std::abs(eta[iEle]) >= isoH.second.absEtaBin.first and std::abs(eta[iEle]) <= isoH.second.absEtaBin.second);

              if (accEle) {
                isoH.second.h2->Fill(puX, isoX[iEle], genWgt * normWgt);
                isoH.second.pr->Fill(puX, isoX[iEle], genWgt * normWgt);
              }
            }
          }
        }

        // Some translation needed to define the result histograms
        std::vector<double> etV;
        for (unsigned iEt = 0; iEt < etBins.size(); iEt++) {
          if (iEt != etBins.size() - 1)
            etV.push_back( etBins.at(iEt).first );
          else {
            etV.push_back( etBins.at(iEt).first );
            etV.push_back( etBins.at(iEt).second );
          }
        }
        std::vector<double> absEtaV;
        for (unsigned iAbsEta = 0; iAbsEta < absEtaBins.size(); iAbsEta++) {
          if (iAbsEta != absEtaBins.size() - 1)
            absEtaV.push_back( absEtaBins.at(iAbsEta).first );
          else {
            absEtaV.push_back( absEtaBins.at(iAbsEta).first );
            absEtaV.push_back( absEtaBins.at(iAbsEta).second );
          }
        }

        // Prepare the stuff needed for showing the derived effAreas
        std::string isoN1 = iso.first + "_" + toStr(sample.first);
        std::replace(isoN1.begin(), isoN1.end(), '.', 'p');
        std::replace(isoN1.begin(), isoN1.end(), '-', 'm');
        std::string isoN2 = iso.second + " " + sample.second;
        TH2D *f0p = new TH2D(("f0p_" + isoN1).c_str(), ("Prof EA " + isoN2).c_str(),
                             absEtaV.size() - 1, absEtaV.data(), etV.size() - 1, etV.data());
        TH2D *f1p = new TH2D(("f1p_" + isoN1).c_str(), ("Prof NT " + isoN2).c_str(),
                             absEtaV.size() - 1, absEtaV.data(), etV.size() - 1, etV.data());

        TF1 *linFun = new TF1("linFun", " ([0]*x + [1]) ", 12.5, 27.5);
        linFun->SetLineColor(kRed);
        linFun->SetLineWidth(2.0);

        // Perform fits for the profile effAreas and save
        for (auto &isoH : m_isoHist) {
          int fpInd = findBinIndex(f0p, isoH.second.absEtaBin, isoH.second.etBin);

          TFitResultPtr pr_fit = isoH.second.pr->Fit("linFun", "SFREMQ");
          const double prVal0 = pr_fit->Value(0), prErr0 = pr_fit->Error(0);
          const double prVal1 = pr_fit->Value(1), prErr1 = pr_fit->Error(1);

          std::cout << isoH.first << " prof effArea: " << prVal0 << " error: " << prErr0
                    << " noiTerm: " << prVal1 << " error: " << prErr1
                    << " chi2: " << pr_fit->Chi2() << " nDF: " << pr_fit->Ndf() << " chi2/nDF: " << pr_fit->Chi2() / pr_fit->Ndf()
                    << std::endl;

          f0p->SetBinContent(fpInd, prVal0);
          f0p->SetBinError(fpInd, prErr0);
          f1p->SetBinContent(fpInd, prVal1);
          f1p->SetBinError(fpInd, prErr1);

          isoH.second.pr->Write();
          //pr_fit->Write();
          isoH.second.h2->Write();
        }

        axHist(f0p, -999., -999., "E_{T} (GeV)", 0.035, 1.15, 0.031, "#left|#eta#right|", 0.037, 1.15, 0.033);
        TCanvas *c01 = new TCanvas("c01", "c01", 200, 10, 1000, 1000);
        c01->cd();
        f0p->Draw("coltexte");
        c01->SaveAs((outDir + "f0p_" + isoN1 + ".pdf").c_str());
        c01->SaveAs((outDir + "f0p_" + isoN1 + ".C").c_str());
        f0p->Write();
        delete c01;
        axHist(f1p, -999., -999., "E_{T} (GeV)", 0.035, 1.15, 0.031, "#left|#eta#right|", 0.037, 1.15, 0.033);
        TCanvas *c02 = new TCanvas("c02", "c02", 200, 10, 1000, 1000);
        c02->cd();
        f1p->Draw("coltexte");
        c02->SaveAs((outDir + "f1p_" + isoN1 + ".pdf").c_str());
        c02->SaveAs((outDir + "f1p_" + isoN1 + ".C").c_str());
        f1p->Write();
        delete c02;
        std::cout << std::endl;

        // Perform fits and save for each quantile
        for (auto &qua : quantVal) {
          std::string qStr = toStr(qua);
          std::replace(qStr.begin(), qStr.end(), '.', 'p');

          TH2D *f0q = new TH2D(("f0q" + qStr + "_" + isoN1).c_str(), ("Quan EA " + qStr + " " + isoN2).c_str(),
                               absEtaV.size() - 1, absEtaV.data(), etV.size() - 1, etV.data());
          TH2D *f1q = new TH2D(("f1q" + qStr + "_" + isoN1).c_str(), ("Quan NT " + qStr + " " + isoN2).c_str(),
                               absEtaV.size() - 1, absEtaV.data(), etV.size() - 1, etV.data());

          for (auto &isoH : m_isoHist) {
            int fqInd = findBinIndex(f0q, isoH.second.absEtaBin, isoH.second.etBin);

            // Make the quantiles through single-bin projections
            TGraph *gq = new TGraph();
            gq->SetMarkerColor(kRed);

            TH1D* hb;
            int iPnt = 0;

            for (int iRho = 0; iRho < isoH.second.h2->GetNbinsX(); iRho++) {
              hb = isoH.second.h2->ProjectionY(("hb" + qStr + "_" + toStr(iRho + 1) + "_" + isoH.first).c_str(), iRho + 1, iRho + 1, "e");
              hb->SetTitle(("hb" + qStr + "_" + toStr(iRho + 1) + "_" + isoH.first).c_str());

              // Evaluate the bin-by-bin integral and quantile
              double hbInt = hb->Integral();
              if (hbInt > 0.) {
                for (int iBin = 0; iBin < hb->GetNbinsX(); iBin++) {
                  if (hb->Integral(1, iBin + 1) / hbInt > qua) {
                    gq->SetPoint(iPnt, isoH.second.h2->ProjectionX()->GetBinCenter(iRho + 1),
                                 hb->GetBinCenter(iBin + 1));

                    //std::cout << "Point " << iPnt << " is x:" << isoH.second.h2->ProjectionX()->GetBinCenter(iRho + 1) <<
                    //  ", y:" << hb->GetBinCenter(iBin + 1) << std::endl;
                    ++iPnt;
                    break;
                  }
                }
              }
              //hb->Write();
              delete hb;
            }

            TFitResultPtr qu_fit = gq->Fit("linFun", "SFREMQ");
            const double quVal0 = qu_fit->Value(0), quErr0 = qu_fit->Error(0);
            const double quVal1 = qu_fit->Value(1), quErr1 = qu_fit->Error(1);

            std::cout << isoH.first << " quan " + toStr(qua) + " effArea: " << quVal0 << " error: " << quErr0
                      << " noiTerm: " << quVal1 << " error: " << quErr1
                      << " chi2: " << qu_fit->Chi2() << " nDF: " << qu_fit->Ndf() << " chi2/nDF: " << qu_fit->Chi2() / qu_fit->Ndf()
                      << std::endl;

            f0q->SetBinContent(fqInd, quVal0);
            f0q->SetBinError(fqInd, quErr0);
            f1q->SetBinContent(fqInd, quVal1);
            f1q->SetBinError(fqInd, quErr1);

            gq->Write(("gq" + qStr + "_" + isoH.first).c_str());
            //qu_fit->Write();
            delete gq;
          }

          axHist(f0q, -999., -999., "E_{T} (GeV)", 0.035, 1.15, 0.031, "#left|#eta#right|", 0.037, 1.15, 0.033);
          TCanvas *c03 = new TCanvas("c03", "c03", 200, 10, 1000, 1000);
          c03->cd();
          f0q->Draw("coltexte");
          c03->SaveAs((outDir + "f0q" + qStr + "_" + isoN1 + ".pdf").c_str());
          c03->SaveAs((outDir + "f0q" + qStr + "_" + isoN1 + ".C").c_str());
          f0q->Write();
          delete c03;
          axHist(f1q, -999., -999., "E_{T} (GeV)", 0.035, 1.15, 0.031, "#left|#eta#right|", 0.037, 1.15, 0.033);
          TCanvas *c04 = new TCanvas("c04", "c04", 200, 10, 1000, 1000);
          c04->cd();
          f1q->Draw("coltexte");
          c04->SaveAs((outDir + "f1q" + qStr + "_" + isoN1 + ".pdf").c_str());
          c04->SaveAs((outDir + "f1q" + qStr + "_" + isoN1 + ".C").c_str());
          f1q->Write();
          delete c04;
          std::cout << std::endl;
        }

        etV.clear();
        absEtaV.clear();
      }

      // Clear it up; otherwise some address mixing may occur
      t1->ResetBranchAddress(b_iso);
      b_iso = 0;
    }

    // Same as above
    t1->ResetBranchAddress(b_pu);
    b_pu = 0;
  }

  fOut->Close();

  gROOT->ProcessLine(".q");
}


