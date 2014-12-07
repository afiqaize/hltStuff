import FWCore.ParameterSet.Config as cms

process = cms.Process("DRAW")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_cff')

#process.GlobalTag.globaltag = 'PRE_LS171_V5A::All'
process.GlobalTag.globaltag = 'MCRUN2_72_V3A::All'

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.MessageLogger.cerr.FwkReport.reportEvery = cms.untracked.int32( 1000 )

process.source = cms.Source("PoolSource",
                            fileNames = cms.untracked.vstring( 
                                #'/store/group/phys_top/triggerStudies/skims/'
                                '/store/group/phys_top/triggerStudies/path_output/tchan_cut1p0_721p2_01.root',
                                '/store/group/phys_top/triggerStudies/path_output/tchan_cut1p0_721p2_02.root',
                                '/store/group/phys_top/triggerStudies/path_output/tchan_cut1p0_721p2_03.root',
                                '/store/group/phys_top/triggerStudies/path_output/tchan_cut1p0_721p2_04.root',
                                '/store/group/phys_top/triggerStudies/path_output/tchan_cut1p0_721p2_05.root',
                                '/store/group/phys_top/triggerStudies/path_output/tchan_cut1p0_721p2_06.root',
                                '/store/group/phys_top/triggerStudies/path_output/tchan_cut1p0_721p2_07.root',
                                                           )
)

process.drawHist = cms.EDAnalyzer('drawVar',
                                   pathName = cms.string("HLT_Ele27_eta2p1_WP75_Gsf_v1"),
                                   filterName = cms.string("hltEle27WP75GsfTrackIsoFilter"),
                                   procName = cms.string("NTUPLE"),
                                   doMatching = cms.bool(True),
                                   ptCutGen = cms.double(25.),
                                   etaCutGen = cms.double(2.1),
)
process.TFileService = cms.Service( "TFileService",
                                   fileName = cms.string( 'tchan_hlt27_wp75_kin.root' )
                                   )

process.p = cms.Path(process.drawHist)
