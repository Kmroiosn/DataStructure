clearn1: clearn1.c
	gcc -o clearn1 clearn1.c -g

clearn1.s: clearn1.c
	gcc -S -o clearn1.s clearn1.c -g

clearn1.3.s: clearn1.c
	gcc -S -o clearn1.3.s clearn1.c -g -O3

clearn2: clearn2.c
	gcc -o clearn2 clearn2.c -g

clean:
	rm -rf clearn1 clearn1.s clearn1.o
