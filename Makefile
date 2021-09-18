all:
	gcc -Wall -o disasm disasm.c -lcapstone

clean:
	rm disasm