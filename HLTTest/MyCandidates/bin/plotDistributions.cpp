#include "DataFormats/FWLite/interface/Handle.h"
#include "DataFormats/FWLite/interface/Event.h"
#include "DataFormats/EgammaCandidates/interface/GsfElectron.h"
#include "DataFormats/EgammaReco/interface/SuperCluster.h"
#include "FWCore/FWLite/interface/AutoLibraryLoader.h"
#include "DataFormats/RecoCandidate/interface/RecoEcalCandidate.h"
#include "DataFormats/RecoCandidate/interface/RecoEcalCandidateFwd.h"
#include "DataFormats/RecoCandidate/interface/RecoEcalCandidateIsolation.h"
#include "DataFormats/EgammaCandidates/interface/Electron.h"
#include "DataFormats/EgammaCandidates/interface/ElectronIsolationAssociation.h"

#include "DataFormats/Math/interface/deltaR.h"
#include "DataFormats/Common/interface/ValueMap.h"

#include "TFile.h"
#include "TH1F.h"

#include <vector>

int main() {
  AutoLibraryLoader::enable();
  TFile file("/afs/cern.ch/user/s/sani/work/CMSSW_6_1_0/src/outputA.root");

  TH1F* eteb = new TH1F("eteb", "eteb", 100, 0, 100);
  TH1F* etpfeb = new TH1F("etpfeb", "etpfeb", 100, 0, 100);
  
  TH1F* ecaleb = new TH1F("ecaleb", "ecaleb", 60, -5, 10);
  TH1F* ecalpfeb = new TH1F("ecalpfeb", "ecalpfeb", 60, -5, 10);
  
  TH1F* sieieeb = new TH1F("sieieeb", "sieieeb", 100, 0, 0.05);
  TH1F* sieiepfeb = new TH1F("sieiepfeb", "sieiepfeb", 100, 0, 0.05);

  //TH1F* eopeb = new TH1F("eopeb", "eopeb", 100, 0, 5);
  //TH1F* eoppfeb = new TH1F("eoppfeb", "eoppfeb", 100, 0, 5);

  TH1F* detaeb = new TH1F("detaeb", "detaeb", 100, 0, 0.1);
  TH1F* detapfeb = new TH1F("detapfeb", "detapfeb", 100, 0, 0.1);

  TH1F* dphieb = new TH1F("dphieb", "dphieb", 100, 0, 0.01);
  TH1F* dphipfeb = new TH1F("dphipfeb", "dphipfeb", 100, 0, 0.01);


  TH1F* et = new TH1F("et", "et", 100, 0, 100);
  TH1F* etpf = new TH1F("etpf", "etpf", 100, 0, 100);
  
  TH1F* ecal = new TH1F("ecal", "ecal", 60, -5, 10);
  TH1F* ecalpf = new TH1F("ecalpf", "ecalpf", 60, -5, 10);
  
  TH1F* sieie = new TH1F("sieie", "sieie", 100, 0, 0.05);
  TH1F* sieiepf = new TH1F("sieiepf", "sieiepf", 100, 0, 0.05);

  //TH1F* eop = new TH1F("eop", "eop", 100, 0, 5);
  //TH1F* eoppf = new TH1F("eoppf", "eoppf", 100, 0, 5);

  TH1F* deta = new TH1F("deta", "deta", 100, 0, 0.1);
  TH1F* detapf = new TH1F("detapf", "detapf", 100, 0, 0.1);

  TH1F* dphi = new TH1F("dphi", "dphi", 100, 0, 0.01);
  TH1F* dphipf = new TH1F("dphipf", "dphipf", 100, 0, 0.01);

  fwlite::Event ev(&file);
  
  for (ev.toBegin(); ! ev.atEnd(); ++ev) {
    edm::EventBase const & event = ev;
    
    edm::Handle<std::vector<reco::Electron> > eH;
    // event.getByLabel( edm::InputTag("hltEl27WP80PixelMatchElectronsL1Seeded::TEST"), eH);

    edm::Handle<std::vector<reco::RecoEcalCandidate> > cH;
    event.getByLabel( edm::InputTag("hltL1SeededRecoEcalCandidate"), cH);

    edm::Handle<reco::RecoEcalCandidateIsolationMap> sieieMapH;
    const reco::RecoEcalCandidateIsolationMap* sieieMap = 0;
    event.getByLabel(edm::InputTag("hltL1SeededHLTClusterShape"), sieieMapH);
    if (!sieieMapH.failedToGet())
      sieieMap = sieieMapH.product();

    //edm::Handle<reco::RecoEcalCandidateIsolationMap> ecalMapH;
    //const reco::RecoEcalCandidateIsolationMap* ecalMap = 0;
    //event.getByLabel(edm::InputTag("hltL1SeededPhotonEcalIso::TEST"), ecalMapH);
    //if (!ecalMapH.failedToGet())
    //  ecalMap = ecalMapH.product();

    //edm::Handle<reco::RecoEcalCIsolationMap> eopMapH;
    //const reco::RecoEcalCandidateIsolationMap* eopMap = 0;
    //event.getByLabel(edm::InputTag(""), eopMapH);
    //if (!eopMapH.failedToGet())
    //  eopMap = sieieMapH.product();

    //edm::Handle<reco::ElectronIsolationMap> detaMapH;
    //const reco::ElectronIsolationMap* detaMap = 0;
    //event.getByLabel(edm::InputTag("hltEle27WP80L1SeededDetaDphi:Deta"), detaMapH);
    //if (!detaMapH.failedToGet())
    //  detaMap = detaMapH.product();

    //edm::Handle<reco::ElectronIsolationMap> dphiMapH;
    //const reco::ElectronIsolationMap* dphiMap = 0;
    //event.getByLabel(edm::InputTag("hltEle27WP80L1SeededDetaDphi:Dphi"), dphiMapH);
    //if (!dphiMapH.failedToGet())
    //  dphiMap = dphiMapH.product();

    for (unsigned int i=0; i<cH->size(); i++) {
      reco::RecoEcalCandidateRef c(cH, i);

      if (fabs(c->eta()) < 1.479) {
	eteb->Fill(c->energy()*sin(c->theta()));
	std::cout << sieieMap << std::endl;
	if (sieieMap != 0) {
	  std::cout << (*sieieMap)[c] << std::endl;
	  sieieeb->Fill((*sieieMap)[c]);
	}
	std::cout << "42" << std::endl;
	//if (ecalMap != 0)
	//  ecaleb->Fill((*ecalMap)[c]);
	std::cout << "43" << std::endl;
      } else {
	et->Fill(c->superCluster()->energy()*sin(c->theta()));
	if (sieieMap != 0)
	  sieie->Fill((*sieieMap)[c]);
	std::cout << "43" << std::endl;
	//if (ecalMap != 0)
	//  ecal->Fill((*ecalMap)[c]);
	std::cout << "44" << std::endl;
      }
    }
    /*
    std::cout << "42" << std::endl;
    for (unsigned int i=0; i<eH->size(); i++) {
      reco::ElectronRef e(eH, i);
      
      if (fabs(e->eta())<1.479) {
	//if (eopMap != 0)
	//  eopeb->Fill((*eopMap)[e]);
	
	if (detaMap != 0)
	  detaeb->Fill((*detaMap)[e]);
	
	if (dphiMap != 0)
	  dphieb->Fill((*dphiMap)[e]);
	
      }  else {
	if (detaMap != 0)
	  deta->Fill((*detaMap)[e]);
	
	if (dphiMap != 0)
	  dphi->Fill((*dphiMap)[e]);
      }
    }

    std::cout << "5" << std::endl;
    event.getByLabel( edm::InputTag("hltEl27WP80PixelMatchElectronsL1SeededPF"), eH);
    event.getByLabel( edm::InputTag("hltL1SeededRecoEcalCandidatePF"), cH);
    
    const reco::RecoEcalCandidateIsolationMap* sieieMapPF = 0;
    event.getByLabel(edm::InputTag("hltL1SeededHLTClusterShapePF"), sieieMapH);
    if (!sieieMapH.failedToGet())
      sieieMapPF = sieieMapH.product();

    const reco::RecoEcalCandidateIsolationMap* ecalMapPF = 0;
    event.getByLabel(edm::InputTag("hltL1SeededPhotonEcalIsoPF"), ecalMapH);
    if (!ecalMapH.failedToGet())
      ecalMapPF = ecalMapH.product();
    std::cout << "6" << std::endl;
    //edm::Handle<reco::RecoEcalCIsolationMap> eopMapH;
    //const reco::RecoEcalCandidateIsolationMap* eopMap = 0;
    //event.getByLabel(edm::InputTag(""), eopMapH);
    //if (!eopMapH.failedToGet())
    //  eopMap = sieieMapH.product();

    const reco::ElectronIsolationMap* detaMapPF = 0;
    event.getByLabel(edm::InputTag("hltEle27WP80L1SeededDetaDphiPF:Deta"), detaMapH);
    if (!detaMapH.failedToGet())
      detaMapPF = detaMapH.product();

    const reco::ElectronIsolationMap* dphiMapPF = 0;
    event.getByLabel(edm::InputTag("hltEle27WP80L1SeededDetaDphiPF:Dphi"), dphiMapH);
    if (!dphiMapH.failedToGet())
      dphiMapPF = dphiMapH.product();
    std::cout << "7" << std::endl;
    for (unsigned int i=0; i<cH->size(); i++) {
      reco::RecoEcalCandidateRef c(cH, i);
      if (fabs(c->eta()) < 1.479) {
	etpfeb->Fill(c->superCluster()->energy()*sin(c->theta()));
	if (sieieMapPF != 0)
	  sieiepfeb->Fill((*sieieMapPF)[c]);
	
	if (ecalMapPF != 0)
	  ecalpfeb->Fill((*ecalMapPF)[c]);
      } else {
	etpf->Fill(c->superCluster()->energy()*sin(c->theta()));
	if (sieieMapPF != 0)
	  sieiepf->Fill((*sieieMapPF)[c]);
	
	if (ecalMapPF != 0)
	  ecalpf->Fill((*ecalMapPF)[c]);
      }
    }
    
    for (unsigned int i=0; i<eH->size(); i++) {
      reco::ElectronRef e(eH, i);
      
      if (fabs(e->eta())<1.479) {
	//if (eopMap != 0)
	//  eopeb->Fill((*eopMap)[e]);
	
	if (detaMapPF != 0)
	  detapfeb->Fill((*detaMapPF)[e]);
	
	if (dphiMapPF != 0)
	  dphipfeb->Fill((*dphiMapPF)[e]);
	
      }  else {
	if (detaMapPF != 0)
	  detapf->Fill((*detaMapPF)[e]);
	
	if (dphiMapPF != 0)
	  dphipf->Fill((*dphiMapPF)[e]);
      }
    }
    */
  }

  TFile* output = new TFile("output.root", "recreate");
  et->Write();
  sieie->Write();
  ecal->Write();
  deta->Write();
  dphi->Write();
  etpf->Write();
  sieiepf->Write();
  ecalpf->Write();
  detapf->Write();
  dphipf->Write();

  eteb->Write();
  sieieeb->Write();
  ecaleb->Write();
  detaeb->Write();
  dphieb->Write();
  etpfeb->Write();
  sieiepfeb->Write();
  ecalpfeb->Write();
  detapfeb->Write();
  dphipfeb->Write();
  
  output->Close();
  

  return 0;

}

