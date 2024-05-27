# Messaging app using ZeroMQ library

## What is it ?

I'm trying to build an online chatroom using ZeroMQ. The end goal is to have something encrypted, secure, fast, easily scalable and, especially, easily deployable by anyone. It should be as easy as opening the server app and the chatroom is online.
Anyone that should have access now can securely communicate without having to rely on any third party server or service other than internet providers.
For now the only user interface will be made using ncurses. Later on I would like this app to be available for the three major OS's and for Android.

## Utilities

Dependencies: 
1. zeroMQ library (libzmq - zmq.h)
2. ncurses ( libncurses - ncurses.h)

## Linking

Static: zeroMQ and ncurses both provide archive files.

Anyway, REMEMBER to run this before anything if you are linking dynamically
against a library not in a default system folder:
```
export LD_LIBRARY_PATH = ./lib
```

## TODO

[x] -- example with raylib\
[x] -- example with ncurses\
[ ] -- understand all the other patterns in zeroMQ
[ ] -- finish zeroMQ guide
[ ] -- implement simple REQ/REP for client message and PUB/SUB for other
[ ] -- add ncurses tui to reach the most simple chat appl
[ ] -- add configuration before chat (server's ip addr, nickname)
[ ] -- add some form of encryption and authentication
[ ] -- change into p2p arch with client-server for each device ?
