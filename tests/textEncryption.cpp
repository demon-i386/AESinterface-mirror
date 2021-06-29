#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../src/include/aes.hpp"

int main(){
	AES aes;
	char message[255] = "Hello World!";
	aes.encrypt(message, 0);
}