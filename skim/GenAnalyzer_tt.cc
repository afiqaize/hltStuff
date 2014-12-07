// For tt
// system include files

#include <memory>
#include <iostream>

// user include files
#include "GeneratorInterface/GenFilters/interface/GenAnalyzer_tt.h"

using namespace std;

//
// constructors and destructor
//
GenAnalyzer_tt::GenAnalyzer_tt(const edm::ParameterSet& iConfig):

	genParticleTag_(iConfig.getUntrackedParameter<edm::InputTag>("genParticleTag")),
	genJetTag_(iConfig.getUntrackedParameter<edm::InputTag>("genJetTag")), decayType_(iConfig.getUntrackedParameter("decayType", 1)),
        leptonFlavor_(iConfig.getUntrackedParameter("leptonFlavor", 0)),
        doKinSel(false), lepPtCut(0.), lepEtaCut(20.), jetPtCut(0.), jetEtaCut(20.) {

	  // Kinematic selection at gen level for mu+jets
          doKinSel = iConfig.existsAs<edm::ParameterSet>("kinSelection");
          if (doKinSel) {

            edm::ParameterSet selectionCuts = iConfig.getParameter<edm::ParameterSet>("kinSelection");
            if (selectionCuts.existsAs<double>("jetPtCut"))
              jetPtCut = selectionCuts.getParameter<double>("jetPtCut");
            if (selectionCuts.existsAs<double>("jetEtaCut"))
              jetEtaCut = selectionCuts.getParameter<double>("jetEtaCut");
            if (selectionCuts.existsAs<double>("lepPtCut"))
              lepPtCut = selectionCuts.getParameter<double>("lepPtCut");
            if (selectionCuts.existsAs<double>("lepEtaCut"))
              lepEtaCut = selectionCuts.getParameter<double>("lepEtaCut");

          }

  std::cout<<"JetCuts: "<<jetPtCut<<"\t"<<jetEtaCut<<std::endl;
  std::cout<<"LepCuts: "<<lepPtCut<<"\t"<<lepEtaCut<<std::endl;

}

GenAnalyzer_tt::~GenAnalyzer_tt() {

	 // do anything here that needs to be done at desctruction time
	 // (e.g. close files, deallocate resources etc.)
}

void GenAnalyzer_tt::resetTree() {

        // Reset the variables to its default state

	for (int i = 0; i < maxGenJets; ++i) {

	   jetPt[i] = -1.;
	   jetEta[i] = 9999.;

	}

	nEvt = 0;
	nRun = 0;
	topPt  = -1.;
	bPt    = -1.;
	WPt = -1.;
	topEta  = 9999.;
	bEta    = 9999.;
	WEta = 9999.;

	nLep = 0;
	for (int i = 0; i < maxLepton; ++i) {

		lepId[i] = 0;
		lepPt[i] = -1.;
		lepEta[i] = 9999.;
		lepPhi[i] = 9999.;

	}

	nQuark = 0;
	for (int i = 0; i < maxQuark; ++i) {

		quarkId[i] = 0;
		quarkPt[i] = -1.;
		quarkEta[i] = 9999.;
		quarkPhi[i] = 9999.;

	}
}

//
// member functions
//

const reco::Candidate* GenAnalyzer_tt::getGeneratorFinalStateFor(const reco::Candidate *p, bool isSherpa) {

        // Ensures that any candidate is really its generator final state

        if (p == 0) return 0; // No candidate so reject the event

	const reco::Candidate *prevState = p;
	do {

		const reco::Candidate *nextState = 0;
		int nDaughter = prevState->numberOfDaughters();
		for (int iDaughter=0; iDaughter < nDaughter; iDaughter++) {

			const reco::Candidate *dau = prevState->daughter(iDaughter);
			if(dau == 0) continue;
			if(dau->pdgId() != p->pdgId()) continue;
			nextState = dau;
			break;

		}
		if (nextState == 0) break;
		if (nextState == prevState) break;
		prevState = nextState;
	} while (1);

	return prevState;
}

// ------------ method called for each event  ------------
bool GenAnalyzer_tt::filter(edm::Event& iEvent, const edm::EventSetup& iSetup) {

	bool accept = false;
	using namespace edm;
	using reco::GenParticleCollection;
	using reco::GenJetCollection;

	IndexByPt indexComparator;

	resetTree();

	Handle<GenParticleCollection> genParticles;
	iEvent.getByLabel(genParticleTag_, genParticles);

	nLep = 0;

	std::vector<float> lep_pts, lep_etas, lep_phis, quark_pts, quark_etas, quark_phis;
	std::vector<int> lep_ids, quark_ids;
	std::vector<OrderPair> lep_ordered, quark_ordered;

        nEvt = iEvent.id().event();
        nRun = iEvent.id().run();

	for (size_t i = 0; i < genParticles->size(); ++i ) {

		const reco::GenParticle &p = (*genParticles)[i];
		if (p.status() != 3 && (p.status()<20 || p.status()>30) ) continue;

		// Dump t/b quark properties
		if(abs(p.pdgId()) ==  6 && (p.status()==3 || p.status()==22)) {

			const reco::Candidate *top = getGeneratorFinalStateFor(&p); // Find the top

			topPt  = top->pt();
                        topEta  = top->eta();

			int nTopDau = top->numberOfDaughters();

			for (int j = 0; j < nTopDau; ++j) { // Loop on the top daughters

				const reco::Candidate *top_daughter;

				if (top->daughter(j)->status() == 3) 
                                  top_daughter = top->daughter(j); // pythia 6

				else
                                  top_daughter = getGeneratorFinalStateFor(top->daughter(j));

				int dauId = top_daughter->pdgId();
				if (abs(dauId) ==  5) {

                                  bPt = top_daughter->pt(); 
                                  bEta = top_daughter->eta();
                                  nQuark++;

                                }

				if (abs(dauId) == 24) {

				  WPt = top_daughter->pt(); 
                                  WEta = top_daughter->eta();

				  int nWDau = top_daughter->numberOfDaughters();

				  for (int k = 0; k < nWDau; ++ k) { // Loop on the W daughters

				     const reco::Candidate *w_daughter;
				     if (top_daughter->daughter(k)->status() == 3)
                                       w_daughter = top_daughter->daughter(k); // pythia 6
				     else
                                       w_daughter = getGeneratorFinalStateFor(top_daughter->daughter(k));

				     if (abs(w_daughter->pdgId()) == 11 || abs(w_daughter->pdgId()) == 13 || abs(w_daughter->pdgId()) == 15) { // Leptonic W daughters

                                       if (nLep < maxLepton) {

					 lep_pts.push_back(w_daughter->pt());
					 lep_etas.push_back(w_daughter->eta());
					 lep_phis.push_back(w_daughter->phi());
					 lep_ids.push_back(w_daughter->pdgId());
					 lep_ordered.push_back(std::make_pair(nLep, w_daughter->pt()));

				       }

				       nLep++;

				     }

				     if (abs(w_daughter->pdgId()) > 0 && abs(w_daughter->pdgId()) < 5 ) { // Hadronic W daughters

                                       if (nQuark < maxQuark) {

					 quark_pts.push_back(w_daughter->pt());
					 quark_etas.push_back(w_daughter->eta());
					 quark_phis.push_back(w_daughter->phi());
					 quark_ids.push_back(w_daughter->pdgId());
					 quark_ordered.push_back(std::make_pair(nQuark, w_daughter->pt()));

				       }

				     nQuark++;

				     }
				  }
			      }
		      }
	      }
      }

	std::sort(lep_ordered.begin(), lep_ordered.end(), indexComparator);
	std::sort(quark_ordered.begin(),  quark_ordered.end(), indexComparator);

	int lepi = 0;
	for (std::vector<OrderPair>::const_iterator it = lep_ordered.begin();
		                                  it != lep_ordered.end(); ++it, ++lepi) {
		int index = it->first;
		if (lepi < maxLepton) {

			lepId [lepi] = lep_ids[index];
			lepPt [lepi] = lep_pts[index];
			lepEta[lepi] = lep_etas[index];
			lepPhi[lepi] = lep_phis[index];

		}
	}

	bool lepOk = false;
	int nL = 0;
        bool jetOk = false;
        int nJ = 0;
        
	Handle<GenJetCollection> genJets;
	iEvent.getByLabel(genJetTag_, genJets);

	for (size_t i=0; i < genJets->size(); ++i) {

		if (i > maxGenJets - 1) break;
		const reco::GenJet &jet = (*genJets)[i];
		jetPt[i]  = jet.pt();
		jetEta[i] = jet.eta();

                if (doKinSel) {

                  if ((jetPt[i] > jetPtCut) && fabs(jetEta[i]) < jetEtaCut)
                    nJ++;

                }

                else nJ++;

	}

        if (nJ < nQuark) return false;

	if (decayType_ == 1) { // semileptonic

          for (int k = 0; k < nLep; k++) {

            if (leptonFlavor_ == 1 && abs(lepId[k]) != 11)
              return false;
            if (leptonFlavor_ == 2 && abs(lepId[k]) != 13)
              return false;			
            if (leptonFlavor_ == 3 && abs(lepId[k]) != 15)
              return false;

            if ((lepPt[k] > lepPtCut) && (fabs(lepEta[k]) < lepEtaCut))
              nL++;

          }

          if (doKinSel)
            lepOk = (nL == 1);
          else lepOk = true;

          if (doKinSel)
            jetOk = (nJ >= 4);

          else jetOk = true;

        }

	else if (decayType_ == 2) { // dileptonic

          for (int k = 0; k < nLep; k++) {

            if (leptonFlavor_ == 1 && abs(lepId[k]) != 11)
              return false;
            if (leptonFlavor_ == 2 && abs(lepId[k]) != 13)
              return false;			
            if (leptonFlavor_ == 3 && abs(lepId[k]) != 15)
              return false;

            if ((lepPt[k] > lepPtCut) && (fabs(lepEta[k]) < lepEtaCut))
              nL++;

          }

          if (doKinSel)
            lepOk = (nL == 2);
          else lepOk = true;

          if (doKinSel)
            jetOk = (nJ >= 2);

          else jetOk = true;

        }
   
        else if (decayType_ == 3) { // hadronic

          if (doKinSel)
            lepOk = (nL == 0);

          else lepOk = true;

          if (doKinSel)
            jetOk = (nJ >= 6);

          else jetOk = true;

	}

        accept = (lepOk && jetOk);
        return accept;
}

// ------------ method called once each job just before starting event loop  ------------

// ------------ method called once each job just after ending the event loop  ------------

// ------------ method called when starting to processes a run  ------------
/*
void
GenAnalyzer_tt::beginRun(edm::Run const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when ending the processing of a run  ------------
/*
void
GenAnalyzer_tt::endRun(edm::Run const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when starting to processes a luminosity block  ------------
/*
void
GenAnalyzer_tt::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when ending the processing of a luminosity block  ------------
/*
void
GenAnalyzer_tt::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
//define this as a plug-in
DEFINE_FWK_MODULE(GenAnalyzer_tt);
