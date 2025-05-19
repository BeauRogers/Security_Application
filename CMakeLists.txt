cmake_minimum_required(VERSION 3.10)
project(ButtonApp)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# If you installed SFML via homebrew, this should help find it
set(SFML_DIR "/opt/homebrew/Cellar/sfml/3.0.0_1/lib/cmake/SFML")

# Find SFML
find_package(SFML 3.0 REQUIRED COMPONENTS Graphics Window)

# Include SFML directories
if (SFML_FOUND)
   include_directories(${SFML_INCLUDE_DIR})
   include_directories("/opt/homebrew/Cellar/sfml/3.0.0_1/include")
endif()

# Add the current directory to the library search path
link_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Include directories
include_directories(${CMAKE_SOURCE_DIR})

# Add nlohmann_json
include(FetchContent)
FetchContent_Declare(
    json
    URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz
)
FetchContent_MakeAvailable(json)

# Add source files
add_executable(ButtonApp 
    main.cpp
    api/api_interface.cpp
    button.cpp
    main_screen.cpp
)

# Link SFML libraries - updated for SFML 3.0
target_link_libraries(ButtonApp sfml-graphics sfml-window sfml-system nlohmann_json::nlohmann_json)

# If you're on macOS, you might need these framework links
#if(APPLE)
#    target_link_libraries(ButtonApp PRIVATE
#        "-framework OpenGL"
#        "-framework GLUT"
#    )
#endif()