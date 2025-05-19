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

# Parse command line arguments
BUILD=false
CLEAN=false

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
        *)
            echo "Unknown argument: $arg"
            echo "Usage: ./build.sh [--build] [--clean]"
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

# If no arguments provided, show usage
if [ "$BUILD" = false ] && [ "$CLEAN" = false ]; then
    echo "Usage: ./build.sh [--build] [--clean]"
    echo "Options:"
    echo "  --build    Build the project"
    echo "  --clean    Clean build files"
    echo "  --build --clean    Clean and rebuild the project"
fi 