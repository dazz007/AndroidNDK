#include <iostream>
#include "cryptopp/cryptlib.h"
#include "dsa.h"
#include <string>
#include "osrng.h"
using CryptoPP::AutoSeededRandomPool;

#include "cryptopp/integer.h"
using CryptoPP::Integer;

#include "cryptopp/nbtheory.h"
using CryptoPP::ModularExponentiation;

#include "cryptopp/dh.h"
using CryptoPP::DH;

#include "cryptopp/dh2.h"
using CryptoPP::DH2;
using CryptoPP::RandomNumberGenerator;
#include "Hash.h"

using namespace std;
//NAMESPACE_BEGIN(CryptoPP)

////////////////////////////////////////////////////////////
class KeyGenerator
{
public:
    int keySize;
    KeyGenerator(DH &domain)
    : dh(domain) {
        p = dh.GetGroupParameters().GetModulus();
		q = dh.GetGroupParameters().GetSubgroupOrder();
		g = dh.GetGroupParameters().GetGenerator();
        keySize = Hash::size;
    }

    unsigned int StaticPrivateKeyLength() const
    {return dh.PrivateKeyLength();}
	unsigned int StaticPublicKeyLength() const
    {return dh.PublicKeyLength();}
	void GenerateStaticPrivateKey(RandomNumberGenerator &rng, byte *privateKey) const
    {dh.GeneratePrivateKey(rng, privateKey);}
	void GenerateStaticPublicKey(RandomNumberGenerator &rng, const byte *privateKey, byte *publicKey) const
    {dh.GeneratePublicKey(rng, privateKey, publicKey);}
	void GenerateStaticKeyPair(RandomNumberGenerator &rng, byte *privateKey, byte *publicKey) const //x, g^x
    {dh.GenerateKeyPair(rng, privateKey, publicKey);}

	unsigned int EphemeralPrivateKeyLength() const { return keySize; }
	void GenerateEphemeralPrivateKey(RandomNumberGenerator &rng, byte *privateKey) const; //cb^ha
	unsigned int EphemeralPublicKeyLength() const { return keySize; }
	void GenerateEphemeralPublicKey(RandomNumberGenerator &rng, byte *privateKey) const; //cb^ha
    void GenerateEphemeralKeyPair(RandomNumberGenerator &rng, byte *privateKey, byte *publicKey) const;

    byte * GenerateKeyFromHashedKey(byte *key, int random);
    byte * EstablishSessionKey(byte *ephemeralPrivateKey, byte * ephemeralPublicKey);

protected:
	DH &dh;
    Integer p, q, g;

};
