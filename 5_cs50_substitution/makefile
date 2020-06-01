# Windows makefile

CC = gcc
CFlags = -c -o
terminal = powershell
finalapp = substitution.exe
objects = main.o get_key.o get_txt.o cipher.o

all: $(finalapp)

$(finalapp): $(objects)
	$(CC) $^ -o $@

%.o: %.c vars_cipher.h
	$(CC) $< $(CFlags) $@

clean:
	$(terminal) remove-item * -include *.o, *.exe
