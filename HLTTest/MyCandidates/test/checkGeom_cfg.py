import FWCore.ParameterSet.Config as cms

process = cms.Process("ExREG")
process.load("Configuration.StandardSequences.Services_cff")
process.load('Configuration.Geometry.GeometryDB_cff')
process.load('Configuration/StandardSequences/MagneticField_38T_cff')
process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_cff')
process.load("Configuration.StandardSequences.Reconstruction_cff")
#process.GlobalTag.globaltag = 'FT_R_53_V21::All'
process.GlobalTag.connect   = 'frontier://FrontierProd/CMS_COND_31X_GLOBALTAG'
process.GlobalTag.pfnPrefix = cms.untracked.string('frontier://FrontierProd/')
#process.GlobalTag.pfnPrefix = cms.untracked.string('frontier://FrontierArc/')
from Configuration.AlCa.GlobalTag import GlobalTag as customiseGlobalTag
#process.GlobalTag = customiseGlobalTag(process.GlobalTag, globaltag = 'FT_R_53_V21::All')
process.GlobalTag = customiseGlobalTag(process.GlobalTag, globaltag = 'GR_H_V32::All')
    
#process.GlobalTag.globaltag = 'GR_H_V32::All'

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(1)
    )


process.source = cms.Source("EmptySource")

process.checkGeom = cms.EDAnalyzer("checkGeometry")
process.p = cms.Path(process.checkGeom)

                                        
