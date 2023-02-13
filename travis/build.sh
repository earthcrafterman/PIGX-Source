#!/usr/bin/env bash

set -euo pipefail

PICS_URL=${PICS_URL:-""}
FIELDS_URL=${FIELDS_URL:-""}
COVERS_URL=${COVERS_URL:-""}
DISCORD_APP_ID=${DISCORD_APP_ID:-""}
UPDATE_URL=${UPDATE_URL:-""}
ARCH=${ARCH:-"x64"}
TARGET_OS=${TARGET_OS:-""}
BUNDLED_FONT=""
if [[ -f "NotoSansJP-Regular.otf" ]]; then
	BUNDLED_FONT="--bundled-font=NotoSansJP-Regular.otf"
fi

if [[ -z "${VS_GEN:-""}" ]]; then
	./premake5.exe vs2017 --no-core=true --oldwindows=true --sound=sfml --no-joystick=true --pics=\"$PICS_URL\" --fields=\"$FIELDS_URL\" --covers=\"$COVERS_URL\" --discord=\"$DISCORD_APP_ID\" --update-url=\"$UPDATE_URL\"
	dotnet msbuild -m -p:Configuration=release -p:Platform=Win32 ./build/ygo.sln -t:ygoprodll -verbosity:minimal -p:EchoOff=true
	python.exe ./travis/patcher.py bin/release/ygoprodll.exe
else
	./premake5.exe $VS_GEN --no-core=true --sound=sfml --no-joystick=true --pics=\"$PICS_URL\" --fields=\"$FIELDS_URL\" --covers=\"$COVERS_URL\" --discord=\"$DISCORD_APP_ID\" --update-url=\"$UPDATE_URL\"
	dotnet msbuild -m -p:Configuration=release -p:Platform=Win32 ./build/ygo.sln -t:ygoprodll -verbosity:minimal -p:EchoOff=true
fi
exit 0
PREMAKE_FLAGS=""
if [[ -n "${ARCH:-""}" ]]; then
	PREMAKE_FLAGS=" --architecture=$ARCH"
fi
if [[ -n "${TARGET_OS:-""}" ]]; then
	PREMAKE_FLAGS="$PREMAKE_FLAGS --os=macosx"
fi
./premake5.exe gmake2 $PREMAKE_FLAGS --no-core=true --vcpkg-root=$VCPKG_ROOT --sound=sfml --no-joystick=true --pics=\"$PICS_URL\" --fields=\"$FIELDS_URL\" --covers=\"$COVERS_URL\" --discord=\"$DISCORD_APP_ID\" --update-url=\"$UPDATE_URL\"
