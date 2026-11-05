# Минимальная версия CMake
cmake_minimum_required(VERSION 3.10)

# Имя нашего учебного решения
project(Catch2Homework)

# Подключаем готовую папку с библиотекой Catch2
add_subdirectory(catch2)


add_executable(task1_tests task1.cpp)
target_link_libraries(task1_tests PRIVATE Catch2::Catch2 Catch2::Catch2WithMain)


add_executable(task2_tests task2.cpp)
target_link_libraries(task2_tests PRIVATE Catch2::Catch2 Catch2::Catch2WithMain)
