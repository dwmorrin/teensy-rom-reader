#!/bin/bash
# paste the roms together to form the full 32 bit words
[[ -d ./roms ]] || exit 1
t="tmp.$0.txt"
paste -d '      ' \
    ./roms/8B.txt \
    ./roms/7B.txt \
    ./roms/6B.txt \
    ./roms/5B.txt \
    ./roms/4B.txt \
    ./roms/3B.txt \
    ./roms/2B.txt \
    ./roms/1B.txt \
    >"$t"
if sed 's///g' "$t" >rom-words.txt; then
    rm "$t"
fi

