cmake_minimum_required(VERSION 3.23.0)

project(MetaSystem)

add_library(MetaSystem SHARED Any.h Any.cpp MetaInfo.cpp MetaInfo.h)
add_subdirectory(MetaSystem_ut)