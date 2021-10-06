#!/usr/bin/env bash

set -euxo pipefail

./travis/install-local-dependencies.sh windows
./travis/get-windows-vcpkg-cache.sh
./travis/get-windows-d3d9sdk.sh