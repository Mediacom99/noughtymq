/*
 *
 *  Utility header-only file. Contains code for 
 *  string management and such.
 */


// Receive a ZeroMQ string from socket and convert into
// C string. Chops C string at 255 chars.

#include <zmq.h>
#ifndef UTILITY_H
#define UTILITY_H


static char * s_recv (void* socket)
{
	char buffer[256];
	int size = zmq_recv(socket, buffer, 255, 0);
	if(size == -1) {
		return NULL;
	}
	if(size > 255)
	{
		size = 255;
	}
	buffer[size] = '\0';

	return strdup(buffer);

}
#endif
