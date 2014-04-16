#include "MutualAuthenticationChip.h"

#include "cryptopp/dh.h"
using CryptoPP::DH;

void MutualAuthenticationChip::GenerateKeyPairs(){
	//Automaticly Seeded Randomness Pool.
	//This class seeds itself using an operating system provided RNG.
	privateKey = new SecByteBlock(dh.PrivateKeyLength());
	publicKey = new SecByteBlock(dh.PublicKeyLength());
	dh.GenerateKeyPair(this->rnd, *privateKey, *publicKey);

}

void MutualAuthenticationChip::GenerateEphemeralKeys(){
	kg->GenerateEphemeralKeyPair(rnd, *ephemeralPrivateKey, *ephemeralPublicKey);

//    Integer a = Integer(this->rnd, this->keySize); //random a
//    byte *aEncoded;
//    a.Encode(aEncoded, this->keySize); //change Integer to byte
//    this->ephemeralPrivateKey = Hash::getSHA1(aEncoded, this->keySize); //ha = H(a)
//    CryptoPP::Integer exponent(this->ephemeralPrivateKey, keySize);
//    CryptoPP::Integer cA = a_exp_b_mod_c(this->g, exponent, this->p);   //ca = g^H(a)
//    cA.Encode(this->ephemeralPublicKey, keySize);
}

byte * MutualAuthenticationChip::GetEphemeralPublicKey(){
	return *ephemeralPublicKey;
}

void MutualAuthenticationChip::dupa(){

}

int MutualAuthenticationChip::GetKeySize(){
	return keySize;
}