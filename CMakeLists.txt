cmake_minimum_required(VERSION 3.18.4)
project(llvm-shenanigans VERSION 0.2.2)

# set(CMAKE_C_COMPILER clang)
# set(CMAKE_CXX_COMPILER clang++)

find_package(LLVM 20.1 REQUIRED CONFIG
  HINTS
  ${CMAKE_SOURCE_DIR}/deps/opt)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Found LLVM_DIR ${LLVM_DIR}")

add_definitions(-DFLANG_LITTLE_ENDIAN)
include_directories(${LLVM_INCLUDE_DIRS})
separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
add_definitions(${LLVM_DEFINITIONS_LIST})

# Now build our tools
add_executable(main src/main.cc)

# Find the libraries that correspond to the LLVM components
# that we wish to use
llvm_map_components_to_libnames(all)

# Link against LLVM libraries
target_link_libraries(main LLVMSupport)
