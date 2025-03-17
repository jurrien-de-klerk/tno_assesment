#!/usr/bin/env bash

set -e

function delete_command {
    echo " >>> $*"
    "$@"
}

SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &>/dev/null && pwd)"
IMAGE_NAME="klerk/assignment/build-env"
BUILD_DIR="manual_build"

delete_command rm -rf "$SCRIPT_DIR/$BUILD_DIR"
delete_command docker image rm "$IMAGE_NAME"
