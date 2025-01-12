#!/usr/bin/env sh

read int
echo $int > .value
sed -i "1,4 s/--mute=no /--mute=yes/" Backup/scripts/autostart.sh
sed -i "$int s/--mute=yes/--mute=no /" Backup/scripts/autostart.sh
startx
