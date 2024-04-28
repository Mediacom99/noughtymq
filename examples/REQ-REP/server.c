/*
 *
 *  Request-Response pattern example
 */

#include <zmq.h>
#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>

int main (void) {

	//Bind this application to a socket to talk to clients
	void *context = zmq_ctx_new(); //Initialize zmq context
	void *responder = zmq_socket(context, ZMQ_REP); //get the socket for a REQ-REP pattern
	int rc = zmq_bind(responder, "tcp://*:5555"); //bind the socket to the 5555 port using tcp for incoming messages from clients
	assert(rc == 0);

	//Main loop
	while(1)
	{
		char buffer[10]; //buffer to hold client response (not a C string by default!!!)
		zmq_recv(responder, buffer, 10, 0); //receive request from client
		printf("%s\n", buffer);
		sleep(1);
		zmq_send(responder, "Message Received\n",17,0); //send response based on the client request
	}
	return 0;
}

