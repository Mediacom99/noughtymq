SERVER = ./src/server.c
CLIENT = ./src/client.c
BINclient = ./bin/client
BINserver = ./bin/server
INC = ./include

targets : client server
	@echo "[INFO] Built both client and server binaries."

client : ${CLIENT}
	@echo "[INFO] Building client binary ..."
	gcc -std=c99 -Wall --pedantic-errors -I${INC} -lzmq ${CLIENT} -o ${BINclient}

server : ${SERVER}
	@echo "[INFO] Building server binary ..."
	gcc -std=c99  -Wall --pedantic-errors -I${INC} -lzmq ${SERVER} -o ${BINserver}

clean :
	@echo "[INFO] Removing client and server executables."
	rm ${BINclient}
	rm ${BINserver}

