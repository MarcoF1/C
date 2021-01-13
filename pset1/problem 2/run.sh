#!/bin/bash

#compile the C file
gcc -o factor.out factor.c

# run the file with inputs
./factor.out << EOF
37800
EOF

# Clean the output files
rm factor.out