server client:server.o client.o
	gcc -lpthread -o server server.o 
	gcc -o client client.o
server.o client.o:server.c client.c
	gcc -c server.c
	gcc -c client.c

clean:
	rm server.o client.o
