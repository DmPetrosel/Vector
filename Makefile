all:
	g++ vect.h vect.cpp rand_walk.cpp -o rand_walk.exe
clear:
	rm -f rand_walk.exe
clearoutput:
	rm -f output.txt
