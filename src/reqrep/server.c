/*
 *
 *  Request-Response pattern example
 */


#include <zmq.h>
#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>

#define MAXBUF 256

int main (void) {

	//Bind this application to a socket to talk to clients
	void *context = zmq_ctx_new(); //Initialize zmq context
	void *responder = zmq_socket(context, ZMQ_REP); //get a socket as a responder of the clients' requests
	int rc = zmq_bind(responder, "tcp://*:5555"); //bind the socket to the 5555 port using tcp for incoming messages from clients
	assert(rc == 0);

	//Main loop

	while(1)
	{
		char buffer[MAXBUF]; //buffer to hold client request (not a C string by default!!!)
		for(int i = 0; i < MAXBUF; i++) {
		  buffer[i] = 0;
		}
		zmq_recv(responder, buffer, MAXBUF, 0); //receive request from client
		printf("%s\n", buffer);
		sleep(1);
		zmq_send(responder, "Here is the response to your request!",MAXBUF,0); //send response answering to the request
	}
	return 0;
}

