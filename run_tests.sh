#!/usr/bin/env bash

set -e

SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &>/dev/null && pwd)"
IMAGE_NAME="klerk/assignment/build-env"
BUILD_DIR="manual_build"

"$SCRIPT_DIR"/build.sh

echo " >>>"
echo " >>> Starting the simulation..."
echo " >>>"
docker run --rm -it --volume "$SCRIPT_DIR":/workspace "$IMAGE_NAME" /workspace/"$BUILD_DIR"/test/unit_tests
