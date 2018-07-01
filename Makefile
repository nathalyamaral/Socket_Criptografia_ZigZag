all: cliente servidor 

servidor:  servidor.o
	g++ servidor.o -Wall -g -o servidor.out

cliente: cliente.o
	g++ cliente.o -Wall -g -o cliente.out
	
run: cliente servidor
	gnome-terminal -e ./servidor.out
	gnome-terminal -e ./cliente.out
