all:
	gcc src/*.c -I include -lm -o a.out

run:
	./a.out
