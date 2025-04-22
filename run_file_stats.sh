#!/bin/bash

# Check if the input file exists
if [ ! -f "$1" ]; then
    echo "File not found! Please provide a valid filename."
    exit 1
fi

# Compile the C program
gcc -o file_stats file_stats.c

# Check if compilation was successful
if [ $? -ne 0 ]; then
    echo "Compilation failed!"
    exit 1
fi

# Run the C program with the provided file
./file_stats "$1"

# Ask the user if they want to modify the file
read -p "Do you want to modify the file? (y/n): " choice

if [ "$choice" == "y" ]; then
    nano "$1"  # You can replace 'nano' with your preferred text editor
    echo "File modified. Re-running the program..."
    ./file_stats "$1"
else
    echo "Exiting."
fi
