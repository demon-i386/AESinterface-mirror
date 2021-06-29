#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../src/include/aes.hpp"

int main(){
	// creating object for AES class
	AES aes;
	unsigned char message[255] = "Hello World!";
	unsigned char key[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };

	// aes.encrypt(unsigned char* state, unsigned char *state, int mode);
	// use know key
	aes.encrypt(message, key, 0);

	// aes.encrypt(unsigned char* state, int mode);
	// generate random key
	aes.encrypt(message, 0);
}