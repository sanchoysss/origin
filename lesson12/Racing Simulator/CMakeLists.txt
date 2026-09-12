# CMakeList.txt: проект CMake для Racing Simulator; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.10)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Racing Simulator")

if (MSVC)
  add_compile_options("/utf-8")
endif()

include_directories(headers)

add_library(DynamicLib SHARED 
    source/Transport.cpp
    source/Race.cpp
    source/Ground.cpp
    source/Air.cpp
    source/Camel.cpp
    source/FastCamel.cpp
    source/Centaur.cpp
    source/Boots.cpp
    source/MagicCarpet.cpp
    source/Eagle.cpp
    source/Broom.cpp

)
target_compile_definitions(DynamicLib PRIVATE RACING_LIBRARY_EXPORTS)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (CMakeTarget "main.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeTarget PROPERTY CXX_STANDARD 20)
endif()

target_link_libraries(CMakeTarget PRIVATE DynamicLib)
