cmake_minimum_required(VERSION 3.10)
project(ColoredButtonsApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set SFML_DIR if SFML is installed in a non-standard location
# Uncomment and modify the path if needed
#set(SFML_DIR "/opt/homebrew/Cellar/sfml/3.0.0_1/lib/cmake/SFML")

# Find SFML package - updated for SFML 3.0
find_package(SFML 3.0.0 COMPONENTS Graphics Window System REQUIRED)

# Include SFML directories
if (SFML_FOUND)
   include_directories(${SFML_INCLUDE_DIR})
   include_directories("/opt/homebrew/Cellar/sfml/3.0.0_1/include")
endif()

# Add the current directory to the library search path
link_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Include directories
include_directories(${CMAKE_SOURCE_DIR})

# Add source files
add_executable(ColoredButtonsApp 
    main.cpp
    api/api_interface.cpp
)

# Link SFML libraries - updated for SFML 3.0
target_link_libraries(ColoredButtonsApp sfml-graphics sfml-window sfml-system)

# Print SFML information for debugging
message(STATUS "SFML: ${SFML}")
message(STATUS "SFML_FOUND: ${SFML_FOUND}")
message(STATUS "SFML_DIR: ${SFML_DIR}")