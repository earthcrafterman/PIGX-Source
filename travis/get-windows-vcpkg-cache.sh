#!/usr/bin/env bash

set -euxo pipefail

mkdir -p C:\vcpkg2
cd C:\vcpkg2
curl --retry 5 --connect-timeout 30 --location --remote-header-name --output installed.zip $VCPKG_CACHE_ZIP_URL
unzip -uo installed.zip > /dev/null
mkdir ports
mkdir triplets
mkdir triplets/community
./vcpkg.exe integrate install
