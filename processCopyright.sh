#/bin/bash

./addCopyright.pl < $1 > $1.bak
mv $1.bak $1

