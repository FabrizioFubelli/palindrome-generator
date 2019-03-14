# build an executable named myprog from myprog.c
all: main.c
	gcc -o palindrome main.c

clean:
	$(RM) palindrome
