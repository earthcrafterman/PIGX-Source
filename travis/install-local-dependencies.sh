#!/usr/bin/env bash

set -euxo pipefail

#Download default font to be bundled
curl --retry 5 --connect-timeout 30 --location --remote-header-name --remote-name https://raw.githubusercontent.com/ProjectIgnis/Distribution/master/fonts/NotoSansJP-Regular.otf

# We are locked to FreeType 2.6.5 for now because of TTF interpreter behaviour in newer versions
# curl --retry 5 --connect-timeout 30 --location --remote-header-name --remote-name http://downloads.sourceforge.net/freetype/freetype-2.6.5.tar.bz2
# echo Extracting FreeType...
# tar xf freetype-2.6.5.tar.bz2 > /dev/null
# mv freetype-2.6.5/builds freetype
# mv freetype-2.6.5/include freetype
# mv freetype-2.6.5/src freetype
# rm -rf freetype-2.6.5
# rm freetype-2.6.5.tar.bz2

# install UPX
curl --retry 5 --connect-timeout 30 --location --remote-header-name --remote-name https://github.com/upx/upx/releases/download/v3.96/upx-3.96-win64.zip
unzip -uo upx-3.96-win64.zip > /dev/null
mv upx-3.96-win64/upx.exe upx.exe
rm -rf upx-3.96-win64
rm upx-3.96-win64.zip

curl --retry 5 --connect-timeout 30 --location --remote-header-name --remote-name https://github.com/edo9300/irrlicht1-8-4/archive/1.9-custom.zip
echo Extracting irrlicht... this may take some time.
unzip -uo irrlicht1-8-4-1.9-custom.zip > /dev/null
mv irrlicht1-8-4-1.9-custom/include irrlicht/include
# Technically, only code files need to be moved, and code files in lzma and aesGladman, but this is easier
mv irrlicht1-8-4-1.9-custom/source/Irrlicht irrlicht/src
rm -rf irrlicht1-8-4-1.9-custom
rm irrlicht1-8-4-1.9-custom.zip
# We will build against vcpkg-provided versions of these libs
rm -rf irrlicht/src/bzip2 irrlicht/src/jpeglib irrlicht/src/libpng irrlicht/src/zlib
