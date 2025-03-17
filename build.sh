#!/usr/bin/env bash

set -e

SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &>/dev/null && pwd)"
IMAGE_NAME="klerk/assignment/build-env"
BUILD_DIR="manual_build"

echo " >>>"
echo " >>> Building Docker image '${IMAGE_NAME}'..."
echo " >>>"
docker build "${SCRIPT_DIR}/.devcontainer/" --tag "${IMAGE_NAME}"

echo " >>>"
echo " >>> Building C++ code..."
echo " >>>"
docker run --rm -it --volume "$SCRIPT_DIR":/workspace --workdir /workspace "$IMAGE_NAME" cmake -B "$BUILD_DIR" -S .
docker run --rm -it --volume "$SCRIPT_DIR":/workspace --workdir /workspace "$IMAGE_NAME" cmake --build "$BUILD_DIR"
