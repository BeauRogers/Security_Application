# Colored Buttons Application

A simple C++ application that displays 4 colored buttons on a screen. Each button calls a different function from an API interface class located in a separate folder.

## Prerequisites

- CMake (version 3.10 or higher)
- C++ compiler with C++17 support
- SFML library (version 2.5 or higher)

## Building the Application

### On macOS

1. Install SFML using Homebrew:
   ```
   brew install sfml
   ```

2. Create a build directory and navigate to it:
   ```
   mkdir build
   cd build
   ```

3. Generate the build files:
   ```
   cmake ..
   ```

4. Build the application:
   ```
   make
   ```

### On Linux

1. Install SFML:
   ```
   sudo apt-get install libsfml-dev
   ```

2. Follow the same build steps as for macOS.

### On Windows

1. Install SFML using vcpkg or download from the SFML website.
2. Use CMake GUI or command line to generate build files.
3. Build using your preferred build system.

## Running the Application

After building, run the application:

```
./ColoredButtonsApp
```

## Project Structure

- `main.cpp`: Contains the main application code with the UI and button handling
- `api/api_interface.h`: Header file for the API interface class
- `api/api_interface.cpp`: Implementation of the API interface class
- `CMakeLists.txt`: CMake configuration file

## How It Works

The application creates a window with 4 colored buttons (red, green, blue, and yellow). When a button is clicked, it calls the corresponding function in the API interface class. The API interface functions currently just print messages to the console, but you can extend them to perform actual API operations. 