add_executable (ch08 "ch08.cpp")
# Set C++ standard for the ch08 target
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ch08 PROPERTY CXX_STANDARD 20)
endif()