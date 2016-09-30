#!/bin/bash
#
#  install-nanomsg.sh
#
#  Copyright (c) 2016 Stephen Whittle  All rights reserved.
#
#  Permission is hereby granted, free of charge, to any person obtaining a copy
#  of this software and associated documentation files (the "Software"),
#  to deal in the Software without restriction, including without limitation
#  the rights to use, copy, modify, merge, publish, distribute, sublicense,
#  and/or sell copies of the Software, and to permit persons to whom
#  the Software is furnished to do so, subject to the following conditions:
#  The above copyright notice and this permission notice shall be included
#  in all copies or substantial portions of the Software.
#  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
#  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
#  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
#  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
#  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
#  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
#  IN THE SOFTWARE.

if [ $(id -u) -ne 0 ] ; then
    printf "must be a superuser!!!\n" >&2
    exit 1
fi

install_dir="/usr/local/src/nanomsg"
archive_version="1.0.0"
archive_file="$archive_version.tar.gz"

apt-get install cmake

[ ! -d "$install_dir" ] && mkdir --parents "$install_dir"

cd "$install_dir"

wget "https://github.com/nanomsg/nanomsg/archive/$archive_file"

tar -zxvf "$archive_file"

cd "nanomsg-$archive_version"

mkdir build
cd build
cmake ..
cmake --build .
ctest -C Debug .
cmake --build . --target install

(
    printf "# nanomsg\n"
    printf "/usr/local/lib/x86_64-linux-gnu\n"
) >/etc/ld.so.conf.d/nanomsg.conf

ldconfig

exit 0
