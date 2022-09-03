#!/usr/bin/env bash

set -euxo pipefail

USE_IRRKLANG=${2:-""}

if [[ ! -z $USE_IRRKLANG ]]; then
    curl --retry 5 --connect-timeout 30 --location --remote-header-name --remote-name http://www.ambiera.at/downloads/irrKlang-64bit-1.6.0.zip
    echo Extracting irrKlang64...
    unzip -uo irrKlang-64bit-1.6.0.zip > /dev/null
    rm -rf irrKlang
    mv irrKlang-64bit-1.6.0 irrKlang
    rm irrKlang-64bit-1.6.0.zip

    if [[ "$TRAVIS_OS_NAME" == "osx" ]]; then  
        # For convenience with dylibbundler
        cp -f irrKlang/bin/macosx-gcc/libirrklang.dylib /usr/local/lib
    fi
fi

# We are locked to FreeType 2.6.5 for now because of TTF interpreter behaviour in newer versions
# curl --retry 5 --connect-timeout 30 --location --remote-header-name --remote-name http://downloads.sourceforge.net/freetype/freetype-2.6.5.tar.bz2
# echo Extracting FreeType...
# tar xf freetype-2.6.5.tar.bz2 > /dev/null
# mv freetype-2.6.5/builds freetype
# mv freetype-2.6.5/include freetype
# mv freetype-2.6.5/src freetype
# rm -rf freetype-2.6.5
# rm freetype-2.6.5.tar.bz2

if [[ ! -z $USE_IRRKLANG ]]; then
	# We wrap irrKlang32's extract because its zip has a hidden macOS directory that we don't want
	curl --retry 5 --connect-timeout 30 --location --remote-header-name --remote-name https://www.ambiera.at/downloads/irrKlang-32bit-1.6.0.zip
	echo Extracting irrKlang32...
	"C:\Program Files\7-Zip\7z.exe" x irrKlang-32bit-1.6.0.zip -d irrKlang-tmp
	# Merge 32-bit binaries into folder
	mv irrKlang-tmp/irrKlang-1.6.0/bin/win32-gcc irrKlang/bin/win32-gcc
	mv irrKlang-tmp/irrKlang-1.6.0/bin/win32-visualStudio irrKlang/bin/win32-visualStudio
	mv irrKlang-tmp/irrKlang-1.6.0/lib/Win32-gcc irrKlang/lib/Win32-gcc
	mv irrKlang-tmp/irrKlang-1.6.0/lib/Win32-visualStudio irrKlang/lib/Win32-visualStudio
	rm -rf irrKlang-tmp
	rm irrKlang-32bit-1.6.0.zip
fi

# install UPX
curl --retry 5 --connect-timeout 30 --location --remote-header-name --remote-name https://github.com/upx/upx/releases/download/v3.96/upx-3.96-win64.zip
"C:\Program Files\7-Zip\7z.exe" x upx-3.96-win64.zip
mv upx-3.96-win64/upx.exe upx.exe
rm -rf upx-3.96-win64
rm upx-3.96-win64.zip

curl --retry 5 --connect-timeout 30 --location --remote-header-name --remote-name https://github.com/edo9300/irrlicht1-8-4/archive/1.9-custom.zip
echo Extracting irrlicht... this may take some time.
"C:\Program Files\7-Zip\7z.exe" x irrlicht1-8-4-1.9-custom.zip
mv irrlicht1-8-4-1.9-custom/include irrlicht/include
# Technically, only code files need to be moved, and code files in lzma and aesGladman, but this is easier
mv irrlicht1-8-4-1.9-custom/source/Irrlicht irrlicht/src
rm -rf irrlicht1-8-4-1.9-custom
rm irrlicht1-8-4-1.9-custom.zip
# We will build against vcpkg-provided versions of these libs
rm -rf irrlicht/src/bzip2 irrlicht/src/jpeglib irrlicht/src/libpng irrlicht/src/zlib