cmake_minimum_required(VERSION 3.13)

project(api_app CXX)

find_package(PkgConfig)
pkg_check_modules(LIBCGICC REQUIRED cgicc)
pkg_check_modules(LIBOPENCV4 REQUIRED opencv4)

add_executable(api_app main.cpp)
target_include_directories(api_app PRIVATE ${LIBCGICC_INCLUDE_DIRS} ${LIBOPENCV4_INCLUDE_DIRS})
target_link_libraries(api_app ${LIBCGICC_LIBRARIES} ${LIBOPENCV4_LIBRARIES})