all: hello.o
	ld -T hello.ld --oformat binary -o hello.bin hello.o
	mv hello.bin ..

hello.o: hello.s
	as -o hello.o hello.s

clean:
	rm ../hello.bin hello.o
