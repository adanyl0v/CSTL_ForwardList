#!/bin/bash

read -p "Enter the installation config: " CONFIG

# Comment next line to keep installed other library versions
rm -rf /usr/local/lib/libCSTL_ForwardList.so*

cmake --install "build/$CONFIG" --config $CONFIG
