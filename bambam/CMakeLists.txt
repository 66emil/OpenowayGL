cmake_minimum_required(VERSION 3.25)
project(bambam)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

# Включение заголовочных файлов GLFW и OpenGL
include_directories(${OPENGL_INCLUDE_DIRS})
include_directories(${glfw3_INCLUDE_DIRS})

set(SOURCES
        main.cpp
        # Добавьте остальные файлы вашей игры здесь
        )

add_executable(bambam ${SOURCES})

target_link_libraries(bambam glfw ${OPENGL_LIBRARIES})
