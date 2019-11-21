#!/bin/bash
# exit when any command fails
set -e
# keep track of the last executed command
trap 'last_command=$current_command; current_command=$BASH_COMMAND' DEBUG
# echo an error message before exiting
trap 'echo "\"${last_command}\" command filed with exit code $?."' EXIT

echo "Cleaning, compiling and flashing driver..."
ptxdist clean driver-gamepad  
ptxdist compile driver-gamepad 
ptxdist targetinstall driver-gamepad  
ptxdist targetinstall kernel 
ptxdist image root.romfs  
ptxdist test flash-rootfs