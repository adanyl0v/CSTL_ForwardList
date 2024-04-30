#!/bin/bash

read -p "Enter the build configuration: " CONFIG
cmake --build "build/$CONFIG" --config $CONFIG
