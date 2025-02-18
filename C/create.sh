#!/bin/bash
PROJECT_NAME=projects/$1
mkdir -p $PROJECT_NAME/{src,include,build}
touch $PROJECT_NAME/src/{main.c,$1.c}
touch $PROJECT_NAME/include/$1.h
cp README.md $PROJECT_NAME/README.md
cp LICENSE $PROJECT_NAME/LICENSE
