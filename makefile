FILES = arvore.c palavras.c leArq.c main.c

all: compile

compile: $(FILES)
	gcc -ggdb $^ -o main

%.o: %.c
	gcc -c $^

clean:
	rm *.o
