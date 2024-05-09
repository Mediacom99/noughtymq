SRC = ./examples/raylib/rayguiTry.c
BIN = ./bin/noughtymq
LIB_PATH = ./lib
INC_PATH = ./include
LIB_FLAG = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

.EXPORT_ALL_VARIABLES:
	LD_LIBRARY_PATH=${LIB_PATH}

noughtymq : ${SRC}
	clang -v -I${INC_PATH} -Wl,--verbose,-L${LIB_PATH} ${LIB_FLAG} ${SRC} -o ${BIN}


run : noughtymq
	${BIN}

	
clean : 
	rm ${BIN}

