cmake_minimum_required(VERSION 3.18.4)
project(llvm-shenanigans VERSION 0.2.2)

find_package(LLVM 20.1 REQUIRED CONFIG
  HINTS
  ${CMAKE_SOURCE_DIR}/deps/opt)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Found LLVM_DIR ${LLVM_DIR}")

add_executable(main src/main.cc)
