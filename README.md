# Messaging app using ZeroMQ library

## What is it ?

I'm trying to build an online chatroom using ZeroMQ. The end goal is to have something encrypted, secure, fast, easily scalable and, especially, easily deployable by anyone. It should be as easy as opening the server app and the chatroom is online.
Anyone that should have access now can securely communicate without having to rely on any third party server or service other than internet providers. 

## Utilities

Dependencies: 
1. libzmq3-dev (on debian)
2. raylib (?)

## Linking

Static: zeroMQ and ncurses both provide archive files.

Anyway, REMEMBER to run this before anything if you are linking dynamically
against a library not in a default system folder:
```
export LD_LIBRARY_PATH = ./lib
```

## TODO

[x] -- example with raylib


[ ] -- try getting output dynamically onto window (from printf for example)


[ ] -- understand all the other patterns in zeroMQ


