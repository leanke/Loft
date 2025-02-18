#!/bin/bash

if [ -z "$1" ]; then
  echo "Usage: $0 <project_directory> [libraries]"
  exit 1
fi

PROJECT_DIR=$1
LIBRARIES=$2

make -f /home/leanke/loft/C/lib/Makefile PROJECT_DIR=$PROJECT_DIR LIBRARIES="$LIBRARIES"
# Usage - COMPILER=linux_clang DEBUG=1 ./build_project.sh /path/to/project [libraries]












