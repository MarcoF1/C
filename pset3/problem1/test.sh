#!bin/bash

filename="sorting.exe"

# compile 
g++ -o $filename sorting.cpp

# run the file
./$filename

# delete the file
rm $filename