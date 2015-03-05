import FWCore.ParameterSet.Config as cms

process = cms.Process("DRAW")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_cff')

process.GlobalTag.globaltag = 'PHYS14_25_V1::All'

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.MessageLogger.cerr.FwkReport.reportEvery = cms.untracked.int32( 1000 )

process.source = cms.Source("PoolSource",
                            fileNames = cms.untracked.vstring( 
                                'file:/afs/cern.ch/work/a/afiqaize/hlt/Part2_OpenHLT/OpenHLT/CMSSW_7_3_1/src/HLTrigger/Configuration/test/Alt_Job/trigSel100.root'
                                                           )
)

process.drawHist = cms.EDAnalyzer('drawVar',
                                   pathName = cms.string("HLT_Ele27_eta2p1_WP75_Gsf_v1"),
                                   filterName = cms.string("hltEle27WP75GsfTrackIsoFilter"),
                                   procName = cms.string("TURNON"),
                                   doMatching = cms.bool(True),
                                   ptCut = cms.double(25.),
                                   etaCut = cms.double(2.1),
                                   electrons = cms.InputTag("gedGsfElectrons"),
)
process.TFileService = cms.Service( "TFileService",
                                   fileName = cms.string( 'out.root' )
                                   )

process.p = cms.Path(process.drawHist)
