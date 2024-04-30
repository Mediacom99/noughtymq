#!/usr/bin/bash
#
# Build script
#

if [ $# -eq 0 ]
then
	echo "No arguments provided!"
	echo "please provide source file name and output file name"
	exit
fi
#clang -v -L/usr/lib/x86_64-linux-gnu -lzmq $1 -o $2
clang -v -Wall -L/usr/lib/x86_64-linux-gnu -I/home/edoardo/noughtymq/include -lzmq  $1 -o $2
exit
