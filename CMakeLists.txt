cmake_minimum_required(VERSION 3.13)

project(api_app CXX)

find_package(PkgConfig)
pkg_check_modules(LIBCGICC REQUIRED cgicc)

add_executable(api_app main.cpp)
target_include_directories(api_app PRIVATE ${LIBCGICC_INCLUDE_DIRS})
target_link_libraries(api_app ${LIBCGICC_LIBRARIES})