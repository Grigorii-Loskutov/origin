cmake_minimum_required(VERSION 3.22.0)
project(FigureExemplar)
add_library(FigureDinamicLibrary SHARED Equilateral_Triangle.cpp Equilateral_Triangle.h Figure.cpp Figure.h Isosceles_Triangle.cpp Isosceles_Triangle.h Parallelogram.cpp Parallelogram.h Quadrangle.cpp Quadrangle.h Rectangle_.cpp Rectangle_.h Rectangular_Triangle.cpp Rectangular_Triangle.h Rhombus.cpp Rhombus.h Square.cpp Square.h Triangle.cpp Triangle.h)
set (CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_executable(FigureImplementation FigureImplementation.cpp)
target_link_libraries(FigureImplementation FigureDinamicLibrary)