import FWCore.ParameterSet.Config as cms

process = cms.Process("DRAW")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = cms.untracked.int32( 1000 )

process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
process.GlobalTag.globaltag = 'START44_V9B::All'

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.source = cms.Source("PoolSource",
                            fileNames = cms.untracked.vstring( 
                                'file:/afs/cern.ch/work/a/afiqaize/t_schan/Part1_TagProbe/CMSSW_4_4_5/src/MuonAnalysis/TagAndProbe/test/zmumu/t_schan.root',
                                'file:/afs/cern.ch/work/a/afiqaize/t_schan/Part1_TagProbe/CMSSW_4_4_5/src/MuonAnalysis/TagAndProbe/test/zmumu/tbar_schan.root',
                                                           )
)

process.drawHist = cms.EDAnalyzer('drawVar',
                                   pathName = cms.string("HLT_IsoMu17_v"),
                                   filterName = cms.string("hltIsoMu17L3IsoFiltered17"),
                                   procName = cms.string("HLT"),
                                   doMatching = cms.bool(True),
                                   ptCut = cms.double(20.),
                                   etaCut = cms.double(2.1),
)
process.TFileService = cms.Service( "TFileService",
                                   fileName = cms.string( 'schan_hist.root' )
                                   )

process.p = cms.Path(process.drawHist)
