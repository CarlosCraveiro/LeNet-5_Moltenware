all:
	gcc src/*.c -I include -lm -g -O0 -o a.out

run:
	./a.out
