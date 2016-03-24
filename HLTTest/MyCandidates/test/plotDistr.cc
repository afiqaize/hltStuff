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

// Jul 23 2015: inclusion of RECO quantities (on RECO/AOD linked with RAW)
// Aug 07 2015: dEtaSeed and other parameters
// Dec 15 2015: updated to use getByToken for 80X
// Jan 14 2016: now event metadata is stored too
// Feb 03 2016: Reverting back to hltPixelVertices for nVtx
// Mar 07 2016: MC-only PU information and updated genParticle info

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
#include "SimDataFormats/PileupSummaryInfo/interface/PileupSummaryInfo.h"

#include "RecoLocalCalo/HcalRecAlgos/interface/HcalSeverityLevelComputer.h"
#include "RecoLocalCalo/HcalRecAlgos/interface/HcalSeverityLevelComputerRcd.h"
#include "CondFormats/HcalObjects/interface/HcalChannelQuality.h"
#include "CondFormats/DataRecord/interface/HcalChannelQualityRcd.h"

#include "Geometry/Records/interface/CaloGeometryRecord.h"

#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/GsfTrackReco/interface/GsfTrack.h"
#include "DataFormats/GsfTrackReco/interface/GsfTrackFwd.h"
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

  edm::EDGetTokenT<edm::TriggerResults> trgResToken;

  edm::EDGetTokenT<reco::GenParticleCollection> genToken;
  edm::EDGetTokenT<reco::VertexCollection> vtxToken;
  edm::EDGetTokenT< std::vector<PileupSummaryInfo> > puToken;

  edm::EDGetTokenT<std::vector<reco::GsfElectron> > elToken;
  edm::EDGetTokenT<std::vector<reco::Electron> > eToken;
  edm::EDGetTokenT<std::vector<reco::RecoEcalCandidate> > cToken;

  edm::EDGetTokenT<edm::ValueMap<float> > recoEcalToken;
  edm::EDGetTokenT<edm::ValueMap<float> > recoHcalToken;

  edm::EDGetTokenT<reco::RecoEcalCandidateIsolationMap> sieieToken;
  edm::EDGetTokenT<reco::RecoEcalCandidateIsolationMap> ecalToken;
  edm::EDGetTokenT<reco::RecoEcalCandidateIsolationMap> hcalToken;
  edm::EDGetTokenT<reco::RecoEcalCandidateIsolationMap> hoeToken;
  edm::EDGetTokenT<reco::RecoEcalCandidateIsolationMap> tkisoToken;
  edm::EDGetTokenT<reco::RecoEcalCandidateIsolationMap> detaToken;
  edm::EDGetTokenT<reco::RecoEcalCandidateIsolationMap> detaSeedToken;
  edm::EDGetTokenT<reco::RecoEcalCandidateIsolationMap> dphiToken;
  edm::EDGetTokenT<reco::RecoEcalCandidateIsolationMap> eopToken;
  edm::EDGetTokenT<reco::RecoEcalCandidateIsolationMap> mishitsToken;
  edm::EDGetTokenT<reco::RecoEcalCandidateIsolationMap> chi2Token;
  edm::EDGetTokenT<reco::RecoEcalCandidateIsolationMap> hitsToken;

  edm::EDGetTokenT<double> rhoToken;

  std::string outputFileName;
  TFile* f;
  TTree* t;
  
  Float_t rho;
  Int_t nRun, nEvt, nLumi, accPath;
  Int_t npf, gp_n, reco_n;
  Float_t epf[10];
  Float_t eRawpf[10];
  Float_t eoppf[10];  
  Float_t etpf[10];
  Float_t etRawpf[10];  
  Float_t sepf[10];  
  Float_t etapf[10];
  Float_t setapf[10];  
  Float_t phipf[10];   
  Float_t sphipf[10];  
  Float_t ecalpf[10];
  Float_t sieiepf[10];
  Float_t detapf[10];
  Float_t detaseedpf[10];
  Float_t dphipf[10];
  Float_t tkptpf[10];
  Float_t tketapf[10];
  Float_t tkphipf[10];
  Float_t hoepf[10];
  Float_t hcalpf[10];
  Float_t tkisopf[10];
  Float_t chi2pf[10];
  Int_t mishitspf[10];
  Int_t hitspf[10];

  Float_t gp_pt[10];
  Float_t gp_eta[10];
  Float_t gp_phi[10];

  Float_t reco_e[10];
  Float_t reco_et[10];
  Float_t reco_eRaw[10];
  Float_t reco_etRaw[10];
  Float_t reco_pt[10];
  Float_t reco_eta[10];
  Float_t reco_phi[10];
  Float_t reco_sieie[10];
  Float_t reco_hoe[10];
  Float_t reco_ecal[10];
  Float_t reco_hcal[10];
  Float_t reco_eop[10];
  Int_t reco_mishits[10];
  Float_t reco_deta[10];
  Float_t reco_detaseed[10];
  Float_t reco_dphi[10];
  Float_t reco_chi2[10];
  Float_t reco_tkiso[10];

  Int_t nVtx;
  Int_t nBX;
  Int_t BX[100];
  Int_t nPUtrue;
  Int_t nPUobs[100];

  bool isData;
  bool saveReco;

};

void plotDistr::beginRun(const edm::Run& run,const edm::EventSetup& setup) {
  std::cout <<"begining run "<<std::endl;
  bool changed = false;
  hltConfig_.init(run,setup,trigResultsTag_.process(),changed); //as we need the orginal HLT config...
  std::cout <<"table name "<<hltConfig_.tableName()<<std::endl;
}


plotDistr::plotDistr(const edm::ParameterSet& iParSet) {
  outputFileName  = iParSet.getParameter<std::string>("OutputFileName");
  isData          = iParSet.getParameter<bool>("isData");
  newClustering   = iParSet.getParameter<bool>("activateNewClustering");
  saveReco        = iParSet.getParameter<bool>("saveReco");
  pathNames_      = iParSet.getParameter<std::vector<std::string> >("trgSelection");
  trigResultsTag_ = iParSet.getParameter<edm::InputTag>("trgResults");

  trgResToken     = consumes<edm::TriggerResults>(trigResultsTag_);
  genToken        = consumes<reco::GenParticleCollection>(edm::InputTag("genParticles"));
  vtxToken        = consumes<reco::VertexCollection>(edm::InputTag("hltPixelVertices"));
  puToken         = consumes<std::vector<PileupSummaryInfo> >(edm::InputTag("addPileupInfo"));

  elToken         = consumes<std::vector<reco::GsfElectron> >(edm::InputTag("gedGsfElectrons"));
  //eToken        = consumes<std::vector<reco::Electron> >(edm::InputTag("hltEgammaCandidates"));
  cToken          = consumes<std::vector<reco::RecoEcalCandidate> >(edm::InputTag("hltEgammaCandidates"));

  recoEcalToken   = consumes<edm::ValueMap<float> >(edm::InputTag("electronEcalPFClusterIsolationProducer"));
  recoHcalToken   = consumes<edm::ValueMap<float> >(edm::InputTag("electronHcalPFClusterIsolationProducer"));

  sieieToken      = consumes<reco::RecoEcalCandidateIsolationMap>(edm::InputTag("hltEgammaClusterShape:sigmaIEtaIEta5x5"));
  ecalToken       = consumes<reco::RecoEcalCandidateIsolationMap>(edm::InputTag("hltEgammaEcalPFClusterIso"));
  hcalToken       = consumes<reco::RecoEcalCandidateIsolationMap>(edm::InputTag("hltEgammaHcalPFClusterIso"));
  hoeToken        = consumes<reco::RecoEcalCandidateIsolationMap>(edm::InputTag("hltEgammaHoverE"));
  tkisoToken      = consumes<reco::RecoEcalCandidateIsolationMap>(edm::InputTag("hltEgammaEleGsfTrackIso"));
  detaToken       = consumes<reco::RecoEcalCandidateIsolationMap>(edm::InputTag("hltEgammaGsfTrackVars:Deta"));
  detaSeedToken   = consumes<reco::RecoEcalCandidateIsolationMap>(edm::InputTag("hltEgammaGsfTrackVars:DetaSeed"));
  dphiToken       = consumes<reco::RecoEcalCandidateIsolationMap>(edm::InputTag("hltEgammaGsfTrackVars:Dphi"));
  eopToken        = consumes<reco::RecoEcalCandidateIsolationMap>(edm::InputTag("hltEgammaGsfTrackVars:OneOESuperMinusOneOP"));
  chi2Token       = consumes<reco::RecoEcalCandidateIsolationMap>(edm::InputTag("hltEgammaGsfTrackVars:Chi2"));
  mishitsToken    = consumes<reco::RecoEcalCandidateIsolationMap>(edm::InputTag("hltEgammaGsfTrackVars:MissingHits"));
  hitsToken       = consumes<reco::RecoEcalCandidateIsolationMap>(edm::InputTag("hltEgammaGsfTrackVars:ValidHits"));

  rhoToken        = consumes<double>(edm::InputTag("hltFixedGridRhoFastjetAllCaloForMuons"));
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
    
    if ((gp->status() == 23 or gp->status() == 24) and abs(gp->pdgId()) == 11) {
      if (gp->pt() > 0.) {
	gp_pt[gp_n]  = gp->pt();
	gp_eta[gp_n] = gp->eta();
	gp_phi[gp_n] = gp->phi();
	gp_n++;
      }
    }
  }
}

void plotDistr::analyze(const edm::Event& iEvt, const edm::EventSetup& iSetup) {

  nRun = iEvt.eventAuxiliary().run();
  nEvt = iEvt.eventAuxiliary().event();
  nLumi = iEvt.eventAuxiliary().luminosityBlock();

  edm::Handle<edm::TriggerResults> trigResultsHandle;
  iEvt.getByToken(trgResToken,trigResultsHandle);

  const edm::TriggerResults& trigResults = *trigResultsHandle;
  const edm::TriggerNames& trigNames = iEvt.triggerNames(trigResults);  

  accPath = 0; 
  for(size_t pathNr=0;pathNr<pathNames_.size();pathNr++){
    size_t pathIndex = trigNames.triggerIndex(pathNames_[pathNr]);
    if(pathIndex<trigResults.size() &&  trigResults.accept(pathIndex)) 
      accPath = 1;
  }

  edm::Handle<reco::GenParticleCollection> gpH;
  edm::Handle<std::vector<PileupSummaryInfo> > puH;

  nBX = 0;
  if (!isData) {

    iEvt.getByToken(genToken, gpH);
    mcTruth(gpH);

    iEvt.getByToken(puToken, puH);
    nPUtrue = puH->begin()->getTrueNumInteractions();
    std::vector<PileupSummaryInfo>::const_iterator pu;

    for(pu = puH->begin(); pu != puH->end(); ++pu) {
      BX[nBX]      = pu->getBunchCrossing();
      nPUobs[nBX]  = pu->getPU_NumInteractions();
      nBX++;
    }
  }

  if (saveReco) {

    edm::Handle<std::vector<reco::GsfElectron> > elH;
    iEvt.getByToken(elToken, elH);

    edm::Handle<edm::ValueMap<float> > recoEcalMap;
    iEvt.getByToken(recoEcalToken, recoEcalMap);

    edm::Handle<edm::ValueMap<float> > recoHcalMap;
    iEvt.getByToken(recoHcalToken, recoHcalMap);

    reco_n = 0;
    for (unsigned int i=0; i<elH->size(); i++) {
      if (reco_n == 9)
	continue;
      reco_e[reco_n] = 9999.;
      reco_et[reco_n] = 9999.;
      reco_eta[reco_n] = 9999.;
      reco_phi[reco_n] = 9999.;
      reco_sieie[reco_n] = 9999.;
      reco_hoe[reco_n] = 9999.;
      reco_ecal[reco_n] = 9999.;
      reco_hcal[reco_n] = 9999.;
      reco_eop[reco_n] = 9999.;
      reco_mishits[reco_n] = 9999;
      reco_deta[reco_n] = 9999.;
      reco_detaseed[reco_n] = 9999.;
      reco_dphi[reco_n] = 9999.;
      reco_chi2[reco_n] = 9999.;
      reco_tkiso[reco_n] = 9999.;
      
      reco::GsfElectronRef el(elH, i);
      reco::GsfElectron::PflowIsolationVariables pfIso = el->pfIsolationVariables();

      reco_e[reco_n] = el->superCluster()->energy();

      reco_et[reco_n] = el->superCluster()->energy()*sin(el->superCluster()->position().theta());

      reco_eRaw[reco_n] = el->superCluster()->rawEnergy();

      reco_etRaw[reco_n] = el->superCluster()->rawEnergy()*sin(el->superCluster()->position().theta());

      reco_pt[reco_n] = el->pt();

      reco_eta[reco_n] = el->superCluster()->eta();

      reco_phi[reco_n] = el->superCluster()->phi();

      reco_sieie[reco_n] = el->full5x5_sigmaIetaIeta();

      reco_hoe[reco_n] = el->hadronicOverEm();

      reco_ecal[reco_n] = (*recoEcalMap)[el];

      reco_hcal[reco_n] = (*recoHcalMap)[el];

      reco_eop[reco_n] = ( 1. / el->superCluster()->energy() ) - ( 1. / el->gsfTrack()->p() );

      reco_mishits[reco_n] = el->gsfTrack()->hitPattern().numberOfHits(reco::HitPattern::MISSING_INNER_HITS);

      reco_deta[reco_n] = el->deltaEtaSuperClusterTrackAtVtx();

      reco_detaseed[reco_n] = el->deltaEtaSeedClusterTrackAtVtx();

      reco_dphi[reco_n] = el->deltaPhiSuperClusterTrackAtVtx();

      reco_chi2[reco_n] = el->gsfTrack()->normalizedChi2();

      reco_tkiso[reco_n] = pfIso.sumChargedHadronPt;

      //std::cout << "plotReco: " << reco_et[reco_n] << " " << reco_eta[reco_n] << " " << reco_phi[reco_n] << std::endl;

      reco_n++;

    }

  }

  edm::Handle<std::vector<reco::Electron> > eH;
  edm::Handle<std::vector<reco::RecoEcalCandidate> > cH;
  edm::Handle<reco::RecoEcalCandidateIsolationMap> sieieMapH;
  edm::Handle<reco::RecoEcalCandidateIsolationMap> ecalMapH;
  edm::Handle<reco::RecoEcalCandidateIsolationMap> hcalMapH;
  edm::Handle<reco::RecoEcalCandidateIsolationMap> hoeMapH;
  edm::Handle<reco::RecoEcalCandidateIsolationMap> tkisoMapH;
  edm::Handle<reco::RecoEcalCandidateIsolationMap> detaMapH;
  edm::Handle<reco::RecoEcalCandidateIsolationMap> detaSeedMapH;
  edm::Handle<reco::RecoEcalCandidateIsolationMap> dphiMapH;
  edm::Handle<reco::RecoEcalCandidateIsolationMap> eopMapH;
  edm::Handle<reco::RecoEcalCandidateIsolationMap> mishitsMapH;
  edm::Handle<reco::RecoEcalCandidateIsolationMap> chi2MapH;
  edm::Handle<reco::RecoEcalCandidateIsolationMap> hitsMapH;

  edm::Handle<reco::VertexCollection> vtxH;
  iEvt.getByToken(vtxToken, vtxH);

  if (!vtxH.failedToGet())
    nVtx = vtxH->size();
  else
    nVtx = 0;

  edm::Handle<double> rhoH;
  iEvt.getByToken(rhoToken, rhoH);

  if (!rhoH.failedToGet())
    rho = *(rhoH.product());
  else
    rho = 9999.;

  npf = 0;
  iEvt.getByToken(cToken, cH);
  if (!cH.failedToGet()) {
    
    const reco::RecoEcalCandidateIsolationMap* sieieMapPF = 0;
    iEvt.getByToken(sieieToken, sieieMapH);
    if (!sieieMapH.failedToGet())  
      sieieMapPF = sieieMapH.product();
      
    const reco::RecoEcalCandidateIsolationMap* ecalMapPF = 0;
    iEvt.getByToken(ecalToken, ecalMapH);
    if (!ecalMapH.failedToGet()) 
      ecalMapPF = ecalMapH.product(); 
      
    const reco::RecoEcalCandidateIsolationMap* hcalMapPF = 0;
    iEvt.getByToken(hcalToken, hcalMapH);
    if (!hcalMapH.failedToGet()) 
      hcalMapPF = hcalMapH.product(); 
      
    const reco::RecoEcalCandidateIsolationMap* hoeMapPF = 0;
    iEvt.getByToken(hoeToken, hoeMapH);
    if (!hoeMapH.failedToGet()) 
      hoeMapPF = hoeMapH.product(); 
      
    const reco::RecoEcalCandidateIsolationMap* tkisoMapPF = 0;
    iEvt.getByToken(tkisoToken, tkisoMapH);
    if (!tkisoMapH.failedToGet())
      tkisoMapPF = tkisoMapH.product();          
      
    const reco::RecoEcalCandidateIsolationMap* detaMapPF = 0;
    iEvt.getByToken(detaToken, detaMapH);
    if (!detaMapH.failedToGet())
      detaMapPF = detaMapH.product();

    const reco::RecoEcalCandidateIsolationMap* detaSeedMapPF = 0;
    iEvt.getByToken(detaSeedToken, detaSeedMapH);
    if (!detaSeedMapH.failedToGet())
      detaSeedMapPF = detaSeedMapH.product();
      
    const reco::RecoEcalCandidateIsolationMap* dphiMapPF = 0;
    iEvt.getByToken(dphiToken, dphiMapH);
    if (!dphiMapH.failedToGet()) 
      dphiMapPF = dphiMapH.product();
      
    const reco::RecoEcalCandidateIsolationMap* eopMapPF = 0;
    iEvt.getByToken(eopToken, eopMapH);
    if (!eopMapH.failedToGet()) 
      eopMapPF = eopMapH.product();

    const reco::RecoEcalCandidateIsolationMap* chi2MapPF = 0;
    iEvt.getByToken(chi2Token, chi2MapH);
    if (!chi2MapH.failedToGet()) 
      chi2MapPF = chi2MapH.product();

    const reco::RecoEcalCandidateIsolationMap* mishitsMapPF = 0;
    iEvt.getByToken(mishitsToken, mishitsMapH);
    if (!mishitsMapH.failedToGet()) 
      mishitsMapPF = mishitsMapH.product();

    const reco::RecoEcalCandidateIsolationMap* hitsMapPF = 0;
    iEvt.getByToken(hitsToken, hitsMapH);
    if (!hitsMapH.failedToGet()) 
      hitsMapPF = hitsMapH.product();
      
    for (unsigned int i=0; i<cH->size(); i++) {
      if (npf >= 9) continue;

      epf[npf] = 9999.;
      eRawpf[npf] = 9999.;
      eoppf[npf] = 9999.;
      etpf[npf] = 9999.;
      etRawpf[npf] = 9999.;
      etapf[npf] = 9999.;
      phipf[npf] = 9999.;
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

      epf[npf] = c->superCluster()->energy();
      eRawpf[npf] = c->superCluster()->rawEnergy();
      etpf[npf] = c->superCluster()->energy()*sin(c->superCluster()->position().theta());
      etRawpf[npf] = c->superCluster()->rawEnergy()*sin(c->superCluster()->position().theta());
      etapf[npf] = c->eta();
      phipf[npf] = c->phi();

      if (sieieMapPF != 0) sieiepf[npf] = (*sieieMapPF)[c];
      if (ecalMapPF != 0) ecalpf[npf] = (*ecalMapPF)[c];
      if (hoeMapPF != 0) hoepf[npf] = (*hoeMapPF)[c];
      if (hcalMapPF != 0) hcalpf[npf] = (*hcalMapPF)[c];
      if (detaMapPF != 0) detapf[npf] = ((*detaMapPF)[c]);
      if (detaSeedMapPF != 0) detaseedpf[npf] = ((*detaSeedMapPF)[c]);
      if (dphiMapPF != 0) dphipf[npf] = fabs((*dphiMapPF)[c]);
      if (eopMapPF != 0) eoppf[npf] = fabs((*eopMapPF)[c]);
      if (mishitsMapPF != 0) mishitspf[npf] = (*mishitsMapPF)[c];
      if (hitsMapPF != 0) hitspf[npf] = (*hitsMapPF)[c];
      if (chi2MapPF != 0) chi2pf[npf] = (*chi2MapPF)[c];
      if (tkisoMapPF != 0) tkisopf[npf] = fabs((*tkisoMapPF)[c]);
	
      //std::cout << "plotHLT: " << etpf[npf] << " " << etapf[npf] << " " << phipf[npf] << std::endl;

      npf++;

    }
  }

  t->Fill();
  //std::cout << std::endl;
  //std::cout << " +++++++ --- +++++++" << std::endl;
  //std::cout << std::endl;

}
 
void plotDistr::beginJob() {
  f = new TFile(outputFileName.c_str(), "recreate");
  t = new TTree("tree", "tree");

  t->Branch("nRun", &nRun, "nRun/I");
  t->Branch("nEvt", &nEvt, "nEvt/I");
  t->Branch("nLumi", &nLumi, "nLumi/I");
  
  t->Branch("accPath", &accPath, "accPath/I");
  t->Branch("nVtx", &nVtx, "nVtx/I");
  t->Branch("rho",  &rho, "rho/F");
  
  if (newClustering) {
    t->Branch("npf",  &npf, "npf/I");
    t->Branch("epf", &epf, "epf[npf]/F");
    t->Branch("eRawpf", &eRawpf, "eRawpf[npf]/F");
    t->Branch("etpf", &etpf, "etpf[npf]/F");
    t->Branch("etRawpf", &etRawpf, "etRawpf[npf]/F");
    t->Branch("etapf", &etapf, "etapf[npf]/F");
    t->Branch("phipf", &phipf, "phipf[npf]/F");
    t->Branch("sieiepf", &sieiepf, "sieiepf[npf]/F");
    t->Branch("ecalpf", &ecalpf, "ecalpf[npf]/F");
    t->Branch("dphipf", &dphipf, "dphipf[npf]/F");
    t->Branch("detapf", &detapf, "detapf[npf]/F");
    t->Branch("detaseedpf", &detaseedpf, "detaseedpf[npf]/F");
    t->Branch("tkptpf",  &tkptpf, "tkptpf[npf]/F");
    t->Branch("tketapf", &tketapf, "tketapf[npf]/F");
    t->Branch("tkphipf", &tkphipf, "tkphipf[npf]/F");
    t->Branch("hoepf",   &hoepf, "hoepf[npf]/F");
    t->Branch("hcalpf",   &hcalpf, "hcalpf[npf]/F");
    t->Branch("tkisopf",   &tkisopf, "tkisopf[npf]/F");
    t->Branch("eoppf", &eoppf, "eoppf[npf]/F");
    t->Branch("chi2pf", &chi2pf, "chi2pf[npf]/F");
    t->Branch("mishitspf", &mishitspf, "mishitspf[npf]/I");
    t->Branch("hitspf", &hitspf, "hitspf[npf]/I");
  }

  if (saveReco) {
    t->Branch("reco_n",   &reco_n,   "reco_n/I");
    t->Branch("reco_e",  &reco_e,  "reco_e[reco_n]/F");
    t->Branch("reco_et",  &reco_et,  "reco_et[reco_n]/F");
    t->Branch("reco_eRaw",  &reco_eRaw,  "reco_eRaw[reco_n]/F");
    t->Branch("reco_etRaw",  &reco_etRaw,  "reco_etRaw[reco_n]/F");
    t->Branch("reco_pt",  &reco_pt,  "reco_pt[reco_n]/F");
    t->Branch("reco_eta", &reco_eta, "reco_eta[reco_n]/F");
    t->Branch("reco_phi", &reco_phi, "reco_phi[reco_n]/F");
    t->Branch("reco_sieie",  &reco_sieie,  "reco_sieie[reco_n]/F");
    t->Branch("reco_hoe", &reco_hoe, "reco_hoe[reco_n]/F");
    t->Branch("reco_ecal", &reco_ecal, "reco_ecal[reco_n]/F");
    t->Branch("reco_hcal",  &reco_hcal,  "reco_hcal[reco_n]/F");
    t->Branch("reco_eop", &reco_eop, "reco_eop[reco_n]/F");
    t->Branch("reco_mishits", &reco_mishits, "reco_mishits[reco_n]/I");
    t->Branch("reco_deta",  &reco_deta,  "reco_deta[reco_n]/F");
    t->Branch("reco_detaseed",  &reco_detaseed,  "reco_detaseed[reco_n]/F");
    t->Branch("reco_dphi", &reco_dphi, "reco_dphi[reco_n]/F");
    t->Branch("reco_chi2", &reco_chi2, "reco_chi2[reco_n]/F");
    t->Branch("reco_tkiso", &reco_tkiso, "reco_tkiso[reco_n]/F");
  }

  if (!isData) {
    t->Branch("gpn", &gp_n, "gpn/I");
    t->Branch("gppt", &gp_pt, "gppt[gpn]/F");
    t->Branch("gpeta", &gp_eta, "gpeta[gpn]/F");
    t->Branch("gpphi", &gp_phi, "gpphi[gpn]/F");
    t-> Branch("nBX", &nBX, "nBX/I");
    t-> Branch("BX", BX, "BX[nBX]/I");
    t-> Branch("nPUtrue", &nPUtrue, "nPUtrue/I");
    t-> Branch("nPUobs", nPUobs, "nPUobs[nBX]/I");
  }
}

void plotDistr::endJob() {
  f->cd();
  t->Write();
  f->Close();
}

void plotDistr::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  // The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

DEFINE_FWK_MODULE(plotDistr);
