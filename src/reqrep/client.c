/*
 *
 *  Request-reply pattern example client code
 */

#include <zmq.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


#define MAXBUF 256

int main (void)
{
  printf("Connecting to hello world server...\n");
  void* context = zmq_ctx_new(); //creating new zmq context
  void* requester = zmq_socket(context, ZMQ_REQ); //create a socket for a request to a req-rep server
  zmq_connect(requester, "tcp://localhost:5555"); //connect to the server using the socket

  while(1) {
    char buff[MAXBUF];
    for(int i = 0; i < MAXBUF; i++) {
      buff[i] = 0;
    }
    zmq_send(requester, "Hey server, this is a request for you!", MAXBUF, 0); //send a request to the server
    zmq_recv(requester, buff, MAXBUF, 0); //receive smth from the server (response of the server)
    printf("%s\n", buff); //Print the server response
  }
  zmq_close(requester);
  zmq_ctx_destroy(context);

  return 0;
}
