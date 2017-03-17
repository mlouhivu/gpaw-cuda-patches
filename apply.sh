#!/bin/bash
if [ $# -ne 1 ]
then
	echo 'Usage: bash apply.sh /path/to/gpaw-cuda-source-code'
	exit
fi
if [ ! -e $1 ] || [ ! -d $1 ]
then
	echo "Target does not exist or is not a directory: $1"
	exit
fi

# location of GPAW sources
tgt=$1
echo "Applying patches to: $tgt"

# patch CUDA version limit
patch $tgt/gpaw/gpuarray.py patch-gpuarray.diff
# patch XC headers
patch $tgt/c/xc/xc_gpaw.h patch-xc_gpaw.diff
patch $tgt/c/xc/xc_mgga.h patch-xc_mgga.diff
# patch eigensolver/mode check
patch $tgt/gpaw/paw.py patch-paw.diff
# patch GPGPU pinning on exclusive nodes
patch $tgt/gpaw/cuda.py patch-cuda.diff

