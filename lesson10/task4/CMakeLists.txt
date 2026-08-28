cmake_minimum_required (VERSION 3.10)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("task4")

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(FiguresLibrary SHARED
    Figure.cpp
    Figure.h
    Triangle.cpp
    Triangle.h
    RightTriangle.cpp
    RightTriangle.h
    IsoscelesTriangle.cpp
    IsoscelesTriangle.h
    EquilateralTriangle.cpp
    EquilateralTriangle.h
    Quadrilateral.cpp
    Quadrilateral.h
    Rectangle.cpp
    Rectangle.h
    Square.cpp
    Square.h
    Parallelogram.cpp
    Parallelogram.h
    Rhombus.cpp
    Rhombus.h
)
add_executable (task4 "main.cpp" "main.h")


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET task4 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
target_link_libraries(task4 PRIVATE FiguresLibrary)