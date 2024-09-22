# Add source to this project's executable.
add_executable (ch01 ch01.cpp )
add_executable (ch01_5 ch01_5.cpp)
add_executable (ch01_5_2 ch01_5_2.cpp)
add_executable (exercise_121 exercise_121.cpp)
add_executable (exercise_122 exercise_122.cpp)
add_executable (exercise_123 exercise_123.cpp)
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ch01 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
