cmake_minimum_required(VERSION 2.8)

project(gaz)

# Найдём OpenGL
find_package(OpenGL REQUIRED)
# Найдём FreeGLUT
find_package(GLUT REQUIRED)

# Теперь можно выставить директории с header-ами
include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

#set(SOURCES no_headers/main.cpp no_headers/Container.cpp no_headers/SimpleTree.cpp) или ели хотим меньше кода:
file(GLOB SOURCES "headers/source/*.cpp" "*.cpp")


add_executable(gaz ${SOURCES})
# И указать библиотеки для линковки
target_link_libraries(gaz ${OPENGL_LIBRARIES} glut)


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)

include_directories("headers/")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")


