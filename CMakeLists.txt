cmake_minimum_required(VERSION 3.24)
project ("RunAndShoot")

#Build libraries staticly to not need dll files.
set(BUILD_SHARED_LIBS OFF)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_subdirectory(src)

#add vendor (libraries)
add_subdirectory(external)