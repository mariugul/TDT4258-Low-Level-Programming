#!/bin/bash
# Compile the .c files

# Clear the terminal
clear


printf "
*********************************
**------ Cleaning Files -------**
*********************************\n" 
# Clean the files
make clean 


printf "
*********************************
**----- Compiling Files -------**
*********************************\n" 
# Compile files
make

printf "
*********************************
**---------- Done. ------------**
*********************************\n" 