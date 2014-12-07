import FWCore.ParameterSet.Config as cms

process = cms.Process("GenAnalysisSingleTopTest01")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = cms.untracked.int32(100)

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
process.options = cms.untracked.PSet(
    wantSummary = cms.untracked.bool(True)
)

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
                # 'file:/afs/cern.ch/user/a/aapopov/workspace/TopTriggers/2014.02.11_Test-single-top-CSV/t-chan.root',
                # "root://cms-xrd-global.cern.ch///store/mc/Fall13dr/TToBLNu_t-channel-EMu_Tune4C_13TeV-madgraph-tauola/GEN-SIM-RAW/tsg_PU40bx25_POSTLS162_V2-v1/00000/0268BD3F-9A69-E311-BFE4-003048CF632C.root",
                # "root://cms-xrd-global.cern.ch///store/mc/Fall13dr/TToBLNu_t-channel-EMu_Tune4C_13TeV-madgraph-tauola/GEN-SIM-RAW/tsg_PU40bx25_POSTLS162_V2-v1/00000/023BF2EA-D769-E311-BC98-002590494CC4.root",
                # "root://cms-xrd-global.cern.ch///store/mc/Fall13dr/TToBLNu_t-channel-EMu_Tune4C_13TeV-madgraph-tauola/GEN-SIM-RAW/tsg_PU40bx25_POSTLS162_V2-v1/00000/00F0D78E-A569-E311-BAB9-003048C6763A.root"
    )
)

process.genana = cms.EDFilter('GenAnalyzer'
		,genParticleTag = cms.untracked.InputTag('genParticles')
		,genJetTag = cms.untracked.InputTag('ak5GenJets')
		,kinSelection = cms.PSet(
        jetPt = cms.double(20.),
        jetEta= cms.double(4.5),
        lepPt = cms.double(20.),
        lepEta= cms.double(3.0)
    )
    ,decayType = cms.untracked.int32(1),    ## 1=leptonic, 2=hadronic
    leptonFlavour = cms.untracked.int32(2) ## 0=any, 1=e, 2=mu, 3=tau

		
)

#process.TFileService = cms.Service("TFileService",
#	fileName = cms.string('GenAnalysisTree.root')
#)


process.p1 = cms.Path(process.genana)

process.load("SimGeneral.HepPDTESSource.pythiapdt_cfi")
process.printTree = cms.EDAnalyzer("ParticleListDrawer",
  maxEventsToPrint = cms.untracked.int32(1),
  printVertex = cms.untracked.bool(False),
  src = cms.InputTag("genParticles")
)

process.out = cms.OutputModule("PoolOutputModule",
    fileName = cms.untracked.string('testtt.root'),
    #SelectEvents = cms.untracked.PSet(
        #SelectEvents = cms.vstring('p1')
    #),
)

process.outpath = cms.EndPath(process.out)
process.schedule = cms.Schedule(process.p1,process.outpath)

