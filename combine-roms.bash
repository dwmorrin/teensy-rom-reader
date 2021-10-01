#!/bin/bash
# paste the roms together to form the full 32 bit words
[[ -d ./roms ]] || exit 1
t="tmp.$0.txt"
paste -d '      ' ./roms/* >"$t"
if sed 's/
    rm "$t"
fi
