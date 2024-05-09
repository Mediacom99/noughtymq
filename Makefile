SRC = ./examples/raylib/basicWindow.c
BIN = ./bin/noughtymq
LIB_PATH = ./lib
INC_PATH = ./include

noughtymq : ${SRC}
	clang -v -I${INC_PATH} -Wl,,-L=${LIB_PATH} -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 ${SRC} -o ${BIN}

verbose: ${SRC}
	clang -v -I${INC_PATH} -Wl,--verbose,-L=${LIB_PATH} -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 ${SRC} -o ${BIN}

# Compile statically
static : ${SRC}
	clang -v -I${INC_PATH} -Wl,-V,-L=${LIB_PATH} -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -static ${SRC} -o ${BIN}

clean : 
	rm ${BIN}

clean-all:
	rm -i ./bin/*

run : ${SRC}
	clang -v -I${INC_PATH} -Wl,,-L=${LIB_PATH} -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 ${SRC} -o ${BIN}
	${BIN}
	
