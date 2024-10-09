# CMakeList.txt : CMake project for code, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("code") # Project name

set(PROJECT_SOURCE
	code.cpp 
	code.h
	) 
# Source directory
set(SOURCE_DIR
	${CMAKE_CURRENT_SOURCE_DIR}/src
)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/ch01)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/ch02)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/ch03)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/ch04)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/ch05)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/ch06)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/ch07)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/ch08)



# Add source to this project's executable.
add_executable (code ${PROJECT_SOURCE}) # Main source file

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET code PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
