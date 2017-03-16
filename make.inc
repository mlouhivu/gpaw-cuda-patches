####################################################################
#  make include file.                                              #
####################################################################
#
SHELL = /bin/sh

# ----------------------------------------------------------------------
# - gpaw-cuda Directory Structure / gpaw-cuda library --------------------
# ----------------------------------------------------------------------
#
TOPdir        = .
INCdir        = $(TOPdir)
PYTHONINCdir ?= $(PYTHONHOME)/include/python2.7/
PYTHONLIBdir ?= $(PYTHONHOME)/lib/
NUMPYINCdir  ?= `python -c "import numpy; print numpy.get_include()"`
MPIINCdir    ?= /appl/opt/cluster_studio_xe2013/impi/4.1.3.045/intel64/include/
LIBdir        = $(TOPdir)
CUGPAWLIB     = $(LIBdir)/libgpaw-cuda.a 

#
# Libxc
#
LIBXC_INC = $(LIBXCDIR)/include

#
# MKL
#
MKL_INC = $(MKLROOT)/include

#
# ----------------------------------------------------------------------
# - NVIDIA CUDA includes / libraries / specifics -----------------------
# ----------------------------------------------------------------------
CUDAINCdir    = $(CUDADIR)/include
CUDALIBdir    = $(CUDADIR)/lib64
CUDA_OPTS     = 

#
# ----------------------------------------------------------------------
# - gpaw-cuda includes / libraries / specifics -------------------------------
# ----------------------------------------------------------------------
#

CUGPAW_INCLUDES = -I$(INCdir) -I$(CUDAINCdir) -I$(MPIINCdir) -I$(NUMPYINCdir)  -I$(PYTHONINCdir) -I$(LIBXC_INC) -I$(MKL_INC)
CUGPAW_OPTS     = -DPARALLEL=1 -DGPAW_CUDA=1 -lxc

#
# ----------------------------------------------------------------------
#

CUGPAW_DEFS     = $(CUGPAW_OPTS) $(CUDA_OPTS)  $(CUGPAW_INCLUDES)

#
# ----------------------------------------------------------------------
# - Compilers / linkers - Optimization flags ---------------------------
# ----------------------------------------------------------------------

CC           = icc
CCNOOPT      = $(CUGPAW_DEFS)
CCFLAGS      = $(CUGPAW_DEFS) -fPIC -std=c99 -m64 -O3

NVCC           = nvcc -ccbin=icpc
NVCCFLAGS      = $(CUGPAW_DEFS) -O3 -arch=sm_20 -m64 --compiler-options '-fPIC -O3' 


ARCH     = ar
ARCHFLAGS= cr
RANLIB   = ranlib


