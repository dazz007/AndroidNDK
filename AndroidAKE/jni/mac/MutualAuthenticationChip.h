#pragma once
#include <iostream>
#include <strstream>
#include "mac/Converter.h"
#include "mac/KeyGenerator.h"
//#include "mac/Hash.h"
#include "mac/EncDecClass.h"
#include "cryptopp/secblock.h"
using CryptoPP::SecByteBlock;

#include "cryptopp/integer.h"
using CryptoPP::Integer;

#include "cryptopp/osrng.h"
using CryptoPP::AutoSeededRandomPool;

#include "cryptopp/dh.h"
using CryptoPP::DH;

class MutualAuthenticationChip {
private:
	int help;
	int keySize;
	Integer p, q, g;
	SecByteBlock * publicKey;
	SecByteBlock * privateKey;
	SecByteBlock * ephemeralPublicKey;
	SecByteBlock * ephemeralPrivateKey;
	SecByteBlock * ephemeralPublicKeyAnotherParty;
	AutoSeededRandomPool rnd;
	DH dh;
	KeyGenerator * kg;
public:
	MutualAuthenticationChip(int h): help(h) {
		Integer p("0xB10B8F96A080E01DDE92DE5EAE5D54EC52C99FBCFB06A3C6"
				"9A6A9DCA52D23B616073E28675A23D189838EF1E2EE652C0"
				"13ECB4AEA906112324975C3CD49B83BFACCBDD7D90C4BD70"
				"98488E9C219A73724EFFD6FAE5644738FAA31A4FF55BCCC0"
				"A151AF5F0DC8B4BD45BF37DF365C1A65E68CFDA76D4DA708"
				"DF1FB2BC2E4A4371");

		Integer g("0xA4D1CBD5C3FD34126765A442EFB99905F8104DD258AC507F"
				  "D6406CFF14266D31266FEA1E5C41564B777E690F5504F213"
					"160217B4B01B886A5E91547F9E2749F4D7FBD7D3B9A92EE1"
					"909D0D2263F80A76A6A24C087A091F531DBF0A0169B6A28A"
					"D662A4D18E73AFA32D779D5918D08BC8858F4DCEF97C2A24"
					"855E6EEB22B3B2E5");

		Integer q("0xF518AA8781A8DF278ABA4E7D64B7CB9D49462353");
		this->p = p;
		this->q = q;
		this->g = g;

		dh.AccessGroupParameters().Initialize(this->p, this->q, this->g);

		kg = new KeyGenerator(dh);
		keySize = Hash::size;
	}

    Integer getP() { return p; }
    Integer getQ() { return q; }
    Integer getG() { return g; }

    MutualAuthenticationChip(Integer p, Integer q, Integer g)
    : p(p), q(q), g(g) {}

    void GenerateKeyPairs();
    void GenerateEphemeralKeys();
    void dupa();
    string GetEphemeralPublicKey();
    string ShowPublicKey();
    string ShowPrivateKey();
    int GetKeySize();
    void SetEphemeralPublicKeyAnotherParty(std::string );
};
