#include "drawVar.h"

//
drawVar::drawVar(const edm::ParameterSet& iConfig)
{

  doMatching = false;
  pathName = "";
  filterName = "";
  ptCut = 0.;
  etaCut = 9999.;
  
  doMatching = iConfig.getParameter<bool>("doMatching"); 
  pathName = iConfig.getParameter<std::string>("pathName");
  filterName = iConfig.getParameter<std::string>("filterName");
  procName = iConfig.getParameter<std::string>("procName");
  ptCut = iConfig.getParameter<double>("ptCut");
  etaCut = iConfig.getParameter<double>("etaCut");

}


drawVar::~drawVar()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
drawVar::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
    using namespace edm;
    using namespace std;

    edm::Handle<GenEventInfoProduct> genEvent;
    iEvent.getByLabel("generator", genEvent);

    edm::Handle<reco::GenParticleCollection> genParticles;
    iEvent.getByLabel( "genParticles", genParticles );

    edm::Handle<pat::MuonCollection> patMuons;
    iEvent.getByLabel( "tagMuons", patMuons );

    edm::Handle<pat::JetCollection> tightJets;
    iEvent.getByLabel( "tightJets", tightJets );

    edm::Handle<pat::JetCollection> taggedJets;
    iEvent.getByLabel( "taggedJets", taggedJets );

    edm::InputTag triggerResultsLabel = edm::InputTag("TriggerResults", "", procName);
    edm::Handle<edm::TriggerResults> triggerResults;
    iEvent.getByLabel(triggerResultsLabel, triggerResults);

    // open the trigger summary
    edm::InputTag triggerSummaryLabel_ = edm::InputTag("hltTriggerSummaryAOD", "", procName);
    edm::Handle<trigger::TriggerEvent> triggerSummary;
    iEvent.getByLabel(triggerSummaryLabel_, triggerSummary);
    
    // trigger objects we want to match
    edm::InputTag MuonFilterTag = edm::InputTag(filterName, "", procName);

    trigger::TriggerObjectCollection allTriggerObjects;    
    trigger::TriggerObjectCollection MuonsObjects;

    if (doMatching) {

      bool changedConfig = false;
      if (!hltConfig.init(iEvent.getRun(), iSetup, procName, changedConfig)) {

        cout << "Initialization of HLTConfigProvider failed!!" << endl;
        return;

      }

      if (changedConfig) {

        std::cout << "the curent menu is " << hltConfig.tableName() << std::endl;
        triggerBit = -1;

        for (size_t aa = 0; aa < hltConfig.triggerNames().size(); aa++) {

            if (TString(hltConfig.triggerNames()[aa]).Contains(pathName)) triggerBit = aa;

        }

        if (triggerBit == -1) cout << "HLT path not found" << endl;
       
      }
 
      //find the index corresponding to the event
      size_t MuonFilterIndex = (*triggerSummary).filterIndex(MuonFilterTag);
    
      allTriggerObjects = triggerSummary->getObjects();    
    
      if (MuonFilterIndex < (*triggerSummary).sizeFilters()) { //check if the trigger object is present

        //save the trigger objetcs corresponding to muon leg
        const trigger::Keys &keysMuons = (*triggerSummary).filterKeys(MuonFilterIndex);

        for (size_t bb = 0; bb < keysMuons.size(); bb++) {

            trigger::TriggerObject foundObject = (allTriggerObjects)[keysMuons[bb]];
            MuonsObjects.push_back(foundObject);

        }
      }
    }

    int theNbOfMuon = patMuons->size();
    for (int dd=0 ; dd < theNbOfMuon; dd++) {

      const pat::Muon &patMuon = (*patMuons)[dd];

      if ((fabs(patMuon.eta()) > etaCut)) continue; //eta acceptance cut
      if ((patMuon.pt() < ptCut)) continue; //pt acceptance cut

      if (isRecoMatchedWithGen(patMuon, genParticles)) {

        histos1D_[ "ptMuon_pat" ]->Fill(patMuon.pt());
        histos1D_[ "etaMuon_pat" ]->Fill(patMuon.eta());

        histos1D_[ "nJet_pat" ]->Fill(tightJets->size());
        if (tightJets->size() == 2) histos1D_[ "nTag_pat" ]->Fill(taggedJets->size());

        if (doMatching) {

          if (triggerResults->accept(triggerBit)) {

            histos1D_[ "ptMuon_patPass" ]->Fill(patMuon.pt());
            histos1D_[ "etaMuon_patPass" ]->Fill(patMuon.eta());

            histos1D_[ "nJet_patPass" ]->Fill(tightJets->size());
            if (tightJets->size() == 2) histos1D_[ "nTag_patPass" ]->Fill(taggedJets->size());

          }

          if (isRecoMatchedWithTrigger(patMuon, MuonsObjects)) {

            histos1D_[ "ptMuon_patMatch" ]->Fill(patMuon.pt());
            histos1D_[ "etaMuon_patMatch" ]->Fill(patMuon.eta());

          }
        }
      }
    }
}

// ------------ method called once each job just before starting event loop  ------------
void 
drawVar::beginJob()
{
    edm::Service< TFileService > fileService;

    const int ptBin = 5;
    const int etaBin = 10; 

    float ptBins[ptBin + 1] = {20., 30., 50., 80., 130., 200.};
    float etaBins[etaBin + 1] = {-2.1, -1.65, -1.2, -0.9, -0.45, 0., 0.45, 0.9, 1.2, 1.65, 2.1};

    histos1D_[ "ptMuon_pat" ] = fileService->make< TH1D >( "ptMuon_pat", "nb of pat muon", ptBin, ptBins);
    histos1D_[ "ptMuon_pat" ]->SetXTitle( "muon p_{T} (GeV)" );
    
    histos1D_[ "etaMuon_pat" ] = fileService->make< TH1D >( "etaMuon_pat", "nb of pat muon", etaBin, etaBins);
    histos1D_[ "etaMuon_pat" ]->SetXTitle( "muon #eta" );

    histos1D_[ "nJet_pat" ] = fileService->make< TH1D >( "nJet_pat", "nb of jet", 5., 0., 5.);
    histos1D_[ "nJet_pat" ]->SetXTitle( "nJet" );

    histos1D_[ "nTag_pat" ] = fileService->make< TH1D >( "nTag_pat", "nb of tag", 3., 0., 3.);
    histos1D_[ "nTag_pat" ]->SetXTitle( "nTag" );

    histos1D_[ "ptMuon_patPass" ] = fileService->make< TH1D >( "ptMuon_patPass", "nb of pat muon passing", ptBin, ptBins);
    histos1D_[ "ptMuon_patPass" ]->SetXTitle( "muon p_{T} (GeV)" );
    
    histos1D_[ "etaMuon_patPass" ] = fileService->make< TH1D >( "etaMuon_patPass", "nb of pat muon passing", etaBin, etaBins);
    histos1D_[ "etaMuon_patPass" ]->SetXTitle( "muon #eta" );

    histos1D_[ "nJet_patPass" ] = fileService->make< TH1D >( "nJet_patPass", "nb of jet with muon passing", 5., 0., 5.);
    histos1D_[ "nJet_patPass" ]->SetXTitle( "nJet" );

    histos1D_[ "nTag_patPass" ] = fileService->make< TH1D >( "nTag_patPass", "nb of tag with muon passing and 2 jets", 3., 0., 3.);
    histos1D_[ "nTag_patPass" ]->SetXTitle( "nTag" );

    histos1D_[ "ptMuon_patMatch" ] = fileService->make< TH1D >( "ptMuon_patMatch", "nb of pat muon matched with trigger", ptBin, ptBins);
    histos1D_[ "ptMuon_patMatch" ]->SetXTitle( "muon p_{T} (GeV)" );
    
    histos1D_[ "etaMuon_patMatch" ] = fileService->make< TH1D >( "etaMuon_patMatch", "nb of pat muon matched with trigger", etaBin, etaBins);
    histos1D_[ "etaMuon_patMatch" ]->SetXTitle( "muon #eta" );

}

// ------------ method called once each job just after ending the event loop  ------------
void drawVar::endJob()
{

}

bool drawVar::hasWasMother(const reco::GenParticle p)
{

    bool foundW = false;
    if (p.numberOfMothers()==0) return foundW;
    const reco::Candidate  *part = (p.mother());

    // loop on the mother particles to check if is has a W has mother
    while ((part->numberOfMothers() > 0)) {

        const reco::Candidate  *MomPart =part->mother();

        if (fabs(MomPart->pdgId()) == 24) {

            foundW = true;
            break;

        }

        part = MomPart;

    }

    return foundW;

}

bool drawVar::isRecoMatchedWithTrigger(const pat::Muon m, trigger::TriggerObjectCollection triggerObjects)
{

    for (unsigned int i = 0 ; i < triggerObjects.size() ; i++) {

        float deltaR = sqrt( pow(triggerObjects[i].eta() - m.eta(), 2) + pow(acos(cos(triggerObjects[i].phi() - m.phi())), 2));
        if (deltaR < 0.1) return true;

    }

    return false;

}

bool drawVar::isRecoMatchedWithGen(const pat::Muon m, edm::Handle<reco::GenParticleCollection> genObjects)
{

  for (unsigned int i = 0 ; i < genObjects->size() ; i++) {

      const reco::GenParticle &genCand = (*genObjects)[i];

      if ((fabs(genCand.pdgId()) != 13) || (genCand.status() != 1) || !(hasWasMother(genCand))) continue;
      float deltaR = sqrt( pow(genCand.eta() - m.eta(), 2) + pow(acos(cos(genCand.phi() - m.phi())), 2));
      if (deltaR < 0.1) return true;

  }

    return false;

}

// ------------ method called when starting to processes a run  ------------
/*
void 
drawVar::beginRun(edm::Run const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when ending the processing of a run  ------------
/*
void 
drawVar::endRun(edm::Run const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when starting to processes a luminosity block  ------------
/*
void 
drawVar::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when ending the processing of a luminosity block  ------------
/*
void 
drawVar::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
drawVar::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {

}

//define this as a plug-in
DEFINE_FWK_MODULE(drawVar);
