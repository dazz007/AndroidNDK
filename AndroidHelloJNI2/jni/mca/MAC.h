#include <iostream>
#include <string>
#include "cryptopp/integer.h"

#include "cryptopp/cryptlib.h"

#include "cryptopp/dsa.h"
using CryptoPP::DSA;

#include "cryptopp/secblock.h"
using CryptoPP::SecByteBlock;

#include "cryptopp/dh.h"
using CryptoPP::DH;

using namespace std;
using CryptoPP::Integer;


////////////////////////////////////////////////////////////
class MAC{
public:
	int state;
	SecByteBlock privKey;
	SecByteBlock pubKey;
	DSA::PublicKey signPubKey;
	DSA::PrivateKey signPrivKey;
	DH dh;

	MAC(int y) : state(y){

	}

	void doubleState();

};
