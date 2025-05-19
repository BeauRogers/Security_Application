#!/bin/bash

# Function to clean build files
clean() {
    echo "Cleaning build files..."
    rm -rf build/
    rm -f CMakeCache.txt
    rm -f CMakeFiles/
    rm -f cmake_install.cmake
    rm -f Makefile
    echo "Clean complete!"
}

# Function to build the project
build() {
    echo "Building project..."
    mkdir -p build
    cd build
    cmake ..
    make
    cd ..
    echo "Build complete!"
}

# Function to run the executable
run() {
    echo "Running ButtonApp..."
    if [ -f "build/ButtonApp" ]; then
        ./build/ButtonApp
    else
        echo "Error: ButtonApp executable not found. Please build the project first."
        exit 1
    fi
}

# Parse command line arguments
BUILD=false
CLEAN=false
RUN=false

# Process arguments - clean is checked first to ensure it runs before build
for arg in "$@"
do
    case $arg in
        "--clean")
            CLEAN=true
            ;;
        "--build")
            BUILD=true
            ;;
        "--run")
            RUN=true
            ;;
        *)
            echo "Unknown argument: $arg"
            echo "Usage: ./build.sh [--build] [--clean] [--run]"
            exit 1
            ;;
    esac
done

# Execute commands based on arguments
if [ "$CLEAN" = true ]; then
    clean
fi

if [ "$BUILD" = true ]; then
    build
fi

# Run is always executed last
if [ "$RUN" = true ]; then
    run
fi

# If no arguments provided, show usage
if [ "$BUILD" = false ] && [ "$CLEAN" = false ] && [ "$RUN" = false ]; then
    echo "Usage: ./build.sh [--build] [--clean] [--run]"
    echo "Options:"
    echo "  --build    Build the project"
    echo "  --clean    Clean build files"
    echo "  --run      Run the executable"
    echo "  --build --clean    Clean and rebuild the project"
    echo "  --build --run      Build and run the project"
    echo "  --build --clean --run    Clean, rebuild, and run the project"
fi 