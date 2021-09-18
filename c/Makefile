all:
	gcc -Wall -o hello hello.c
	dd if=hello of=hello.bin skip=4192 count=388 bs=1
	rm hello
	mv hello.bin ..

clean:
	rm ../hello.bin