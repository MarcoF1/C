#!/bin/bash

#compile the C file
gcc -o Mod.out Modulus.c

# run the file with inputs
./Mod.out

# Clean the output files
rm Mod.out