#!/usr/bin/env bash

set -euxo pipefail
ARCH=${ARCH:-"x64"}

./travis/install-local-dependencies.sh
./travis/get-windows-vcpkg-cache.sh
./travis/get-windows-d3d9sdk.sh
