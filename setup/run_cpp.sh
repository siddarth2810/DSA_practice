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

g++ -std=c++17 "$file" -o "$basename" && chmod +x "$basename" && "./$basename" < input.txt > output.txt

