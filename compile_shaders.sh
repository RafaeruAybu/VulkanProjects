#!/bin/bash

# This script generates SPIR-V bytecode.

GLSLC_PATH=/usr/local/bin/glslc
SHADER_DIR=./shaders

${GLSLC_PATH} ${SHADER_DIR}/shader.vert -o ${SHADER_DIR}/vert.spv
${GLSLC_PATH} ${SHADER_DIR}/shader.frag -o ${SHADER_DIR}/frag.spv

