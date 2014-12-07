// -*- C++ -*-
//
// Package:    MyCandidates
// Class:      MyCandidates
//
// Original Author:  Matteo Sani,40 3-A02,+41227671577,
//         Created:  Thu Feb 14 14:06:52 CET 2013
// $Id$
//
//


#include <memory>

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "HLTrigger/HLTcore/interface/HLTConfigProvider.h"
#include "DataFormats/HLTReco/interface/TriggerEvent.h"
#include "DataFormats/HLTReco/interface/TriggerObject.h"
#include "DataFormats/Common/interface/TriggerResults.h"

#include "DataFormats/EgammaCandidates/interface/GsfElectron.h"
#include "DataFormats/EgammaCandidates/interface/GsfElectronFwd.h"

#include "DataFormats/EgammaCandidates/interface/Photon.h"
#include "DataFormats/EgammaCandidates/interface/PhotonFwd.h"

#include "DataFormats/EgammaCandidates/interface/Electron.h"
#include "DataFormats/EgammaCandidates/interface/ElectronFwd.h"
#include "DataFormats/EgammaCandidates/interface/ElectronIsolationAssociation.h"
#include "RecoEgamma/EgammaIsolationAlgos/interface/EgammaHcalIsolation.h"
#include "RecoEgamma/EgammaHLTAlgos/interface/EgammaHLTHcalIsolation.h"
#include "RecoEgamma/EgammaIsolationAlgos/interface/ElectronTkIsolation.h"
#include "RecoEgamma/EgammaIsolationAlgos/interface/EgammaRecHitIsolation.h"
#include "RecoLocalCalo/EcalRecAlgos/interface/EcalSeverityLevelAlgoRcd.h"

#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"

#include "RecoLocalCalo/HcalRecAlgos/interface/HcalSeverityLevelComputer.h"
#include "RecoLocalCalo/HcalRecAlgos/interface/HcalSeverityLevelComputerRcd.h"
#include "CondFormats/HcalObjects/interface/HcalChannelQuality.h"
#include "CondFormats/DataRecord/interface/HcalChannelQualityRcd.h"

#include "Geometry/Records/interface/CaloGeometryRecord.h"

#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/GsfTrackReco/interface/GsfTrack.h"
#include "DataFormats/TrackReco/interface/HitPattern.h"

#include "HLTrigger/HLTcore/interface/HLTFilter.h"
#include "HLTrigger/HLTcore/interface/HLTConfigProvider.h"
#include "FWCore/Common/interface/TriggerNames.h"
#include "DataFormats/HLTReco/interface/TriggerTypeDefs.h"
#include "DataFormats/HLTReco/interface/TriggerEventWithRefs.h"
#include "DataFormats/RecoCandidate/interface/RecoEcalCandidate.h"
#include "DataFormats/RecoCandidate/interface/RecoEcalCandidateFwd.h"
#include "DataFormats/RecoCandidate/interface/RecoEcalCandidateIsolation.h"

#include "DataFormats/HepMCCandidate/interface/GenParticle.h"

#include "DataFormats/Math/interface/deltaR.h"
#include "DataFormats/Common/interface/ValueMap.h"

#include "TLorentzVector.h"
#include "TFile.h"
#include "TTree.h"

#include <string>
#include <iostream>

class plotDistr : public edm::EDAnalyzer {
public:
  explicit plotDistr(const edm::ParameterSet&);
  ~plotDistr();
  
  static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);
  int findEleRef(reco::RecoEcalCandidateRef ref, edm::Handle<reco::ElectronCollection> hltEleH);
  void mcTruth(edm::Handle<reco::GenParticleCollection> genParticleH);

private:
  virtual void beginRun(const edm::Run& run,const edm::EventSetup& setup);
  virtual void beginJob() ;
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void endJob() ;

  edm::InputTag trigResultsTag_;
  HLTConfigProvider hltConfig_; 
  std::vector<std::string> pathNames_;

  std::string outputFileName;
  TFile* f;
  TTree* t;
  
  Float_t rho;
  Int_t passSel;
  Int_t n, npf, gp_n, reco_n, nuns;
  Float_t etawidth[10], phiwidth[10];
  Float_t etawidthpf[10], phiwidthpf[10];
  Float_t eraw[10];
  Float_t e[10];
  Float_t et[10];
  Float_t se[10];
  Float_t erawpf[10];
  Float_t epf[10];  
  Float_t eoppf[10];  
  Float_t etpf[10];  
  Float_t sepf[10];  
  Float_t eta[10];
  Float_t etapf[10];  
  Float_t euns[20];
  Float_t etuns[20];
  Float_t etauns[20];  
  Float_t seta[10];
  Float_t setapf[10];  
  Float_t phi[10];
  Float_t phipf[10];  
  Float_t phiuns[20];  
  Float_t sphi[10];
  Float_t sphipf[10];  
  Float_t ecal[10];
  Float_t ecalpf[10];
  Float_t sieie[10];
  Float_t sieiepf[10];
  //Float_t eop[10];
  //Float_t eoppf[10];
  Float_t deta[10];
  Float_t detapf[10];
  Float_t detaseedpf[10];
  Float_t dphi[10];
  Float_t dphipf[10];
  Float_t tkptpf[10];
  Float_t tketapf[10];
  Float_t tkphipf[10];
  Float_t tkpt[10];
  Float_t tketa[10];
  Float_t tkphi[10];
  Float_t hoe[10];
  Float_t hcal[10];
  Float_t tkiso[10];
  Float_t hoepf[10];
  Float_t hcalpf[10];
  Float_t tkisopf[10];
  Float_t chiso[10];
  Float_t phiso[10];
  Float_t neiso[10];
  Float_t chi2pf[10];
  Int_t mishitspf[10];
  Int_t hitspf[10];

  Float_t gp_pt[10];
  Float_t gp_eta[10];
  Float_t gp_phi[10];

  Float_t reco_et[10];
  Float_t reco_pt[10];
  Float_t reco_eta[10];
  Float_t reco_phi[10];

  Int_t nvtx;

  bool isData;
  bool saveReco;
  bool saveUnseeded;
  bool newClustering;
  bool oldClustering;
};

void plotDistr::beginRun(const edm::Run& run,const edm::EventSetup& setup) {
  std::cout <<"begining run "<<std::endl;
  bool changed = false;
  hltConfig_.init(run,setup,trigResultsTag_.process(),changed); //as we need the orginal HLT config...
  std::cout <<"table name "<<hltConfig_.tableName()<<std::endl;
}


plotDistr::plotDistr(const edm::ParameterSet& iConfig) {
  outputFileName  = iConfig.getParameter<std::string>("OutputFileName");
  isData          = iConfig.getParameter<bool>("isData");
  newClustering   = iConfig.getParameter<bool>("activateNewClustering");
  oldClustering   = iConfig.getParameter<bool>("activateOldClustering");
  saveReco        = iConfig.getParameter<bool>("saveReco");
  saveUnseeded    = iConfig.getParameter<bool>("saveUnseeded");
  pathNames_      = iConfig.getParameter<std::vector<std::string>>("trgSelection");
  trigResultsTag_ = iConfig.getParameter<edm::InputTag>("trgResults");
}

plotDistr::~plotDistr() 
{}

int plotDistr::findEleRef(reco::RecoEcalCandidateRef ref, edm::Handle<reco::ElectronCollection> hltEleH) {

  int index = -1;
  for (unsigned int i=0; i<hltEleH->size(); i++) {
    reco::ElectronRef cand(hltEleH, i);
    if (cand->superCluster() == ref->superCluster()) 
      return i;
  }

  return index;
}

void plotDistr::mcTruth(edm::Handle<reco::GenParticleCollection> gpH) {
  
  gp_n = 0;
  
  for(size_t i = 0; i < gpH->size(); ++i) {
    
    const reco::GenParticleRef gp(gpH, i);
    
    if (gp->status() == 3 and abs(gp->pdgId()) == 11) {
      if (gp->pt() > 0.) {
	gp_pt[gp_n]  = gp->pt();
	gp_eta[gp_n] = gp->eta();
	gp_phi[gp_n] = gp->phi();
	gp_n++;
      }
    }
  }
}

void plotDistr::analyze(const edm::Event& event, const edm::EventSetup& iSetup) {
  edm::Handle<edm::TriggerResults> trigResultsHandle;
  event.getByLabel(trigResultsTag_,trigResultsHandle);

  const edm::TriggerResults& trigResults = *trigResultsHandle;
  const edm::TriggerNames& trigNames = event.triggerNames(trigResults);  

  passSel = 0; 
  for(size_t pathNr=0;pathNr<pathNames_.size();pathNr++){
    size_t pathIndex = trigNames.triggerIndex(pathNames_[pathNr]);
    if(pathIndex<trigResults.size() &&  trigResults.accept(pathIndex)) 
      passSel = 1;
  }

  edm::Handle<reco::GenParticleCollection> gpH;
  if (!isData) {
    event.getByLabel("genParticles", gpH);
    mcTruth(gpH);
  }

  edm::Handle<std::vector<reco::Electron> > eH;
  edm::Handle<std::vector<reco::RecoEcalCandidate> > cH;
  edm::Handle<reco::RecoEcalCandidateIsolationMap> sieieMapH;
  edm::Handle<reco::RecoEcalCandidateIsolationMap> ecalMapH;
  edm::Handle<reco::RecoEcalCandidateIsolationMap> hcalMapH;
  edm::Handle<reco::RecoEcalCandidateIsolationMap> hoeMapH;
  edm::Handle<reco::RecoEcalCandidateIsolationMap> tkisoMapH;
  edm::Handle<reco::RecoEcalCandidateIsolationMap> detaMapH;
  edm::Handle<reco::RecoEcalCandidateIsolationMap> dphiMapH;
  edm::Handle<reco::RecoEcalCandidateIsolationMap> eopMapH;
  edm::Handle<reco::RecoEcalCandidateIsolationMap> mishitsMapH;
  edm::Handle<reco::RecoEcalCandidateIsolationMap> chi2MapH;
  edm::Handle<reco::RecoEcalCandidateIsolationMap> hitsMapH;
  edm::Handle<reco::VertexCollection> vtxH;

  if (saveUnseeded) {
    event.getByLabel(edm::InputTag("hltEgammaCandidatesUnseeded"), cH);

    nuns = 0;
    if (!cH.failedToGet()) {

      for (unsigned int i=0; i<cH->size(); i++) {
	if (nuns == 20)
	  continue;
	euns[nuns] = 9999.;
	etuns[nuns] = 9999.;   
	etauns[nuns] = 9999.;
	phiuns[nuns] = 9999.;
	
	reco::RecoEcalCandidateRef c(cH, i);
	euns[nuns] = c->energy();
	etuns[nuns] = c->energy()*sin(c->theta());
	etauns[nuns] = c->eta();
	phiuns[nuns] = c->phi();
	nuns++;
      }      
    }
  }

  if (saveReco) {
    edm::Handle<std::vector<reco::GsfElectron> > elH;
    event.getByLabel("gsfElectrons", elH);
    reco_n = 0;
    for (unsigned int i=0; i<elH->size(); i++) {
      if (reco_n == 9)
	continue;
      reco_et[reco_n] = 9999.;
      reco_eta[reco_n] = 9999.;
      reco_phi[reco_n] = 9999.;
      reco_pt[reco_n] = 9999.;
      
      reco::GsfElectronRef el(elH, i);
      reco_et[reco_n] = el->superCluster()->energy()*sin(el->superCluster()->position().theta());
      reco_pt[reco_n] = el->pt();
      reco_eta[reco_n] = el->superCluster()->eta();
      reco_phi[reco_n] = el->superCluster()->phi();
      reco_n++;
    }
  }

  //if (!isData) {
  event.getByLabel(edm::InputTag("hltPixelVertices"), vtxH);
  if (!vtxH.failedToGet())
    nvtx = vtxH->size();
  else
    nvtx = 0;

  edm::Handle<double> rhoH;
  event.getByLabel(edm::InputTag("hltFixedGridRhoFastjetAllCaloForMuons"), rhoH);
  if (!rhoH.failedToGet())
    rho = *(rhoH.product());
  else
    rho = 9999.;

  //} else 
  //nvtx = 0;

//  if (oldClustering) {
//    event.getByLabel( edm::InputTag("hltEleAnyWP80PixelMatchElectronsL1Seeded"), eH);   
//    event.getByLabel( edm::InputTag("hltL1SeededRecoEcalCandidate"), cH);
//    
//    const reco::RecoEcalCandidateIsolationMap* sieieMap = 0;
//    event.getByLabel(edm::InputTag("hltL1SeededHLTClusterShape"), sieieMapH);
//    if (!sieieMapH.failedToGet())
//      sieieMap = sieieMapH.product();
//    
//    const reco::RecoEcalCandidateIsolationMap* ecalMap = 0;
//    event.getByLabel(edm::InputTag("hltL1SeededPhotonEcalIso"), ecalMapH);
//    if (!ecalMapH.failedToGet()) 
//      ecalMap = ecalMapH.product(); 
//    
//    const reco::RecoEcalCandidateIsolationMap* hcalMap = 0;
//    event.getByLabel(edm::InputTag("hltL1SeededPhotonHcalIso"), hcalMapH);
//    if (!hcalMapH.failedToGet()) 
//      hcalMap = hcalMapH.product(); 
//    
//    const reco::RecoEcalCandidateIsolationMap* hoeMap = 0;
//    event.getByLabel(edm::InputTag("hltL1SeededPhotonHcalForHE"), hoeMapH);
//    if (!hoeMapH.failedToGet()) 
//      hoeMap = hoeMapH.product(); 
//    
//    const reco::ElectronIsolationMap* tkisoMap = 0;
//    event.getByLabel(edm::InputTag("hltEleAnyWP80L1SeededElectronTrackIso"), tkisoMapH);
//    if (!tkisoMapH.failedToGet())
//      tkisoMap = tkisoMapH.product();          
//    
//    const reco::ElectronIsolationMap* detaMap = 0;
//    event.getByLabel(edm::InputTag("hltEleAnyWP80L1SeededDetaDphi:Deta"), detaMapH);
//    if (!detaMapH.failedToGet())
//      detaMap = detaMapH.product();          
//    
//    const reco::ElectronIsolationMap* dphiMap = 0;
//    event.getByLabel(edm::InputTag("hltEleAnyWP80L1SeededDetaDphi:Dphi"), dphiMapH);
//    if (!dphiMapH.failedToGet())
//      dphiMap = dphiMapH.product();
//        
//    n = 0;
//    for (unsigned int i=0; i<cH->size(); i++) {
//      if (n == 9)
//	continue;
//      
//      etawidth[n] = 9999.;
//      phiwidth[n] = 9999.;
//      e[n] = 9999.;
//      et[n] = 9999.;
//      se[n] = 9999.;
//      eraw[n] = 9999.;
//      eta[n] = 9999.;
//      phi[n] = 9999.;
//      seta[n] = 9999.;
//      sphi[n] = 9999.;
//      sieie[n] = 9999.;
//      ecal[n] = 9999;
//      deta[n] = 9999.;
//      dphi[n] = 9999.;
//      tkpt[n] = 9999.;
//      tketa[n] = 9999.;
//      tkphi[n] = 9999.;
//      hcal[n] = 9999.;
//      hoe[n] = 9999.;
//      tkiso[n] = 9999.;
//      
//      reco::RecoEcalCandidateRef c(cH, i);
//      //std::cout << c->eta() << " " <<  c->phi() << " " << c->et() << std::endl;
//      //if (c->energy()*sin(c->theta()) < 20.)
//      //  continue;
//      eraw[n] = c->superCluster()->rawEnergy();
//      e[n] = c->energy();//*sin(c->theta());
//      et[n] = c->energy()*sin(c->theta());
//      se[n] = c->superCluster()->seed()->energy();//*sin(c->theta());
//      eta[n] = c->eta();
//      phi[n] = c->phi();
//      seta[n] = c->superCluster()->seed()->eta();
//      sphi[n] = c->superCluster()->seed()->phi();
//      etawidth[n] = c->superCluster()->etaWidth();
//      phiwidth[n] = c->superCluster()->phiWidth();
//      
//      if (sieieMap != 0)
//	sieie[n] = (*sieieMap)[c];
//      
//      if (ecalMap != 0) 
//	ecal[n] = (*ecalMap)[c]; 
//      
//      if (hoeMap != 0) 
//	hoe[n] = (*hoeMap)[c]; 
//      
//      if (hcalMap != 0) 
//	hcal[n] = (*hcalMap)[c]; 
//      
//      if (!eH.failedToGet()) {
//	int index  = findEleRef(c, eH);
//	if (index != -1) {
//	  reco::ElectronRef e(eH, index);
//	  
//	  tkpt[n] = e->track()->pt();
//	  tketa[n] = e->track()->eta();	
//	  tkphi[n] = e->track()->phi();
//	  
//	  if (detaMap != 0) {
//	    deta[n] = ((*detaMap)[e]);
//	  }
//	  
//	  if (dphiMap != 0)
//	    dphi[n] = fabs((*dphiMap)[e]);
//
//	  if (tkisoMap != 0)
//	    tkiso[n] = ((*tkisoMap)[e]);
//	}
//      }
//      n++;
//    }
//  }

  if (newClustering) {
    event.getByLabel( edm::InputTag("hltEgammaCandidates"), cH);
    
    npf = 0;
    if (!cH.failedToGet()) {
    
      const reco::RecoEcalCandidateIsolationMap* sieieMapPF = 0;
      event.getByLabel(edm::InputTag("hltEgammaClusterShape"), sieieMapH);
      if (!sieieMapH.failedToGet())  
	sieieMapPF = sieieMapH.product();
      
      const reco::RecoEcalCandidateIsolationMap* ecalMapPF = 0;
      event.getByLabel(edm::InputTag("hltEgammaEcalPFClusterIso"), ecalMapH);
      if (!ecalMapH.failedToGet()) 
	ecalMapPF = ecalMapH.product(); 
      
      const reco::RecoEcalCandidateIsolationMap* hcalMapPF  = 0;
      event.getByLabel(edm::InputTag("hltEgammaHcalPFClusterIso"), hcalMapH);
      if (!hcalMapH.failedToGet()) 
	hcalMapPF = hcalMapH.product(); 
      
      const reco::RecoEcalCandidateIsolationMap* hoeMapPF = 0;
      event.getByLabel(edm::InputTag("hltEgammaHoverE"), hoeMapH);
      if (!hoeMapH.failedToGet()) 
	hoeMapPF = hoeMapH.product(); 
      
      const reco::RecoEcalCandidateIsolationMap* tkisoMapPF = 0;
      event.getByLabel(edm::InputTag("hltEgammaEleGsfTrackIso"), tkisoMapH);
      if (!tkisoMapH.failedToGet())
	tkisoMapPF = tkisoMapH.product();          
      
      const reco::RecoEcalCandidateIsolationMap* detaMapPF = 0;
      event.getByLabel(edm::InputTag("hltEgammaGsfTrackVars:Deta"), detaMapH);
      if (!detaMapH.failedToGet())
	detaMapPF = detaMapH.product();

      const reco::RecoEcalCandidateIsolationMap* detaSeedMapPF = 0;
      event.getByLabel(edm::InputTag("hltEgammaGsfTrackVars:DetaSeed"), detaMapH);
      if (!detaMapH.failedToGet())
	detaSeedMapPF = detaMapH.product();
      
      const reco::RecoEcalCandidateIsolationMap* dphiMapPF = 0;
      event.getByLabel(edm::InputTag("hltEgammaGsfTrackVars:Dphi"), dphiMapH);
      if (!dphiMapH.failedToGet()) 
	dphiMapPF = dphiMapH.product();
      
      const reco::RecoEcalCandidateIsolationMap* eopMapPF = 0;
      event.getByLabel(edm::InputTag("hltEgammaGsfTrackVars:OneOESuperMinusOneOP"), eopMapH);
      if (!eopMapH.failedToGet()) 
	eopMapPF = eopMapH.product();

      const reco::RecoEcalCandidateIsolationMap* chi2MapPF = 0;
      event.getByLabel(edm::InputTag("hltEgammaGsfTrackVars:Chi2"), chi2MapH);
      if (!chi2MapH.failedToGet()) 
	chi2MapPF = chi2MapH.product();

      const reco::RecoEcalCandidateIsolationMap* mishitsMapPF = 0;
      event.getByLabel(edm::InputTag("hltEgammaGsfTrackVars:MissingHits"), mishitsMapH);
      if (!mishitsMapH.failedToGet()) 
	mishitsMapPF = mishitsMapH.product();

      const reco::RecoEcalCandidateIsolationMap* hitsMapPF = 0;
      event.getByLabel(edm::InputTag("hltEgammaGsfTrackVars:ValidHits"), hitsMapH);
      if (!hitsMapH.failedToGet()) 
	hitsMapPF = hitsMapH.product();
      
      for (unsigned int i=0; i<cH->size(); i++) {
	if (npf == 9)
	  continue;
	etawidthpf[npf] = 9999.;
	phiwidthpf[npf] = 9999.;
	epf[npf] = 9999.;
	eoppf[npf] = 9999.;
	etpf[npf] = 9999.;
	sepf[npf] = 9999.;
	erawpf[npf] = 9999.;
	etapf[npf] = 9999.;
	phipf[npf] = 9999.;
	setapf[npf] = 9999.;
	sphipf[npf] = 9999.;
	sieiepf[npf] = 9999.;
	ecalpf[npf] = 9999;
	detapf[npf] = 9999.;
	detaseedpf[npf] = 9999.;
	dphipf[npf] = 9999.;
	tkptpf[npf] = 9999.;
	tketapf[npf] = 9999.;
	tkphipf[npf] = 9999.;
	hcalpf[npf] = 9999.;
	hoepf[npf] = 9999.;
	tkisopf[npf] = 9999.;
	mishitspf[npf] = 9999.;
	chi2pf[npf] = 9999.;
	hitspf[npf] = 9999.;

	reco::RecoEcalCandidateRef c(cH, i);
	//std::cout << c->eta() << " " <<  c->phi() << " " << c->et() << std::endl;
	//if (c->energy()*sin(c->theta()) < 20.)
	//  continue;
	
	//erawpf[npf] = c->superCluster()->rawEnergy();
	//etawidthpf[npf] = c->superCluster()->etaWidth();
	//phiwidthpf[npf] = c->superCluster()->phiWidth();
	epf[npf] = c->energy();//*sin(c->theta());
	etpf[npf] = c->energy()*sin(c->theta());
	//sepf[npf] = c->superCluster()->seed()->energy();//*sin(c->theta());
	etapf[npf] = c->eta();
	phipf[npf] = c->phi();
	//setapf[npf] = c->superCluster()->seed()->eta();
	//sphipf[npf] = c->superCluster()->seed()->phi();
	if (sieieMapPF != 0)
	  sieiepf[npf] = (*sieieMapPF)[c];
	if (ecalMapPF != 0)
	  ecalpf[npf] = (*ecalMapPF)[c]; 
	
	if (hoeMapPF != 0) 
	  hoepf[npf] = (*hoeMapPF)[c]; 
	
	if (hcalMapPF != 0) 
	  hcalpf[npf] = (*hcalMapPF)[c]; 
	
	if (detaMapPF != 0)
	  detapf[npf] = ((*detaMapPF)[c]);

	if (detaSeedMapPF != 0)
	  detaseedpf[npf] = ((*detaSeedMapPF)[c]);
	
	if (dphiMapPF != 0)
	  dphipf[npf] = fabs((*dphiMapPF)[c]);
	
	if (eopMapPF != 0)
	  eoppf[npf] = fabs((*eopMapPF)[c]);
	
	if (mishitsMapPF != 0)
	  mishitspf[npf] = (*mishitsMapPF)[c];

	if (hitsMapPF != 0)
	  hitspf[npf] = (*hitsMapPF)[c];

	if (chi2MapPF != 0)
	  chi2pf[npf] = (*chi2MapPF)[c];
	
	if (tkisoMapPF != 0)
	  tkisopf[npf] = fabs((*tkisoMapPF)[c]);
	
	npf++;
      }
    }
  } 

  t->Fill();
}
 
void plotDistr::beginJob() {
  f = new TFile(outputFileName.c_str(), "recreate");
  t = new TTree("tree", "tree");
  
  if (oldClustering) {
    t->Branch("n",  &n, "n/I");
    t->Branch("ewidth", &etawidth, "ewidth[n]/F");
    t->Branch("pwidth", &phiwidth, "pwidth[n]/F");
    t->Branch("e", &e, "e[n]/F");
    t->Branch("et", &et, "et[n]/F");
    t->Branch("se", &se, "se[n]/F");
    t->Branch("eraw", &eraw, "eraw[n]/F");
    t->Branch("eta", &eta, "eta[n]/F");
    t->Branch("phi", &phi, "phi[n]/F");
    t->Branch("seta", &seta, "seta[n]/F");
    t->Branch("sphi", &sphi, "sphi[n]/F");
    t->Branch("sieie", &sieie, "sieie[n]/F");
    t->Branch("ecal", &ecal, "ecal[n]/F");
    //t->Branch("eop", &eop, "eop[n]/F");
    t->Branch("dphi", &dphi, "dphi[n]/F");
    t->Branch("deta", &deta, "deta[n]/F");
    t->Branch("tkpt",    &tkpt,  "tkpt[n]/F");
    t->Branch("tketa",   &tketa, "tketa[n]/F");
    t->Branch("tkphi",   &tkphi, "tkphi[n]/F");
    t->Branch("hoe",   &hoe, "hoe[n]/F");
    t->Branch("hcal",   &hcal, "hcal[n]/F");
    t->Branch("tkiso",   &tkiso, "tkiso[n]/F");
  }
  
  t->Branch("pass", &passSel, "pass/I");
  t->Branch("nvtx", &nvtx, "nvtx/I");
  t->Branch("rho",  &rho, "rho/F");
  
  if (newClustering) {
    t->Branch("npf",  &npf, "npf/I");
    //t->Branch("ewidthpf", &etawidthpf, "ewidthpf[npf]/F");
    //t->Branch("pwidthpf", &phiwidthpf, "pwidthpf[npf]/F");
    t->Branch("epf", &epf, "epf[npf]/F");
    t->Branch("etpf", &etpf, "etpf[npf]/F");
    t->Branch("sepf", &sepf, "sepf[npf]/F");
    //t->Branch("erawpf", &erawpf, "erawpf[npf]/F");
    t->Branch("etapf", &etapf, "etapf[npf]/F");
    t->Branch("phipf", &phipf, "phipf[npf]/F");
    //t->Branch("setapf", &setapf, "setapf[npf]/F");
    //t->Branch("sphipf", &sphipf, "sphipf[npf]/F");
    t->Branch("sieiepf", &sieiepf, "sieiepf[npf]/F");
    t->Branch("ecalpf", &ecalpf, "ecalpf[npf]/F");
    //t->Branch("eop", &eoppf, "eoppf[npf]/F");
    t->Branch("dphipf", &dphipf, "dphipf[npf]/F");
    t->Branch("detapf", &detapf, "detapf[npf]/F");
    t->Branch("detaseedpf", &detaseedpf, "detaseedpf[npf]/F");
    t->Branch("tkptpf",  &tkptpf, "tkptpf[npf]/F");
    t->Branch("tketapf", &tketapf, "tketapf[npf]/F");
    t->Branch("tkphipf", &tkphipf, "tkphipf[npf]/F");
    t->Branch("hoepf",   &hoepf, "hoepf[npf]/F");
    t->Branch("hcalpf",   &hcalpf, "hcalpf[npf]/F");
    t->Branch("tkisopf",   &tkisopf, "tkisopf[npf]/F");
    t->Branch("chiso",   &chiso, "chiso[npf]/F");
    t->Branch("phiso",   &phiso, "phiso[npf]/F");
    t->Branch("neiso",   &neiso, "neiso[npf]/F");
    t->Branch("eoppf", &eoppf, "eoppf[npf]/F");
    t->Branch("chi2pf", &chi2pf, "chi2pf[npf]/F");
    t->Branch("mishitspf", &mishitspf, "mishitspf[npf]/I");
    t->Branch("hitspf", &hitspf, "hitspf[npf]/I");
  }
  
  if (saveUnseeded) {   
    t->Branch("nuns",  &nuns, "nuns/I");
    t->Branch("euns", &euns, "euns[nuns]/F");
    t->Branch("etuns", &etuns, "etuns[nuns]/F");
    t->Branch("etauns", &etauns, "etauns[nuns]/F");
    t->Branch("phiuns", &phiuns, "phiuns[nuns]/F");
  }

  if (saveReco) {
    t->Branch("recon",   &reco_n,   "recon/I");
    t->Branch("recoet",  &reco_et,  "recoet[recon]/F");
    t->Branch("recopt",  &reco_pt,  "recopt[recon]/F");
    t->Branch("recoeta", &reco_eta, "recoeta[recon]/F");
    t->Branch("recophi", &reco_phi, "recophi[recon]/F");
  }

  if (!isData) {
    t->Branch("gpn",   &gp_n,   "gpn/I");
    t->Branch("gppt",  &gp_pt,  "gppt[gpn]/F");
    t->Branch("gpeta", &gp_eta, "gpeta[gpn]/F");
    t->Branch("gpphi", &gp_phi, "gpphi[gpn]/F");
  }
}

void plotDistr::endJob() {
  f->cd();
  t->Write();
  f->Close();
}

void plotDistr::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

DEFINE_FWK_MODULE(plotDistr);
