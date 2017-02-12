Implementation of Digital Signatures using C

The project’s objective is to create a client-server network, to implement digital signature’s    (RSA) library for ensuring the authenticity of the client and to improve the performance using hash function (SHA-1).

Requirements
	gcc 6.2 or above

Getting Started

Download client.c, sha1.c, sha1.h, rsa.c, rsa.h on client machine.
Download server.c, sha1.c, sha1.h on server machine. 
	
On the server side, run the following commands on terminal:
	gcc -c server.c - server.o
	gcc -c sha1.c -o sha1.o
	gcc server.o sha1.o -o server
	./server

On the client side, run the following commands on terminal: 
	gcc -c client.c -o client.o 
	gcc -c rsa.c -o rsa.o
	gcc -c sha1.c -o sha1.o
	gcc client.o sha1.o rsa.o -o client
	./client

Scope of Improvement
	Code can be updated to use standard RSA key length.

License
	This project is licensed under the  GNU GENERAL PUBLIC LICENSE - see the LICENSE.md file for details

