CC = gcc
CFLAGS = -Wall -Wextra -g

all: q2.exe q3.exe q4.exe

q2.exe: q2.c lista.c lista.h
	$(CC) $(CFLAGS) q2.c lista.c -o q2.exe

q3.exe: q3.c lista.c lista.h
	$(CC) $(CFLAGS) q3.c lista.c -o q3.exe

q4.exe: q4.c lista.c lista.h
	$(CC) $(CFLAGS) q4.c lista.c -o q4.exe

q5.exe: q5.c lista.c lista.h
	$(CC) $(CFLAGS) q5.c lista.c -o q5.exe

clean:
	rm -f q2.exe q3.exe q4.exe q5.exe
