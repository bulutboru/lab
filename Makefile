all: install test

install:
	gcc -std=c99 -g main.c -o main.out -lm

clean:
	rm main.out

test: 
	./main.out
