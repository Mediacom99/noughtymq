SRC = ./examples/raylib/basicWindow.c
BIN = ./bin/noughtymq
LIB_PATH = ./lib
INC_PATH = ./include

noughtymq : ${SRC}
	clang -v -I${INC_PATH} -Wl,-V,-L=${LIB_PATH} -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 ${SRC} -o ${BIN}

# Compile statically
static : ${SRC}
	clang -v -I${INC_PATH} -Wl,-V,-L=${LIB_PATH} -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -static ${SRC} -o ${BIN}

clean : 
	rm -i ${BIN}

clean-all:
	rm -i ./bin/*

run :
	${BIN}
	
