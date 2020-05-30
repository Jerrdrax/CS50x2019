# Windows makefile

CC=gcc
terminal=powershell
finalapp=credit.exe
outputvalidators=validate_start.o validate_length.o validate_checksum.o

credit: main.o get_cardnum.o $(outputvalidators)
	$(CC) main.o get_cardnum.o $(outputvalidators) -o $(finalapp)

main.o: main.c
	$(CC) main.c -c -o main.o

get_cardnum.o: get_cardnum.c
	$(CC) get_cardnum.c -c -o get_cardnum.o

validate_length.o: validate_length.c
	$(CC) validate_length.c -c -o validate_length.o

validate_start.o: validate_start.c
	$(CC) validate_start.c -c -o validate_start.o

validate_checksum.o: validate_checksum.c
	$(CC) validate_checksum.c -c -o validate_checksum.o

clean:
	$(terminal) remove-item * -include *.o, *.exe
