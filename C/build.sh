#!/bin/bash

if [ -z "$1" ]; then
  echo "Usage: $0 <project_directory> [libraries]"
  exit 1
fi

PROJECT_DIR=$1
shift
LIBRARIES="$@"

make -f /home/leanke/loft/C/Makefile PROJECT_DIR=$PROJECT_DIR LIBRARIES="$LIBRARIES"
# Usage - COMPILER=linux_clang DEBUG=1 ./build_project.sh /path/to/project [libraries]
