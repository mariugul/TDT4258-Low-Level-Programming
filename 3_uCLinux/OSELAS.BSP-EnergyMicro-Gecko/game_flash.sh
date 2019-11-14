#!/bin/bash
# Compile the game and flash it

# Clear the terminal
clear


printf "
*********************************
**------ Cleaning Files -------**
*********************************\n" 
# Clean the files
ptxdist clean game

printf "
*********************************
**----- Compiling Files -------**
*********************************\n" 
# Compile files
ptxdist compile game

printf "
*********************************
**-------- Installing ---------**
*********************************\n" 
# Install the game on target
ptxdist targetinstall game

printf "
*********************************
**-------- Image Root ---------**
*********************************\n" 

# Does something I don't know
ptxdist image root.romfs

printf "
*********************************
**------ Flash to Board -------**
*********************************\n" 

# Flash the game 
ptxdist test flash-rootfs

printf "
*********************************
**---------- Done. ------------**
*********************************\n" 