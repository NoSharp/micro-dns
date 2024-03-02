CC = gcc
CC_FLAGS = -O2 -Wall -Wextra

clean:
	del /Q /F /S *.o *.exe

micro_dns: main.o
	$(CC) -o micro_dns main.o nt_udp.o -lws2_32

main.o: nt_udp.o
	$(CC) $(CC_FLAGS) -c src/main.c -o main.o

nt_udp.o:
	$(CC) $(CC_FLAGS) -c src/nt_udp.c -o nt_udp.o