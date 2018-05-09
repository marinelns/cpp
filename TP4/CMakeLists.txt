cmake_minimum_required(VERSION 2.8.11)
project(libOcean)
set(CMAKE_CXX_FLAGS "-g -Wall -Wextra")


find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

add_subdirectory(src)
#add_subdirectory(test)
add_executable(Dvector tests/mainDvector.cpp)
add_executable(Height tests/mainHeight.cpp)
add_executable(Ocean src/main.cxx)
target_link_libraries(Dvector PUBLIC libOcean)
target_include_directories(Dvector PUBLIC libOcean)
target_link_libraries(Height PUBLIC libOcean)
target_include_directories(Height PUBLIC libOcean)
target_link_libraries(Ocean ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} libOcean)
target_include_directories(Ocean PUBLIC libOcean)
