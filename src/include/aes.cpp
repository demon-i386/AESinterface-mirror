/* 
	AES ( Advanced Encryption Standard ) cryptography C implementation
  	based in https://github.com/kokke/tiny-AES-c Bibliography

	 	Bibliography:
			https://nvlpubs.nist.gov/nistpubs/fips/nist.fips.197.pdf - NIST article about AES
			http://ciit.finki.ukim.mk/data/papers/10CiiT/10CiiT-46.pdf - AES operation modes

		About:
			AES is a symmetric block cypher that cuts the message in 128 bits (16 bytes) blocksthat supports 128, 192 and 256 bit keys

    4 Bytes = 1 Word (AES concept)
    Rounding text key to a 16 byte array / Expanding key
    Key Expansion

    Each column is added to a single Word, 4 x 4 columns generates 4 Words
    W1 and W4 is Xored, generating WW1

    W1 W2 W3 W4
    |___XOR___|-- WW1
*/

#include "aes.hpp"

void AES::padding(char *input) {
	int len = (int)strlen(input);
	while((len % BLOCKLEN) != 0) {
		strcat(input, "0");
		len++;
	}
}

void AES::statePlainText(char* input){
	
}

void AES::encryptCBC(char* input, char* key, char* output){
	
}

void AES::keyExpansion(uint8_t key[16], uint8_t* expandedKey){
	uint8_t  keyConvert[sizeof(key)];
	printf("\n");

	for(int i = 0; i < sizeof(key); i++){
		keyConvert[i] = key[i];
	}
	for(int i = 0; i < sizeof(keyConvert); i++){
		printf("0x%x ", keyConvert[i]);
	}
	printf("\nSize of key :: %d\n", sizeof(keyConvert));
}


// Key Expansion routine
void AES::rotWord(){

}
void AES::subWord(){

}


// Message Encryption
void AES::shiftRows(char* input){

}
void AES::mixColumns(char* input){

}
void AES::invMixColumns(char* input){  // inverse of MixColumns

}

void AES::subBytes(char* input){ // Byte substituction using sbox (substituction box)

}

void AES::invShiftRows(char* input){

}
void AES::invSubBytes(char* input){

}

void AES::addRoundKey(char* input, uint8_t* key){ // XOR message - key

}

void AES::executeEncryptionRounds(char* input, uint8_t* key){
	for(int i = 0; i < ROUNDS; i++){
		subBytes(input);
		shiftRows(input);
		mixColumns(input);
		addRoundKey(input, key);
	}
}

// Inverse operation for encryptiom method
void AES::executeDecryptionRounds(char* input, uint8_t* key){
	for(int i = 0; i < ROUNDS; i++){
		invShiftRows(input);
		invSubBytes(input);
		invMixColumns(input);
		addRoundKey(input, key);
	}
}

void AES::decrypt(char* input, uint8_t key[16], int mode){
	
	// Initial round
	addRoundKey(input, key);
	
	// Execute rounds
	executeDecryptionRounds(input, key);

	// Final round
	invShiftRows(input);
	invSubBytes(input);
	addRoundKey(input, key);
}

void AES::encrypt(char* input, int mode){

	// Pad message to 16 bytes
	AES::padding(input);

	// Generate a 16 bytes "random" key
	uint8_t key[16];
	getrandom(key, 16, 0);

	// Initial Round
	AES::addRoundKey(input, key);

	// Execute rounds
	AES::executeEncryptionRounds(input, key);

	// Final Round
	AES::subBytes(input);
	AES::shiftRows(input);
	AES::addRoundKey(input, key);
}

void AES::encrypt(char input[255], uint8_t key[16], int mode){
	uint8_t* expandedKey;
	AES::padding(input);
	AES::keyExpansion(key, expandedKey);
}


AES::AES(){
	puts("AES ( Advanced Encryption Standard ) encryption / decryption interface\nVersion :: 0.0.1\n\n");
}
AES::~AES(){
	
}


/*
switch (mode){
		case 0:
			puts("ECB");
			break;
		
		case 1:
			puts("CBC");
			break;
		
		case 2:
			puts("CFB");
			break;
		
		case 3:
			puts("OFB");
			break;
		
		case 4:
			puts("CTR");
			break;
	}*/