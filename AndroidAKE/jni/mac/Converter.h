#pragma once
#include <string>
#include <iostream>
#include <strstream>
#include "cryptopp/secblock.h"
using CryptoPP::SecByteBlock;

#include "cryptopp/integer.h"
using CryptoPP::Integer;

class Converter
{
public:
	static std::string SecByteBlockToString(SecByteBlock );
	static void FromStringToSecByteblock(std::string, SecByteBlock*, int);
	static void TestIntegerAndSecByteBlock(Integer, SecByteBlock *);
};

