SERVER = ./src/server.c
CLIENT = ./src/client.c
BINclient = ./bin/client
BINserver = ./bin/server
INC = ./include
LLIB = -lzmq

targets : client server
	@echo "[INFO] Built both client and server binaries."

client : ${CLIENT}
	@echo "[INFO] Building client binary ..."
	gcc ${CLIENT} -o ${BINclient} -std=gnu11 -Wall --pedantic-errors -I${INC} ${LLIB} 

server : ${SERVER}
	@echo "[INFO] Building server binary ..."
	gcc ${SERVER} -o ${BINserver} -std=gnu11  -Wall --pedantic-errors -I${INC} ${LLIB} 

clean :
	@echo "[INFO] Removing client and server executables."
	rm ${BINclient}
	rm ${BINserver}

