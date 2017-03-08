###################################################################################
#
# BCMTools
#
# Copyright (c) 2011-2014 Institute of Industrial Science, The University of Tokyo.
# All rights reserved.
#
# Copyright (c) 2012-2016 Advanced Institute for Computational Science (AICS), RIKEN.
# All rights reserved.
#
# Copyright (c) 2017 Research Institute for Information Technology (RIIT), Kyushu University.
# All rights reserved.
#
###################################################################################

set(CMAKE_SYSTEM_NAME Linux)

include(CMakeForceCompiler)

# CMAKE_FORCE_Fortran_Compiler is not supported ver. 2.6
# A : cmake version >= 2.7
# B : cmake version < 2.7

if (CMAKE_MAJOR_VERSION GREATER 2)
  set(build_rule "A")
else()
  if(CMAKE_MINOR_VERSION GREATER 6)
    set(build_rule "A")
  else()
    set(build_rule "B")
  endif()
endif()


if(with_MPI)
  CMAKE_FORCE_C_COMPILER(mpifccpx GNU)
  CMAKE_FORCE_CXX_COMPILER(mpiFCCpx GNU)
  CMAKE_FORCE_Fortran_COMPILER(mpifrtpx GNU)
  if (build_rule STREQUAL "A")
    CMAKE_FORCE_Fortran_COMPILER(mpifrtpx GNU)
  else()
    set(CMAKE_Fortran_COMPILER mpifrtpx)
    set(CMAKE_Fortran_COMPILER_WORKS true)
  endif()

else()
  CMAKE_FORCE_C_COMPILER(fccpx GNU)
  CMAKE_FORCE_CXX_COMPILER(FCCpx GNU)
  CMAKE_FORCE_Fortran_COMPILER(frtpx GNU)
  if (build_rule STREQUAL "A")
    CMAKE_FORCE_Fortran_COMPILER(frtpx GNU)
  else()
    set(CMAKE_Fortran_COMPILER frtpx)
    set(CMAKE_Fortran_COMPILER_WORKS true)
  endif()
endif()

set(CMAKE_FIND_ROOT_PATH /opt/FJSVfxlang/1.2.1)   # RIIT fx10, hayaka
set(CMAKE_INCLUDE_PATH /opt/FJSVfxlang/1.2.1/include)
set(CMAKE_LIBRARY_PATH /opt/FJSVfxlang/1.2.1/lib64)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

#set(CMAKE_CXX_FLAGS "-Xg -std=gnu++03"  CACHE STRING "" FORCE)
#set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -Kparallel"  CACHE STRING "" FORCE)

## Flag for cross-compiling
set(BCM_CROSS_OPTION "ON")

set(TARGET_ARCH "K")