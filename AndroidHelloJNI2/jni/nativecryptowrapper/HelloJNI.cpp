#include <jni.h>
#include <iostream>
#include <string>
#include <sstream>
#include "include/HelloJNI.h"
#include "mca/MAC.h"

#include "cryptopp/nbtheory.h"
#include "cryptopp/osrng.h"
#include "cryptopp/dh.h"
#include "cryptopp/secblock.h"

using std::string;

static int dup = 0;

static MAC mac(10);

int add2add(int y, int b){
	int c = y + b;
	return c;
}

JNIEXPORT jdouble JNICALL Java_com_mytest_androidhellojni2_JNIActivity_getMessage
          (JNIEnv *env, jobject thisObj) {
	CryptoPP::Integer p("0xB10B8F96A080E01DDE92DE5EAE5D54EC52C99FBCFB06A3C6"
			              "9A6A9DCA52D23B616073E28675A23D189838EF1E2EE652C0"
			              "13ECB4AEA906112324975C3CD49B83BFACCBDD7D90C4BD70"
			              "98488E9C219A73724EFFD6FAE5644738FAA31A4FF55BCCC0"
			              "A151AF5F0DC8B4BD45BF37DF365C1A65E68CFDA76D4DA708"
			              "DF1FB2BC2E4A4371");

	CryptoPP::Integer g("0xA4D1CBD5C3FD34126765A442EFB99905F8104DD258AC507F"
			  "D6406CFF14266D31266FEA1E5C41564B777E690F5504F213"
			  "160217B4B01B886A5E91547F9E2749F4D7FBD7D3B9A92EE1"
			  "909D0D2263F80A76A6A24C087A091F531DBF0A0169B6A28A"
			  "D662A4D18E73AFA32D779D5918D08BC8858F4DCEF97C2A24"
			  "855E6EEB22B3B2E5");

	CryptoPP::Integer q("0xF518AA8781A8DF278ABA4E7D64B7CB9D49462353");

	CryptoPP::DH dh;
	CryptoPP::AutoSeededRandomPool rnd;

	dh.AccessGroupParameters().Initialize(p, q, g);
	CryptoPP::SecByteBlock privKey(dh.PrivateKeyLength());
	CryptoPP::SecByteBlock pubKey(dh.PublicKeyLength());
	dh.GenerateKeyPair(rnd, privKey, pubKey);

	CryptoPP::Integer x, y;

	x.Decode(privKey.BytePtr(), privKey.SizeInBytes());
		//    cout << "Shared secret (A): " << std::hex << x << endl;

	y.Decode(pubKey.BytePtr(), pubKey.SizeInBytes());
		//    cout << "Shared secret (B): " << std::hex << y << endl;


	CryptoPP::Integer gx = a_exp_b_mod_c(g, x, p);
	jdouble result;
	if(gx == y){
		result = 11111111111111111;
			    }else{
			    	result = 00000010000100;
			    }


//
//
//	string output_str;
//	result = 1000011212121;
//	std::cout << output_str << std::endl;
   return result;
}

JNIEXPORT jbyteArray JNICALL Java_com_mytest_androidhellojni2_JNIActivity_byteTest(JNIEnv *env, jobject thisObj){

	mac.doubleState();
	string output_str;
	output_str = "test kurwa: ";
	dup = mac.state;
	std::stringstream sstm;
	sstm << output_str << dup;
	output_str = sstm.str();

	jbyteArray returns = env->NewByteArray(output_str.length());
	env->SetByteArrayRegion(returns, 0, output_str.length(), (jbyte*)output_str.c_str());

	return returns;
}


//JNIEXPORT jdouble JNICALL Java_com_mytest_androidhellojni2_JNIActivity_average
//          (JNIEnv *env, jobject obj, jint n1, jint n2) {
//   jdouble result;
//   cout << "In C++, the numbers are " << n1 << " and " << n2 << endl;
//   result = ((jdouble)n1 + n2) / 2.0;
//   // jint is mapped to int, jdouble is mapped to double
//   return result;
//}
//
//
//JNIEXPORT jstring JNICALL Java_com_mytest_androidhellojni2_JNIActivity_sayHello(JNIEnv *env, jobject thisObj, jstring inJNIStr) {
//	// Step 1: Convert the JNI String (jstring) into C-String (char*)
//	   const char *inCStr = env->GetStringUTFChars(inJNIStr, NULL);
//	   if (NULL == inCStr) return NULL;
//
//	   // Step 2: Perform its intended operations
//	   cout << "In C++, the received string is: " << inCStr << endl;
//	   env->ReleaseStringUTFChars(inJNIStr, inCStr);  // release resources
//
//	   // Prompt user for a C++ string
//	   string outCppStr;
//	   cout << "Enter a String: ";
//
//	   outCppStr = "blallalal";
//
//	   // Step 3: Convert the C++ string to C-string, then to JNI String (jstring) and return
//	   return env->NewStringUTF(outCppStr.c_str());
//}


JNIEXPORT jstring JNICALL Java_com_mytest_androidhellojni2_JNIActivity_testSchnorr
		(JNIEnv *env, jobject thisObj){
//
			CryptoPP::Integer p("0xB10B8F96A080E01DDE92DE5EAE5D54EC52C99FBCFB06A3C6"
								  "9A6A9DCA52D23B616073E28675A23D189838EF1E2EE652C0"
								  "13ECB4AEA906112324975C3CD49B83BFACCBDD7D90C4BD70"
								  "98488E9C219A73724EFFD6FAE5644738FAA31A4FF55BCCC0"
								  "A151AF5F0DC8B4BD45BF37DF365C1A65E68CFDA76D4DA708"
								  "DF1FB2BC2E4A4371");
//
//			CryptoPP::Integer g("0xA4D1CBD5C3FD34126765A442EFB99905F8104DD258AC507F"
//		              "D6406CFF14266D31266FEA1E5C41564B777E690F5504F213"
//		              "160217B4B01B886A5E91547F9E2749F4D7FBD7D3B9A92EE1"
//		              "909D0D2263F80A76A6A24C087A091F531DBF0A0169B6A28A"
//		              "D662A4D18E73AFA32D779D5918D08BC8858F4DCEF97C2A24"
//		              "855E6EEB22B3B2E5");
//
//			CryptoPP::Integer q("0xF518AA8781A8DF278ABA4E7D64B7CB9D49462353");
//
//			CryptoPP::DH dh;
//			CryptoPP::AutoSeededRandomPool rnd;
//
//		    dh.AccessGroupParameters().Initialize(p, q, g);
//		    CryptoPP::SecByteBlock privKey(dh.PrivateKeyLength());
//		    CryptoPP::SecByteBlock pubKey(dh.PublicKeyLength());
//		    dh.GenerateKeyPair(rnd, privKey, pubKey);
//
//		    CryptoPP::Integer x, y;
//
//		    x.Decode(privKey.BytePtr(), privKey.SizeInBytes());
//		        //    cout << "Shared secret (A): " << std::hex << x << endl;
//
//		    y.Decode(pubKey.BytePtr(), pubKey.SizeInBytes());
//		        //    cout << "Shared secret (B): " << std::hex << y << endl;
//
//
//		    CryptoPP::Integer gx = a_exp_b_mod_c(g, x, p);
//		    cout << "keys correct " << (gx == y) << endl;
		    string output_str;
//		    output_str.getBytes();
//		    if(gx == y){
//		    	output_str = "dzia�a.";
//		    }else{
		    	output_str = "nie dzia�a.";
//		    }

		    	jstring dupa = (env)->NewStringUTF(output_str.c_str());
//		    	(env)->NewStringUTF((const char* )result.c_str());
	return dupa;
}
