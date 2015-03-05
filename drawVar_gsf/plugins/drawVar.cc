#include "drawVar.h"

//
drawVar::drawVar(const edm::ParameterSet& iConfig):
electronCollectionToken(consumes<edm::View<reco::GsfElectron> >(iConfig.getParameter<edm::InputTag>("electrons")))
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
    using reco::GsfElectron;

    edm::Handle<GenEventInfoProduct> genEvent;
    iEvent.getByLabel("generator", genEvent);

    edm::Handle<reco::GenParticleCollection> genParticles;
    iEvent.getByLabel( "genParticles", genParticles );

    edm::Handle<edm::View<reco::GsfElectron> > gsfCollection;
    iEvent.getByToken(electronCollectionToken, gsfCollection);
    const auto &gsfElectrons = gsfCollection->ptrs();

    edm::InputTag triggerResultsLabel = edm::InputTag("TriggerResults", "", procName);
    edm::Handle<edm::TriggerResults> triggerResults;
    iEvent.getByLabel(triggerResultsLabel, triggerResults);

    // open the trigger summary
    edm::InputTag triggerSummaryLabel_ = edm::InputTag("hltTriggerSummaryAOD", "", procName);
    edm::Handle<trigger::TriggerEvent> triggerSummary;
    iEvent.getByLabel(triggerSummaryLabel_, triggerSummary);
    
    // trigger objects we want to match
    edm::InputTag ElectronFilterTag = edm::InputTag(filterName, "", procName);

    trigger::TriggerObjectCollection allTriggerObjects;    
    trigger::TriggerObjectCollection ElectronObjects;

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
      size_t ElectronFilterIndex = (*triggerSummary).filterIndex(ElectronFilterTag);
    
      allTriggerObjects = triggerSummary->getObjects();    
    
      if (ElectronFilterIndex < (*triggerSummary).sizeFilters()) { //check if the trigger object is present

        //save the trigger objetcs corresponding to electron leg
        const trigger::Keys &keysElectrons = (*triggerSummary).filterKeys(ElectronFilterIndex);

        for (size_t bb = 0; bb < keysElectrons.size(); bb++) {

            trigger::TriggerObject foundObject = (allTriggerObjects)[keysElectrons[bb]];
            ElectronObjects.push_back(foundObject);

        }
      }
    }

    for (const auto &gsfElectron : gsfElectrons ) {

      if ((fabs(gsfElectron->superCluster()->eta()) > etaCut)) continue; //eta acceptance cut
      if ((gsfElectron->pt() < ptCut)) continue; //pt acceptance cut

      if (isRecoMatchedWithGen(gsfElectron, genParticles)) {

        histos1D_[ "ptElectron_gsf" ]->Fill(gsfElectron->pt());
        histos1D_[ "etaElectron_gsf" ]->Fill(gsfElectron->superCluster()->eta());

        if (doMatching) {

          if (triggerResults->accept(triggerBit)) {

            histos1D_[ "ptElectron_pass" ]->Fill(gsfElectron->pt());
            histos1D_[ "etaElectron_pass" ]->Fill(gsfElectron->superCluster()->eta());

          }

          if (isRecoMatchedWithTrigger(gsfElectron, ElectronObjects)) {

            histos1D_[ "ptElectron_match" ]->Fill(gsfElectron->pt());
            histos1D_[ "etaElectron_match" ]->Fill(gsfElectron->superCluster()->eta());

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

    float ptBins[26] = {0., 5., 10., 15., 20., 25., 30., 32., 34., 36., 38., 40., 42., 44., 46., 48., 50., 55., 60., 70., 80., 90., 110., 130., 150., 200.};
    
    histos1D_[ "ptElectron_gsf" ] = fileService->make< TH1D >( "ptElectron_gsf", "nb of electron", 25, ptBins);
    histos1D_[ "ptElectron_gsf" ]->SetXTitle( "electron p_{T} (GeV)" );
    
    histos1D_[ "etaElectron_gsf" ] = fileService->make< TH1D >( "etaElectron_gsf", "nb of electron", 30, -3., 3.);
    histos1D_[ "etaElectron_gsf" ]->SetXTitle( "electron #eta" );

    histos1D_[ "ptElectron_pass" ] = fileService->make< TH1D >( "ptElectron_pass", "nb of electron passing", 25, ptBins);
    histos1D_[ "ptElectron_pass" ]->SetXTitle( "electron p_{T} (GeV)" );
    
    histos1D_[ "etaElectron_pass" ] = fileService->make< TH1D >( "etaElectron_pass", "nb of electron passing", 30, -3., 3.);
    histos1D_[ "etaElectron_pass" ]->SetXTitle( "electron #eta" );

    histos1D_[ "ptElectron_match" ] = fileService->make< TH1D >( "ptElectron_match", "nb of electron matched", 25, ptBins);
    histos1D_[ "ptElectron_match" ]->SetXTitle( "electron p_{T} (GeV)" );
    
    histos1D_[ "etaElectron_match" ] = fileService->make< TH1D >( "etaElectron_match", "nb of electron passing matched", 30, -3., 3.);
    histos1D_[ "etaElectron_match" ]->SetXTitle( "electron #eta" );

}

// ------------ method called once each job just after ending the event loop  ------------
void drawVar::endJob()
{

}

bool drawVar::hasWYZasMother(const reco::GenParticle p)
{

    bool foundWYZ = false;
    if (p.numberOfMothers() == 0) return foundWYZ;
    const reco::Candidate  *part = (p.mother());

    // loop on the mother particles to check if is has a W has mother
    while ((part->numberOfMothers() > 0)) {

        const reco::Candidate  *MomPart =part->mother();

        if ((fabs(MomPart->pdgId()) == 22) or (fabs(MomPart->pdgId()) == 23) or (fabs(MomPart->pdgId()) == 24)) {

            foundWYZ = true;
            break;

        }

        part = MomPart;

    }

    return foundWYZ;

}

bool drawVar::isRecoMatchedWithTrigger(const edm::Ptr<reco::GsfElectron> e, trigger::TriggerObjectCollection triggerObjects)
{

    for (unsigned int i = 0 ; i < triggerObjects.size() ; i++) {

        float deltaR = sqrt( pow(triggerObjects[i].eta() - e->superCluster()->eta(), 2) + pow(acos(cos(triggerObjects[i].phi() - e->superCluster()->phi())), 2));
        if (deltaR < 0.1) return true;

    }

    return false;

}

bool drawVar::isRecoMatchedWithGen(const edm::Ptr<reco::GsfElectron> e, edm::Handle<reco::GenParticleCollection> genObjects)
{

  for (unsigned int i = 0 ; i < genObjects->size() ; i++) {

      const reco::GenParticle &genCand = (*genObjects)[i];

      if ((fabs(genCand.pdgId()) != 11) || (genCand.status() != 1) || !(hasWYZasMother(genCand))) continue;
      float deltaR = sqrt( pow(genCand.eta() - e->superCluster()->eta(), 2) + pow(acos(cos(genCand.phi() - e->superCluster()->phi())), 2));
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
