## Description

Some patches for the CUDA version of GPAW to make it run with newer versions
of the CUDA software stack.

## Usage

#### Obtain source code for the CUDA version of GPAW

Source code is available in GPAW's repository as a separate branch called
'cuda'. To obtain the code, use e.g. the following commands:
```
  git clone https://gitlab.com/gpaw/gpaw.git
  cd gpaw
  git checkout cuda
```


#### Apply patches

Script 'apply.sh' can be used to automatically apply all the patches to the
source code, e.g.

```
bash apply.sh /path/to/gpaw-cuda-source-code
```

or alternatively you can copy the patches to the source code directory and
apply them manually with
```
# patch CUDA version limit
patch gpaw/gpuarray.py patch-gpuarray.diff
# patch XC headers
patch c/xc/xc_gpaw.h patch-xc_gpaw.diff
patch c/xc/xc_mgga.h patch-xc_mgga.diff
# patch eigensolver/mode check
patch gpaw/paw.py patch-paw.diff
# patch GPGPU pinning on exclusive nodes
patch gpaw/cuda.py patch-cuda.diff
```

#### Copy (and modify) setup scripts

Example GPAW setup script (customize-cuda.py) and Make include file for the
CUDA part (make.inc) are also available. Modify them to match your system and
then copy them to the source code directory, e.g. with
```
tgt=/path/to/gpaw-cuda-source-code
cp customize-cuda.py $tgt/
cp make.inc $tgt/c/cuda/
```

