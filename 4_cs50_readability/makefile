# Windows makefile

CC = gcc
CFlags = -c -o
terminal = powershell
finalapp = readability.exe
counters = count_letters.o count_words.o count_sentences.o
objs =readability.o get_txt.o $(counters)

all: $(finalapp)

$(finalapp): main.o $(objs)
	$(CC) $^ -o $@

%.o: %.c vars_read.h
	$(CC) $< $(CFlags) $@

clean:
	$(terminal) remove-item * -include *.o, *.exe
