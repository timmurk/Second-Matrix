CFLAGS=-lm -c -g -std=c++11 -O3
a.out: main.o input.o matrix.o
		g++ main.o input.o matrix.o -o a.out
main.o: main.cpp input.h matrix.h
		g++ $(CFLAGS) main.cpp
matrix.o: matrix.cpp matrix.h
		g++ $(CFLAGS) matrix.cpp
input.o: input.cpp input.h
		g++ $(CFLAGS) input.cpp
clean:
		rm -rf *.o