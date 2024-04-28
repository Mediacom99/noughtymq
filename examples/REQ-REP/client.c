/*
 *
 *  Request-reply pattern example client code
 */

#include <zmq.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main (void)
{

	printf("Connecting to hello world server...\n");
	void* context = zmq_ctx_new(); //creating new zmq context
	void* requester = zmq_socket(context, ZMQ_REQ); //create a socket for a request to a req-rep server
	zmq_connect(requester, "tcp://192.168.1.42:5555"); //connect to the server using the socket

	char buff[20];
	zmq_send(requester, "H4ck3d!", 7, 0); //send something to the server (request something)
	zmq_recv(requester, buff, 20, 0); //receive smth from the server (response of the server)
	printf("%s\n", buff);

	zmq_close(requester);
	zmq_ctx_destroy(context);
	return 0;
}
