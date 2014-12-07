#!/bin/bash


: || : << EOF

srcDir="root://cms-xrd-global.cern.ch///store//mc/Fall13dr/WToENu_Tune4C_13TeV-pythia8/GEN-SIM-RAW/tsg_PU40bx25_POSTLS162_V2-v1/00000/"

fileName01="0066C9AC-8572-E311-8BD2-00266CFAE890.root"
fileName02="04838FAA-7D72-E311-9DB8-7845C4FC35E1.root"
fileName03="04D1D12F-7272-E311-A256-00266CF9B90C.root"
fileName04="06EBCA5E-9C72-E311-B91C-001D09FDD831.root"
fileName05="06F4953E-7A72-E311-B6F8-00266CF897A0.root"
fileName06="088A0086-A372-E311-ADC0-00A0D1EEE0E4.root"
fileName07="1A243E44-B072-E311-B880-848F69FD3E2A.root"
fileName08="1A534A0A-8272-E311-9CC9-7845C4FC378E.root"
fileName09="2077A09D-7D72-E311-95EE-00266CF897A0.root"
fileName10="26B5A47B-B672-E311-A1CD-00A0D1EE8A14.root"
fileName11="2E8B0552-A172-E311-B00D-7845C4FC346A.root"
fileName12="32AC02C6-9272-E311-B4B6-7845C4FC3B33.root"
fileName13="382E4D4F-B972-E311-A80A-7845C4FC35F0.root"
fileName14="426A84BF-9472-E311-A477-00A0D1EE95AC.root"
fileName15="46307887-9172-E311-97F0-00A0D1EE8AF4.root"
fileName16="481B838F-8C72-E311-B792-7845C4FC36AA.root"
fileName17="4C054E37-AE72-E311-880A-7845C4FC3983.root"
fileName18="4C8184F2-A472-E311-ABD3-00A0D1EEF5B4.root"
fileName19="522BCD69-9972-E311-9138-7845C4FC3635.root"
fileName20="542C2EC0-9D72-E311-B64F-008CFA0027B4.root"
fileName21="648F31ED-8672-E311-8D36-848F69FD454D.root"
fileName22="729E75AA-BD72-E311-9DA5-00A0D1EE8E14.root"
fileName23="7655F09B-B972-E311-9C61-00266CF20044.root"
fileName24="76D35EC8-8772-E311-92B6-00A0D1EE8C64.root"
fileName25="78535E2F-9F72-E311-87EA-7845C4FC3A19.root"
fileName26="7C0E1B96-8F72-E311-AD2A-848F69FD29D3.root"
fileName27="7C1D2515-7072-E311-83C1-848F69FD5027.root"
fileName28="7EF21A6A-7672-E311-A230-00266CF9BE6C.root"
fileName29="80BB6AAF-B672-E311-A826-7845C4FC3B0F.root"
fileName30="8203899E-7D72-E311-BE83-00A0D1EE29D0.root"

srcFile01=$srcDir$fileName01
srcFile02=$srcDir$fileName02
srcFile03=$srcDir$fileName03
srcFile04=$srcDir$fileName04
srcFile05=$srcDir$fileName05
srcFile06=$srcDir$fileName06
srcFile07=$srcDir$fileName07
srcFile08=$srcDir$fileName08
srcFile09=$srcDir$fileName09
srcFile10=$srcDir$fileName10
srcFile11=$srcDir$fileName11
srcFile12=$srcDir$fileName12
srcFile13=$srcDir$fileName13
srcFile14=$srcDir$fileName14
srcFile15=$srcDir$fileName15
srcFile16=$srcDir$fileName16
srcFile17=$srcDir$fileName17
srcFile18=$srcDir$fileName18
srcFile19=$srcDir$fileName19
srcFile20=$srcDir$fileName20
srcFile21=$srcDir$fileName21
srcFile22=$srcDir$fileName22
srcFile23=$srcDir$fileName23
srcFile24=$srcDir$fileName24
srcFile25=$srcDir$fileName25
srcFile26=$srcDir$fileName26
srcFile27=$srcDir$fileName27
srcFile28=$srcDir$fileName28
srcFile29=$srcDir$fileName29
srcFile30=$srcDir$fileName30

voms-proxy-init -voms cms

xrdcp $srcFile01 /tmp/$USER/ && sleep 5
xrdcp $srcFile02 /tmp/$USER/ && sleep 5
xrdcp $srcFile03 /tmp/$USER/ && sleep 5
xrdcp $srcFile04 /tmp/$USER/ && sleep 5
xrdcp $srcFile05 /tmp/$USER/ && sleep 5
xrdcp $srcFile06 /tmp/$USER/ && sleep 5
xrdcp $srcFile07 /tmp/$USER/ && sleep 5
xrdcp $srcFile08 /tmp/$USER/ && sleep 5
xrdcp $srcFile09 /tmp/$USER/ && sleep 5
xrdcp $srcFile10 /tmp/$USER/ && sleep 5
xrdcp $srcFile11 /tmp/$USER/ && sleep 5
xrdcp $srcFile12 /tmp/$USER/ && sleep 5
xrdcp $srcFile13 /tmp/$USER/ && sleep 5
xrdcp $srcFile14 /tmp/$USER/ && sleep 5
xrdcp $srcFile15 /tmp/$USER/ && sleep 5
xrdcp $srcFile16 /tmp/$USER/ && sleep 5
xrdcp $srcFile17 /tmp/$USER/ && sleep 5
xrdcp $srcFile18 /tmp/$USER/ && sleep 5
xrdcp $srcFile19 /tmp/$USER/ && sleep 5
xrdcp $srcFile20 /tmp/$USER/ && sleep 5
xrdcp $srcFile21 /tmp/$USER/ && sleep 5
xrdcp $srcFile22 /tmp/$USER/ && sleep 5
xrdcp $srcFile23 /tmp/$USER/ && sleep 5
xrdcp $srcFile24 /tmp/$USER/ && sleep 5
xrdcp $srcFile25 /tmp/$USER/ && sleep 5
xrdcp $srcFile26 /tmp/$USER/ && sleep 5
xrdcp $srcFile27 /tmp/$USER/ && sleep 5
xrdcp $srcFile28 /tmp/$USER/ && sleep 5
xrdcp $srcFile29 /tmp/$USER/ && sleep 5
xrdcp $srcFile30 /tmp/$USER/ && sleep 5

EOF


#cmsRun ey_ptEff_mc.py >& GenWev_newFin2_er.log
cmsRun ey_newL1Skim_qcd50.py >& QCD50_01_newL1for72X.log
sleep 3
eos cp QCD50_01_newL1for72X.root /eos/cms/store/group/phys_top/triggerStudies/skims/
sleep 3
rm Wev_newL1for72X.root
sleep 3
#. prod_make.sh

echo "run_util.sh completed successfully."
