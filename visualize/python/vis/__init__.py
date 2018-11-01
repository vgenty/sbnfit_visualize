import os

if not 'VIS_TOPDIR' in os.environ:
    print '$VIS_BASEDIR shell env. var. not found (run configure.sh)'
    raise ImportError
vis_dir = os.environ['VIS_LIBDIR']

import ROOT
for l in [x for x in os.listdir(vis_dir) if x.endswith('.so')]:
    print "@l=",l,"load=",ROOT.gSystem.Load(l)

from ROOT import vis
vis.LoadVIS()
