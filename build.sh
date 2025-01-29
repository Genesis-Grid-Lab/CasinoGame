#!/bin/bash

#$VULKAN_SDK/bin/glslc Resources/Shader/shader.vert -o Resources/Shader/vert.spv
#$VULKAN_SDK/bin/glslc Resources/Shader/shader.frag -o Resources/Shader/frag.spv

target="out/$1"

cmake -B $target -S . -DCMAKE_BUILD_TYPE=$1
cmake --build $target --config $1

