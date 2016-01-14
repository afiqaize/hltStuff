import ROOT, math

hecal = [];
hecal.append(ROOT.TH2F("hecal0", "hcal0", 170, -85, 85, 360,  0, 360))
hecal.append(ROOT.TH2F("hecal1", "hcal1", 100, 0, 100, 100, 0, 100))
hecal.append(ROOT.TH2F("hecal2", "hcal2", 100, 0, 100, 100, 0, 100))

file = open("run_203909.txt")
lines = file.readlines()
file.close()

Barrel = {}
Endcap = {}
isBarrel = True
for l in lines:
    if ("BARREL" in l):
        continue
    if ("ENDCAP" in l):
        isBarrel = False
        continue
    pos = l.split()
    if (isBarrel):
        hecal[0].SetBinContent(int(pos[0]), int(pos[1]), float(pos[3]))
    else:
        if (int(pos[2]) > 0):
            hecal[1].SetBinContent(int(pos[0]), int(pos[1]), float(pos[3]))
        else:
            hecal[2].SetBinContent(int(pos[0]), int(pos[1]), float(pos[3]))

c = ROOT.TCanvas("c", "c", 1200, 600)
c.Divide(2, 1)
for i in xrange(1,3):
    c.cd(i)
    hecal[i].GetZaxis().SetRangeUser(0.4, 1.2)
    hecal[i].Draw("COLZ")
    print hecal[i].GetMaximum(), hecal[i].GetMinimum()
raw_input()
