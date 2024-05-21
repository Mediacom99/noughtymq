#ifndef ZUTILS_H
#define ZUTILS_H

#include <zmq.h>
#include <string.h> //For strdup, strlen

// MACROS

#define BUFSIZE 256


// DECLARATION

char *s_recv(void *socket, int flag);
int s_send(void *socket, char* buffer, int flag);


// IMPLEMENTATION

// Receive zeroMQ string from socket and convert it into C string
// Chops string at BUFSIZE chars with a null char.
// THE STRING RETURNED BY THIS FUNCTION MUST BE FREED!
char* s_recv(void* socket, int flag)
{
    char buffer[BUFSIZE];
    int size = zmq_recv(socket, buffer, BUFSIZE, flag);
    if(size == -1)
    {
	return NULL;
    }
    if(size > (BUFSIZE - 1))
    {
	size = BUFSIZE - 1;
    }
    buffer[size] = '\0';
    return strdup(buffer);  //AS UNSAFE
}

// Sends a C string as a ZMQ string to the socket
// Returns the number of bytes successfully sent
int s_send(void* socket, char* buffer, int flag) //flag is 0 by default
{
    int size = zmq_send(socket, buffer, strlen(buffer), flag);
    return size;
}
#endif
