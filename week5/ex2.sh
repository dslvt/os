#!/bin/bash

for i in 1 2 3 4 5 6 7 8 9 19
do
	vr=$(tail -1 "ex2")
	echo "$(($vr+1))" >> "ex2"
done
