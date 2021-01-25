#!bin/bash

filename="sorting.exe"
test="test.txt"
# compile 
g++ -o $filename sorting.cpp

# run the file
./$filename cat<< EOF
$(cat $test)
EOF

# delete the file
rm $filename