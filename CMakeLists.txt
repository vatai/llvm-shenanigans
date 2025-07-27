cmake_minimum_required(VERSION 3.28.0)

# set(CMAKE_C_COMPILER clang)
# set(CMAKE_CXX_COMPILER clang++)
# set(ENV{CMAKE_fortran_COMPILER_ENV_VAR} "${CMAKE_SOURCE_DIR}/deps/opt/bin/flang")
set(CMAKE_fortran_COMPILER "${CMAKE_SOURCE_DIR}/deps/opt/bin/flang")
if(NOT EXISTS ${CMAKE_fortran_COMPILER})
  message(WARNING "FLANG DOESN'T EXIST")
endif()

project(llvm-shenanigans VERSION 0.2.2)
enable_language(fortran)
include(FortranCInterface)

find_package(LLVM 20.1 REQUIRED CONFIG
  HINTS
  ${CMAKE_SOURCE_DIR}/deps/opt)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Found LLVM_DIR ${LLVM_DIR}")

include_directories(${LLVM_INCLUDE_DIRS})
separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
add_definitions(${LLVM_DEFINITIONS_LIST})
add_definitions(-DFLANG_LITTLE_ENDIAN)

# Now build our tools
add_executable(main src/main.cc)

# Find the libraries that correspond to the LLVM components
# that we wish to use
llvm_map_components_to_libnames(all)

# Link against LLVM libraries
target_link_libraries(main LLVMSupport flangFrontend)
