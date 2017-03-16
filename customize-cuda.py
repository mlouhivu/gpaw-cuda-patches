# Setup customisation for gpaw/cuda
import os

# compiler and linker
compiler = 'icc'
mpicompiler = 'mpicc'
mpilinker = 'mpicc'
extra_compile_args = ['-std=c99']

# libraries
libraries = ['z']

# use MKL
mklroot = os.environ['MKLROOT']
library_dirs += [mklroot + '/lib/intel64']
include_dirs += [mklroot + '/include']
libraries += ['mkl_intel_lp64', 'mkl_intel_thread', 'mkl_core',
              'mkl_lapack95_lp64', 'mkl_scalapack_lp64',
              'mkl_blacs_intelmpi_lp64', 'iomp5', 'pthread'
             ]

# cuda
library_dirs += [os.environ['CUDALIB'], './c/cuda']
include_dirs += [os.environ['CUDADIR'] + '/include']
libraries += ['gpaw-cuda', 'cublas', 'cudart', 'stdc++']

# libxc
library_dirs += [os.environ['LIBXCDIR'] + '/lib']
include_dirs += [os.environ['LIBXCDIR'] + '/include']
libraries += ['xc']

# GPAW defines
define_macros += [('GPAW_NO_UNDERSCORE_CBLACS', '1')]
define_macros += [('GPAW_NO_UNDERSCORE_CSCALAPACK', '1')]
define_macros += [("GPAW_ASYNC",1)]
define_macros += [("GPAW_MPI2",1)]
define_macros += [('GPAW_CUDA', '1')]

# ScaLAPACK
scalapack = True

# HDF5
hdf5 = False

