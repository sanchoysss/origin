cmake_minimum_required(VERSION 3.10)
project(CombinedLabWork LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(CombinedLab
    main.cpp
    tasks.cpp
    math_functions.cpp
    counter.cpp
    Figure.cpp
    Triangle.cpp
    RightTriangle.cpp
    IsoscelesTriangle.cpp
    EquilateralTriangle.cpp
    Quadrilateral.cpp
    Parallelogram.cpp
    Rectangle.cpp
    Rhombus.cpp
    Square.cpp
)