# Messaging app using ZeroMQ library

## Compiling

Dependencies: libzmq3-dev (on debian)

Compile command: 
```
clang -L/usr/lib/x86_64-linux-gnu -lzmq <src-file> -o <output-file>
```

Use this command to check where packages are installed on the system: 
```
dpkg -L <package-name>
```
