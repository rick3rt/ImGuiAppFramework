# CMake 3.19 is the earliest tested version that works on both Windows and Linux
cmake_minimum_required(VERSION 3.19 FATAL_ERROR)
project(EXAMPLE_PROJECT VERSION 1.0.0 LANGUAGES CXX)

# ########################################################################################
# # User build options
# The preferred method for setting these options is to use command line flags when
# invoking cmake. See the README.md for details.

# ########################################################################################
# # Global flags
if(NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED True)
endif()

# if(NOT DEFINED CMAKE_CUDA_STANDARD)
# set(CMAKE_CUDA_STANDARD 17)
# set(CMAKE_CUDA_STANDARD_REQUIRED True)
# endif()

# # Set the -fPIC flag
# set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# ########################################################################################
# If no CUDA architecture is supplied, nvcc will rely on just-in-time compilation for the architecture
# of the actual present GPU, which can lead to a long delay the first time the code is executed.
# To avoid this delay, specify the -DCMAKE_CUDA_ARCHITECTURES=XX option, where XX is your device's
# compute capability as a 2-digit number, e.g., 61, 70, etc.
# set(CMAKE_CUDA_ARCHITECTURES 61 72 86)
# message("CMAKE_CUDA_ARCHITECTURES: ${CMAKE_CUDA_ARCHITECTURES}")
# message("CUDA_ARCHITECTURES: ${CUDA_ARCHITECTURES}")

# if(NOT DEFINED CMAKE_CUDA_ARCHITECTURES)
# message(WARNING "No CMAKE_CUDA_ARCHITECTURES provided. Relying on JIT compilation.")
# # set(CMAKE_CUDA_ARCHITECTURES OFF)  # Rely on JIT compilation
# endif()

# ########################################################################################
# Logging is performed using the spdlog library for fast C++ logging.
# FetchContent_Declare(
# spdlog
# GIT_REPOSITORY https://github.com/gabime/spdlog
# GIT_TAG eb3220622e73a4889eee355ffa37972b3cac3df5
# )
# set(spdlog_force_shared_crt ON CACHE BOOL "" FORCE)
# FetchContent_MakeAvailable(googletest spdlog)

# ########################################################################################
# Build flags
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG=1")

# set(CUDA_NVCC_FLAGS -Xcompiler -fPIC -use_fast_math -gencode=arch=compute_20,code="sm_20,compute_20" --ptxas-options=-v -DMATLAB_MEX_FILE -G -g -O0)
# set(CUDA_NVCC_FLAGS -Xcompiler -fPIC -use_fast_math --ptxas-options=-v -DMATLAB_MEX_FILE -G -g -O0 -R2018a)
# set(CMAKE_CUDA_FLAGS_DEBUG "${CMAKE_CUDA_FLAGS_DEBUG} -lineinfo")

# ########################################################################################
# Find dependencies
# find_package(CUDA 11.4 REQUIRED)
# find_package(Matlab 9.6 REQUIRED)

# find_package(glfw3 REQUIRED)
# find_package(OpenGL REQUIRED)
# find_package(GLEW REQUIRED)

# find_package(OpenMP REQUIRED)

# Include these directories for all subdirectories
# include_directories(CUDA_INCLUDE_DIRS)
add_subdirectory(myApp)
add_subdirectory(lib)

# ########################################################################################
# Generate Target List
# See: https://discourse.cmake.org/t/cmake-list-of-all-project-targets/1077/17

# function(_get_all_cmake_targets out_var current_dir)
# get_property(targets DIRECTORY ${current_dir} PROPERTY BUILDSYSTEM_TARGETS)
# get_property(subdirs DIRECTORY ${current_dir} PROPERTY SUBDIRECTORIES)

# foreach(subdir ${subdirs})
# _get_all_cmake_targets(subdir_targets ${subdir})
# list(APPEND targets ${subdir_targets})
# endforeach()

# set(${out_var} ${targets} PARENT_SCOPE)
# endfunction()

# # Run at end of top-level CMakeLists
# _get_all_cmake_targets(all_targets ${CMAKE_CURRENT_LIST_DIR})
# string(REPLACE ";" "\n" all_targets "${all_targets}")

# # message("TARGETS: ${all_targets}" )
# FILE(WRITE ./target_list.txt
# "${all_targets}"
# )
