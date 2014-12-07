// Tool to calculate the rates
// Run in ROOT: .L rateCalc.cxx, then main();
// Datasets as specified in Andrey's mail
// Careful, this assumes running over entire dataset (total event from DAS)  and no bad jobs

#include <TMath.h>
#include <iostream>
#include <TString.h>

using namespace std;

void rateCalc(TString proc, Double_t pasEvt) {

  Double_t xsec = 0.; // takes the value in pb
  Double_t totEvt = 0.; // total #evt processed
  Double_t cmConv = 1.e-36; // factor from pb to cm, 1e-36
  
  if (proc == "qcd30") {

    xsec = 161500000. * cmConv;
    totEvt = 2978932.;

  }

  else if (proc == "qcd50") {

    xsec = 22110000. * cmConv;
    totEvt = 3001228.;

  }

  else if (proc == "qcd80") {

    xsec = 3000114.3 * cmConv;
    totEvt = 3000513.;

  }

  else if (proc == "qcd120") {

    xsec = 493200. * cmConv;
    totEvt = 2928546.;

  }

  else if (proc == "wev") {

    xsec = 16000. * cmConv;
    totEvt = 99280.;

  }

  else if (proc == "wmv") {

    xsec = 16100. * cmConv;
    totEvt = 100000.;

  }

  else if (proc == "dyll") {

    xsec = 6960. * cmConv; // direct xsec
    totEvt = 2828296.;

  }

  // fill in the xsec for these

  else if (proc == "tt") {

    xsec = 806. * cmConv; // from Andrey
    totEvt = 2735769.;

  }

  else if (proc == "tchan") {

    xsec = 210. * cmConv; // from Andrey
    totEvt = 499800.;

  }

  else {

    cout << "Process requested is not supported at the moment. Sorry." << std::endl;

  }

  Double_t nfillb = 2662., mfillb = 3564.; // filled and max bunch
  Double_t xtime = 25.e-9; // 25 ns bunch crossing
  Double_t ilumi = 1.4e34; // instantenous lumi

  Double_t collRate = (nfillb / mfillb) / xtime;

  Double_t rate = 0., err = 0.;

  rate = collRate * (1. - TMath::Exp(-1. * (xsec * ilumi * pasEvt / totEvt) / collRate));
  err = xsec * ilumi * (TMath::Sqrt(pasEvt + (pasEvt * pasEvt / totEvt)) / totEvt);

  std::cout << "The rate for the process " << proc << " is " << rate << " +- " << err << std::endl;

}

Int_t main() {

  std::cout << "All, 27 GeV:" << std::endl;

  rateCalc("wev", 35103.);
  rateCalc("tchan", 146236.);
  rateCalc("tt", 633049.);
  rateCalc("dyll", 608243.);
  rateCalc("qcd30", 13935.);
  rateCalc("qcd50", 50046.);
  rateCalc("qcd80", 84280.);
  rateCalc("qcd120", 145571.);

  std::cout << std::endl;

  std::cout << "All, 30 GeV" << std::endl;

  rateCalc("wev", 31736.);
  rateCalc("tchan", 136730.);
  rateCalc("tt", 604098.);
  rateCalc("dyll", 560850.);
  rateCalc("qcd30", 9310.);
  rateCalc("qcd50", 42127.);
  rateCalc("qcd80", 79488.);
  rateCalc("qcd120", 142003.);

  std::cout << std::endl;

  std::cout << "All, 32 GeV" << std::endl;

  rateCalc("wev", 29197.);
  rateCalc("tchan", 130368.);
  rateCalc("tt", 585501.);
  rateCalc("dyll", 529823.);
  rateCalc("qcd30", 7089.);
  rateCalc("qcd50", 37414.);
  rateCalc("qcd80", 76596.);
  rateCalc("qcd120", 139971.);

  std::cout << std::endl;

  std::cout << "Barrel, 27 GeV" << std::endl;

  rateCalc("wev", 25409.);
  rateCalc("tchan", 115510.);
  rateCalc("tt", 520797.);
  rateCalc("dyll", 462675.);
  rateCalc("qcd30", 9098.);
  rateCalc("qcd50", 29794.);
  rateCalc("qcd80", 50570.);
  rateCalc("qcd120", 97316.);

  std::cout << std::endl;

  std::cout << "Barrel, 30 GeV" << std::endl;

  rateCalc("wev", 23114.);
  rateCalc("tchan", 108213.);
  rateCalc("tt", 498439.);
  rateCalc("dyll", 425993.);
  rateCalc("qcd30", 6142.);
  rateCalc("qcd50", 25400.);
  rateCalc("qcd80", 47799.);
  rateCalc("qcd120", 95067.);

  std::cout << std::endl;

  std::cout << "Barrel, 32 GeV" << std::endl;

  rateCalc("wev", 21365.);
  rateCalc("tchan", 103262.);
  rateCalc("tt", 483892.);
  rateCalc("dyll", 401490.);
  rateCalc("qcd30", 4709.);
  rateCalc("qcd50", 22676.);
  rateCalc("qcd80", 46108.);
  rateCalc("qcd120", 93818.);

  return 0;

}

