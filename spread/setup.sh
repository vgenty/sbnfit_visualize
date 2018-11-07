me="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
echo $me

export SPREAD_TOPDIR=$me
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$SPREAD_TOPDIR
