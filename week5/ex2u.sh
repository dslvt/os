#!/bin/bash

for i in 1 2 3 4 5 6 7 8 9 10
do
	if ln ex2 ex2.lock; then 
		vr=$(tail -1 "ex2")
		echo "$(($vr+1))" >> "ex2"
		rm ex2.lock;
	fi
done
