cmake_minimum_required(VERSION 3.16)

project(openGL)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(EXE main)
set(RUN_DIR ${PROJECT_SOURCE_DIR})
set(sources main.cpp)

find_package(OpenGL REQUIRED COMPONENTS OpenGL)
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)

add_executable(${EXE} ${sources})
add_dependencies(${EXE} OpenGL::OpenGL)
include_directories(${GLUT_INCLUDE_DIRS} )
include_directories(${GLEW_INCLUDE_DIRS} )
target_link_libraries(${EXE} OpenGL::OpenGL ${GLEW_LIBRARIES} glfw)
set_target_properties(${EXE} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${RUN_DIR})
