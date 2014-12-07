import FWCore.ParameterSet.Config as cms

process = cms.Process("GenAnalysisWevSkim01")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.load('RecoJets.Configuration.GenJetParticles_cff')

process.MessageLogger.cerr.FwkReport.reportEvery = cms.untracked.int32(100)

process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(100))
process.options = cms.untracked.PSet(wantSummary = cms.untracked.bool(True))

process.source = cms.Source("PoolSource", 
                            fileNames = cms.untracked.vstring(
        '/store/mc/Fall13dr/WToMuNu_Tune4C_13TeV-pythia8/GEN-SIM-RAW/tsg_PU40bx25_POSTLS162_V2-v1/00000/0AA68F61-726B-E311-AFFC-00266CF32F90.root',
        #'/store/mc/Fall13dr/WToENu_Tune4C_13TeV-pythia8/GEN-SIM-RAW/tsg_PU40bx25_POSTLS162_V2-v1/00000/0066C9AC-8572-E311-8BD2-00266CFAE890.root',
        #'/store/mc/Fall13dr/WToENu_Tune4C_13TeV-pythia8/GEN-SIM-RAW/tsg_PU40bx25_POSTLS162_V2-v1/00000/04838FAA-7D72-E311-9DB8-7845C4FC35E1.root',
        #'/store/mc/Fall13dr/WToENu_Tune4C_13TeV-pythia8/GEN-SIM-RAW/tsg_PU40bx25_POSTLS162_V2-v1/00000/04D1D12F-7272-E311-A256-00266CF9B90C.root',
        #'/store/mc/Fall13dr/WToENu_Tune4C_13TeV-pythia8/GEN-SIM-RAW/tsg_PU40bx25_POSTLS162_V2-v1/00000/06EBCA5E-9C72-E311-B91C-001D09FDD831.root',
        #'/store/mc/Fall13dr/WToENu_Tune4C_13TeV-pythia8/GEN-SIM-RAW/tsg_PU40bx25_POSTLS162_V2-v1/00000/06F4953E-7A72-E311-B6F8-00266CF897A0.root',
        #'/store/mc/Fall13dr/WToENu_Tune4C_13TeV-pythia8/GEN-SIM-RAW/tsg_PU40bx25_POSTLS162_V2-v1/00000/088A0086-A372-E311-ADC0-00A0D1EEE0E4.root',
        #'/store/mc/Fall13dr/WToENu_Tune4C_13TeV-pythia8/GEN-SIM-RAW/tsg_PU40bx25_POSTLS162_V2-v1/00000/1A243E44-B072-E311-B880-848F69FD3E2A.root',
        #'/store/mc/Fall13dr/WToENu_Tune4C_13TeV-pythia8/GEN-SIM-RAW/tsg_PU40bx25_POSTLS162_V2-v1/00000/1A534A0A-8272-E311-9CC9-7845C4FC378E.root',
        #'/store/mc/Fall13dr/WToENu_Tune4C_13TeV-pythia8/GEN-SIM-RAW/tsg_PU40bx25_POSTLS162_V2-v1/00000/2077A09D-7D72-E311-95EE-00266CF897A0.root',
        #'/store/mc/Fall13dr/WToENu_Tune4C_13TeV-pythia8/GEN-SIM-RAW/tsg_PU40bx25_POSTLS162_V2-v1/00000/26B5A47B-B672-E311-A1CD-00A0D1EE8A14.root',
        #'/store/mc/Fall13dr/WToENu_Tune4C_13TeV-pythia8/GEN-SIM-RAW/tsg_PU40bx25_POSTLS162_V2-v1/00000/2E8B0552-A172-E311-B00D-7845C4FC346A.root',
        #'/store/mc/Fall13dr/WToENu_Tune4C_13TeV-pythia8/GEN-SIM-RAW/tsg_PU40bx25_POSTLS162_V2-v1/00000/32AC02C6-9272-E311-B4B6-7845C4FC3B33.root',
        #'/store/mc/Fall13dr/WToENu_Tune4C_13TeV-pythia8/GEN-SIM-RAW/tsg_PU40bx25_POSTLS162_V2-v1/00000/382E4D4F-B972-E311-A80A-7845C4FC35F0.root',
        #'/store/mc/Fall13dr/WToENu_Tune4C_13TeV-pythia8/GEN-SIM-RAW/tsg_PU40bx25_POSTLS162_V2-v1/00000/426A84BF-9472-E311-A477-00A0D1EE95AC.root',
        #'/store/mc/Fall13dr/WToENu_Tune4C_13TeV-pythia8/GEN-SIM-RAW/tsg_PU40bx25_POSTLS162_V2-v1/00000/46307887-9172-E311-97F0-00A0D1EE8AF4.root',
        #'/store/mc/Fall13dr/WToENu_Tune4C_13TeV-pythia8/GEN-SIM-RAW/tsg_PU40bx25_POSTLS162_V2-v1/00000/481B838F-8C72-E311-B792-7845C4FC36AA.root',
        #'/store/mc/Fall13dr/WToENu_Tune4C_13TeV-pythia8/GEN-SIM-RAW/tsg_PU40bx25_POSTLS162_V2-v1/00000/4C054E37-AE72-E311-880A-7845C4FC3983.root',
        #'/store/mc/Fall13dr/WToENu_Tune4C_13TeV-pythia8/GEN-SIM-RAW/tsg_PU40bx25_POSTLS162_V2-v1/00000/4C8184F2-A472-E311-ABD3-00A0D1EEF5B4.root',
        #'/store/mc/Fall13dr/WToENu_Tune4C_13TeV-pythia8/GEN-SIM-RAW/tsg_PU40bx25_POSTLS162_V2-v1/00000/522BCD69-9972-E311-9138-7845C4FC3635.root',
        #'/store/mc/Fall13dr/WToENu_Tune4C_13TeV-pythia8/GEN-SIM-RAW/tsg_PU40bx25_POSTLS162_V2-v1/00000/542C2EC0-9D72-E311-B64F-008CFA0027B4.root',
        #'/store/mc/Fall13dr/WToENu_Tune4C_13TeV-pythia8/GEN-SIM-RAW/tsg_PU40bx25_POSTLS162_V2-v1/00000/648F31ED-8672-E311-8D36-848F69FD454D.root',
        #'/store/mc/Fall13dr/WToENu_Tune4C_13TeV-pythia8/GEN-SIM-RAW/tsg_PU40bx25_POSTLS162_V2-v1/00000/729E75AA-BD72-E311-9DA5-00A0D1EE8E14.root',
        #'/store/mc/Fall13dr/WToENu_Tune4C_13TeV-pythia8/GEN-SIM-RAW/tsg_PU40bx25_POSTLS162_V2-v1/00000/7655F09B-B972-E311-9C61-00266CF20044.root',
        #'/store/mc/Fall13dr/WToENu_Tune4C_13TeV-pythia8/GEN-SIM-RAW/tsg_PU40bx25_POSTLS162_V2-v1/00000/76D35EC8-8772-E311-92B6-00A0D1EE8C64.root',
        #'/store/mc/Fall13dr/WToENu_Tune4C_13TeV-pythia8/GEN-SIM-RAW/tsg_PU40bx25_POSTLS162_V2-v1/00000/78535E2F-9F72-E311-87EA-7845C4FC3A19.root',
        #'/store/mc/Fall13dr/WToENu_Tune4C_13TeV-pythia8/GEN-SIM-RAW/tsg_PU40bx25_POSTLS162_V2-v1/00000/7C0E1B96-8F72-E311-AD2A-848F69FD29D3.root',
        #'/store/mc/Fall13dr/WToENu_Tune4C_13TeV-pythia8/GEN-SIM-RAW/tsg_PU40bx25_POSTLS162_V2-v1/00000/7C1D2515-7072-E311-83C1-848F69FD5027.root',
        #'/store/mc/Fall13dr/WToENu_Tune4C_13TeV-pythia8/GEN-SIM-RAW/tsg_PU40bx25_POSTLS162_V2-v1/00000/7EF21A6A-7672-E311-A230-00266CF9BE6C.root',
        #'/store/mc/Fall13dr/WToENu_Tune4C_13TeV-pythia8/GEN-SIM-RAW/tsg_PU40bx25_POSTLS162_V2-v1/00000/80BB6AAF-B672-E311-A826-7845C4FC3B0F.root',
        #'/store/mc/Fall13dr/WToENu_Tune4C_13TeV-pythia8/GEN-SIM-RAW/tsg_PU40bx25_POSTLS162_V2-v1/00000/8203899E-7D72-E311-BE83-00A0D1EE29D0.root',
                            )
)

process.genana = cms.EDFilter('GenAnalyzer', 
                              genParticleTag = cms.untracked.InputTag('genParticles'), 
                              genJetTag = cms.untracked.InputTag('ak5GenJets'), 
                              kinSelection = cms.PSet(jetPtCut  = cms.double(0.),
                                                      jetEtaCut = cms.double(9999.),
                                                      lepPtCut  = cms.double(20.),
                                                      lepEtaCut = cms.double(3.0)), 
                              decayType = cms.untracked.int32(1),    ## 1 leptonic 2 hadronic
                              leptonFlavor = cms.untracked.int32(2) ## 0 any, 1 e, 2 mu, 3 tau
)

process.p1 = cms.Path(process.genana)

process.load("SimGeneral.HepPDTESSource.pythiapdt_cfi")
process.printTree = cms.EDAnalyzer("ParticleListDrawer", 
                                   maxEventsToPrint = cms.untracked.int32(1), 
                                   printVertex = cms.untracked.bool(False), 
                                   src = cms.InputTag("genParticles")
)

process.out = cms.OutputModule("PoolOutputModule",
                               fileName = cms.untracked.string("Wev_Pt20.root"),
                               SelectEvents = cms.untracked.PSet(SelectEvents = cms.vstring('p1')),
)

process.outpath = cms.EndPath(process.out)
process.schedule = cms.Schedule(process.p1, process.outpath)
