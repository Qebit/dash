
Debian
====================
This directory contains files used to package akaxd/akax-qt
for Debian-based Linux systems. If you compile akaxd/akax-qt yourself, there are some useful files here.

## akax: URI support ##


akax-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install akax-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your akax-qt binary to `/usr/bin`
and the `../../share/pixmaps/dash128.png` to `/usr/share/pixmaps`

akax-qt.protocol (KDE)

