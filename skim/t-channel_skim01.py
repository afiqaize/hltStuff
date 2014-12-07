import FWCore.ParameterSet.Config as cms

process = cms.Process("GenAnalysisSingleTopSkim01")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.load('RecoJets.Configuration.GenJetParticles_cff')
process.load('RecoJets.JetProducers.ak4GenJets_cfi')

process.MessageLogger.cerr.FwkReport.reportEvery = cms.untracked.int32(100)

process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(-1))
process.options = cms.untracked.PSet(wantSummary = cms.untracked.bool(True))

process.source = cms.Source("PoolSource", 
                            fileNames = cms.untracked.vstring()
)

process.genana = cms.EDFilter('GenAnalyzer_st', 
                              genParticleTag = cms.untracked.InputTag('genParticles'), 
                              genJetTag = cms.untracked.InputTag('ak5GenJets'), 
                              kinSelection = cms.PSet(jetPtCut  = cms.double(20.),
                                                      jetEtaCut = cms.double(4.5),
                                                      lepPtCut  = cms.double(20.),
                                                      lepEtaCut = cms.double(3.0)), 
                              decayType = cms.untracked.int32(1),    ## 1=leptonic, 2=hadronic
                              leptonFlavor = cms.untracked.int32(2) ## 0=any, 1=e, 2=mu, 3=tau
)

process.p1 = cms.Path(process.genana)

process.load("SimGeneral.HepPDTESSource.pythiapdt_cfi")
process.printTree = cms.EDAnalyzer("ParticleListDrawer", 
                                   maxEventsToPrint = cms.untracked.int32(1), 
                                   printVertex = cms.untracked.bool(False), 
                                   src = cms.InputTag("genParticles")
)

process.out = cms.OutputModule("PoolOutputModule",
                               fileName = cms.untracked.string("t-channel_skim01.root"),
                               SelectEvents = cms.untracked.PSet(SelectEvents = cms.vstring('p1')),
)

process.outpath = cms.EndPath(process.out)
process.schedule = cms.Schedule(process.p1, process.outpath)
