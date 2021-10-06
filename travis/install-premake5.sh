#!/usr/bin/env bash

set -euxo pipefail

PREMAKE_VERSION=${PREMAKE_VERSION:-5.0.0-alpha15}

curl --retry 5 --connect-timeout 30 --location --remote-header-name --remote-name https://github.com/premake/premake-core/releases/download/v$PREMAKE_VERSION/premake-$PREMAKE_VERSION-windows.zip
unzip -uo premake-$PREMAKE_VERSION-windows.zip
rm premake-$PREMAKE_VERSION-windows.zip