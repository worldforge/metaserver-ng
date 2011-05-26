#!/bin/sh
# Worldforge Next Generation MetaServer
#
# Copyright (C) 2011 Sean Ryan <sryan@evercrack.com>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

LIBTOOLIZE=libtoolize
OS=$(uname -s)

if [ "x$OS" = "xDarwin" ]; then
   LIBTOOLIZE=glibtoolize
fi

rm -f config.cache

if test -d /usr/local/share/aclocal ; then
	ACLOCAL_FLAGS="$ACLOCAL_FLAGS -I /usr/local/share/aclocal"
fi
aclocal $ACLOCAL_FLAGS
$LIBTOOLIZE --force --copy
autoheader
automake --gnu --add-missing --copy
autoconf
