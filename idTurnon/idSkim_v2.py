import FWCore.ParameterSet.Config as cms

process = cms.Process("idSkim")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = cms.untracked.int32(1000)

# Load stuff needed by lazy tools later for the value map producer
process.load("Configuration.StandardSequences.Services_cff")
process.load("Configuration.StandardSequences.Geometry_cff")
process.load("Configuration.StandardSequences.MagneticField_38T_cff")
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
process.load("Configuration.StandardSequences.Reconstruction_cff")
# NOTE: the pick the right global tag!
# for PHYS14 scenario PU4bx50 : global tag is ???
# for PHYS14 scenario PU20bx25: global tag is PHYS14_25_V1
# as a rule, find the global tag in the DAS under the Configs for given dataset
process.GlobalTag.globaltag = 'PHYS14_25_V1'

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

process.source = cms.Source("PoolSource",
                            fileNames = cms.untracked.vstring(),
                            secondaryFileNames = cms.untracked.vstring()
                            )

# START ELECTRON ID SECTION
#
# Set up everything that is needed to compute electron IDs and
# add the ValueMaps with ID decisions into the event data stream
#
# Load tools and function definitions

from PhysicsTools.SelectorUtils.tools.vid_id_tools import *

# Turn on VID producer
# switchOnVIDElectronIdProducer(process)

process.load("RecoEgamma.ElectronIdentification.egmGsfElectronIDs_cfi")

from PhysicsTools.SelectorUtils.centralIDRegistry import central_id_registry
process.egmGsfElectronIDSequence = cms.Sequence(process.egmGsfElectronIDs)

# Define which IDs we want to produce
# Each of these two example IDs contains all four standard
# cut-based ID working points (only two WP of the PU20bx25 are actually used here).

my_id_modules = ['RecoEgamma.ElectronIdentification.Identification.cutBasedElectronID_PHYS14_PU20bx25_V1_cff']

# Add them to the VID producer

for idmod in my_id_modules:
                setupAllVIDIdsInModule(process, idmod, setupVIDElectronSelection)

# Do not forget to add the egmGsfElectronIDSequence to the path,
# as in the example below!
#
# END ELECTRON ID SECTION
#
# Configure an example module for user analysis of electrons

process.eID = cms.EDFilter('ElectronIDFilter',
                             electrons = cms.InputTag("gedGsfElectrons"),
                             electronID = cms.InputTag("egmGsfElectronIDs:cutBasedElectronID-PHYS14-PU20bx25-V1-standalone-tight"),
                             genParticleTag = cms.InputTag("genParticles"),
                             )

process.drawHist = cms.EDAnalyzer('drawVar',
                                   pathName = cms.string("HLT_Ele32_eta2p1_WP75_Gsf_v1"),
                                   filterName = cms.string("hltEle32WP75GsfTrackIsoFilter"),
                                   procName = cms.string("idSkim"),
                                   doMatching = cms.bool(False),
                                   ptCut = cms.double(30.),
                                   etaCut = cms.double(2.1),
                                   electrons = cms.InputTag("gedGsfElectrons"),
)
process.TFileService = cms.Service("TFileService",
                                   fileName = cms.string( 'out.root' )
                                  )

process.p = cms.Path(process.egmGsfElectronIDSequence * process.eID + process.drawHist)


