cmake_minimum_required(VERSION 3.28.0)

project(llvm-shenanigans VERSION 0.2.2)

enable_language(Fortran)
include(FortranCInterface)

find_package(LLVM 20.1 REQUIRED CONFIG
  HINTS
  ${CMAKE_SOURCE_DIR}/deps/opt)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Found LLVM_DIR ${LLVM_DIR}")

include_directories(${LLVM_INCLUDE_DIRS})
message(STATUS "include_directories ${LLVM_INCLUDE_DIRS}")
separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
add_definitions(${LLVM_DEFINITIONS_LIST})
add_definitions(-DFLANG_LITTLE_ENDIAN)

# Find the libraries that correspond to the LLVM components
# that we wish to use
llvm_map_components_to_libnames(all)

# Now build our tools
add_executable(main src/main.cc)
target_link_libraries(main LLVMSupport)

