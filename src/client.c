/*

  Publisher-Subscribe pattern with zeroMQ, client example
  @AUTHOR: Edoardo Bertoli

*/

#include "zutils.h"
#include <zmq.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#define BUFSIZE 256

int main(void)
{
    printf("Collecting messages from the server...\n");

    void *context = zmq_ctx_new();
    void *subscriber = zmq_socket(context, ZMQ_SUB);

    int rc = zmq_connect(subscriber, "tcp://localhost:6969");
    assert(rc == 0);

    //  Subscribe to filter
    //const char *filter = "CLIENT1";
    rc = zmq_setsockopt(subscriber, ZMQ_SUBSCRIBE,
			"BR1",3); //only the publications starting with 'BR1'
                                  //will be read by this client
    assert(rc == 0);
    
        
    for(int i = 0; i < 10; ++i) {
	char *buffer = s_recv(subscriber, 0);
	if(buffer == NULL) {
	    printf("No chars received!\n");
	} else {
	    printf("Received: %s\n", buffer);    
	}
	
	free(buffer);
    }

    return 0;

    
}
