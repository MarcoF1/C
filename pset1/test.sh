#!/bin/bash

#compile the C file
gcc -o Mod.out Modulus.c

# file to be reading input lines from
filename='ModulusArgs.txt'

# run the file with inputs
./Mod.out cat<< EOF
$(cat $filename)
EOF

# Clean the output files
rm Mod.out