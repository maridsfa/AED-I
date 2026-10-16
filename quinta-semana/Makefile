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

q7.exe: q7.c lista.c lista.h
	$(CC) $(CFLAGS) q7.c lista.c -o q7.exe

q10.exe: q10.c lista.c lista.h
	$(CC) $(CFLAGS) q10.c lista.c -o q10.exe

clean:
	rm -f q2.exe q3.exe q4.exe q5.exe q7.exe q10.exe
