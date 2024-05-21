/*

  Publisher-Subscribe server model example with zeroMQ library.

*/

#include "zutils.h"
#include <zmq.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#define BUFSIZE 256

int main(void)
{
    //Start context and publisher socket
    void *ctx = zmq_ctx_new();
    void *publisher = zmq_socket(ctx, ZMQ_PUB);
    int rc = zmq_bind(publisher, "tcp://*:6969");
    assert(rc == 0);
    char usrline[BUFSIZE];
    
    while(1) {
	printf("Write what you want to publish:\n");
	fgets(usrline,BUFSIZE,stdin);
	int res = s_send(publisher, usrline, 0);
	fprintf(stderr, "[LOG] chars sent: %d\n", res);
    }

    zmq_close(publisher);
    zmq_ctx_destroy(ctx);

    return 0;
}
