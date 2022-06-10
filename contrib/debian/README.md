
Debian
====================
This directory contains files used to package xeked/xeke-qt
for Debian-based Linux systems. If you compile xeked/xeke-qt yourself, there are some useful files here.

## xeke: URI support ##


xeke-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install xeke-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your xeke-qt binary to `/usr/bin`
and the `../../share/pixmaps/dash128.png` to `/usr/share/pixmaps`

xeke-qt.protocol (KDE)

