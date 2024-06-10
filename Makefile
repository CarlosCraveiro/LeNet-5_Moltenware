all:
	gcc src/*.c -I include -I images -I parameters -lm -o a.out

run:
	./a.out
