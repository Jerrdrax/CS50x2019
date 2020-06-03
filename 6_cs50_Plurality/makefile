# Makefile for windows

CC = gcc
CFlags = -c -o
terminal = powershell
finalapp = Plurality.exe
election = get_election.o validate_duplicate.o
votes = get_numvotes.o get_votes.o
objects = main.o print_winner.o $(election) $(votes)

all: $(finalapp)

$(finalapp): $(objects)
	$(CC) $^ -o $@

%.o: %.c Plurality_Variables.h
	$(CC) $< $(CFlags) $@

clean:
	$(terminal) remove-item * -include *.o, *.exe
