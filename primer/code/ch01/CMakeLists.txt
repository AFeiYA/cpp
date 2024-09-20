# Add source to this project's executable.
set(PROJECT_SOURCE
  "ch01.cpp"
  "ch01.h"
)

add_executable (ch01 ${PROJECT_SOURCE}) 

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ch01 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
