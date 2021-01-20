#!/bin/bash

#compile the C file
gcc -o cow.out cowPonds.c

# file to be reading input lines from
filename='cowPonds.txt'

# run the file with inputs
./cow.out cat<< EOF
$(cat $filename)
EOF

# Clean the output files
rm cow.out