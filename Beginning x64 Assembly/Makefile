hello: hello.o
	gcc -o hello hello.o -no-pie

hello.o: hello.s
	nasm -f elf64 -g -F dwarf hello.s -l hello.lst
