# Set up cmake
cmake_minimum_required (VERSION 2.6)
project (qt_push_button_hover_sound CXX C)
add_compile_options(-std=c++17 -Wall -Wextra)
set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR})

# Find LIbrary
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets Multimedia)
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTORCC ON)


# Add code
add_subdirectory(src)
