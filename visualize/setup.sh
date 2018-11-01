me="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
echo $me

export VIS_TOPDIR=$me
export VIS_LIBDIR=$me/lib
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$VIS_LIBDIR
export PYTHONPATH=$VIS_TOPDIR/python:$PYTHONPATH
