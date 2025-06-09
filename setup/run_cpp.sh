#!/usr/bin/env bash

file="$1"
basename="${file%.*}"

if [ -z "$file" ]; then
  echo "Usage: $0 <filename>"
  exit 1
fi

if [ ! -f "$file" ]; then
  echo "Error: File '$file' does not exist."
  exit 1
fi

# Compile the C++ file
g++ -std=c++17 -O3 -march=native "$file" -o "$basename"

if [ $? -ne 0 ]; then
  echo "Error: Compilation failed."
  exit 1
fi

# Make the output executable
chmod +x "$basename"

echo "Running $basename..."

/usr/bin/time -f "Execution time: %e seconds" ./"$basename" < input.txt > output.txt

# Run multiple times and average
 # for i in {1..5}; do
 # /usr/bin/time -f "Run $i: %e seconds" ./"$basename" < input.txt > output.txt
 # done
