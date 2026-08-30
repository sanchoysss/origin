cmake_minimum_required (VERSION 3.10)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("task3")

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(LibraryDynamic SHARED "LibraryDynamic.h" "LibraryDynamic.cpp")
 
add_executable (task3 "main.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET task3 PROPERTY CXX_STANDARD 20)
endif()

target_link_libraries(task3 LibraryDynamic)