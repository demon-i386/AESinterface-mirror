PWD := `pwd`
CC = g++
DIR=$HOME/local

.PHONY: install clean

install:
	@ mkdir -p $(HOME)/.local/lib
	@ export LD_LIBRARY_PATH=${HOME}/local/lib/:${LD_LIBRARY_PATH}
	@ cp ./build/libaes.a /usr/local/lib/
	@ cp ./src/include/aes.hpp /usr/local/include

all: ./src/include/aes.cpp
	@ mkdir -p build/bin
	@ $(CC) -c ./src/include/aes.cpp -o ./src/objs/aes.o -fpermissive
	@ ar crv libaes.a ./src/objs/aes.o 
	@ mv libaes.a ./build

shared:
	@ $(CC) -c -fpic -o ./src/objs/aes.o ./tests/*.cpp
	@ $(CC) -shared -o ./build/libaes.so ./src/objs/aes.o

clean:
	@ shred -u ./src/objs/*.o ./build/libaes.* 

test-shared: 
	@ $(CC) ./tests/*.cpp -o ./build/bin/main -I ./src/include/ -L ./build/libaes.so

test-static: all
	@ $(CC) ./tests/*.cpp ./build/libaes.a -o ./build/bin/main 
	@ ./build/bin/main