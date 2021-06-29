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

void AES::padding(unsigned char *state) {
	int len = sizeof(state);
	unsigned char *ptr = state;

	while((len % BLOCKLEN) != 0) {
		realloc(ptr, 1); 
		strcat(ptr, 0);
		len++;
	}
}


void AES::encryptCBC(char* state, char* key, char* output){
	
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
void AES::rotWord(unsigned char* key){

}
void AES::subWord(unsigned char* key){

}


// Message Encryption
void AES::shiftRows(unsigned char* state){

}
void AES::mixColumns(unsigned char* state){

}
void AES::invMixColumns(unsigned char* state){  // inverse of MixColumns

}

void AES::subBytes(unsigned char* state){ // Byte substituction using sbox (substituction box)

}

void AES::invShiftRows(unsigned char* state){

}
void AES::invSubBytes(unsigned char* state){

}

void AES::addRoundKey(unsigned char* state, unsigned char* key){ // XOR message - key

}

void AES::executeEncryptionRounds(unsigned char* state, unsigned char* key){
	for(int i = 0; i < ROUNDS; i++){
		subBytes(state);
		shiftRows(state);
		mixColumns(state);
		addRoundKey(state, key);
	}
}

// Inverse operation for encryptiom method
void AES::executeDecryptionRounds(unsigned char* state, unsigned char* key){
	for(int i = 0; i < ROUNDS; i++){
		invShiftRows(state);
		invSubBytes(state);
		invMixColumns(state);
		addRoundKey(state, key);
	}
}

void AES::decrypt(unsigned char* state, unsigned char* key, int mode){
	
	// Initial round
	addRoundKey(state, key);
	
	// Execute rounds
	executeDecryptionRounds(state, key);

	// Final round
	invShiftRows(state);
	invSubBytes(state);
	addRoundKey(state, key);
}

unsigned char* AES::generateKey(){
	unsigned char key[16];
	getrandom(key, 16, 0);
	return key;
}

void AES::encrypt(unsigned char* state, int mode){

	// Pad message to 16 bytes
	AES::padding(state);

	// Generate a 16 bytes "random" key
	unsigned char* key = AES::generateKey();

	// Initial Round
	AES::addRoundKey(state, key);

	// Execute rounds
	AES::executeEncryptionRounds(state, key);

	// Final Round
	AES::subBytes(state);
	AES::shiftRows(state);
	AES::addRoundKey(state, key);
}

void AES::encrypt(unsigned char *state, unsigned char *key, int mode){
	
	// Pad message to 16 bytes
	AES::padding(state);
	
	// Initial Round
	AES::addRoundKey(state, key);

	// Execute rounds
	AES::executeEncryptionRounds(state, key);

	// Final Round
	AES::subBytes(state);
	AES::shiftRows(state);
	AES::addRoundKey(state, key);

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