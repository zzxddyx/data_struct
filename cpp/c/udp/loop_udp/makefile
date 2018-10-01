client server:client.o server.o
	gcc -o client client.o
	gcc -o server server.o
client.o server.o:client.c server.c
	gcc -c client.c
	gcc -c server.c

clean:
	rm server.o client.o
