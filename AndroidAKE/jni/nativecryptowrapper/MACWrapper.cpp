#include "include/MACWrapper.h"


JNIEXPORT void JNICALL Java_com_example_androidake_MutualAuthenticateChip_prepare_1MAC_1CPP
  (JNIEnv *env, jobject thisObj){


};


JNIEXPORT jbyteArray JNICALL Java_com_example_androidake_MutualAuthenticateChip_get_1ephemeralkey_1CPP
  (JNIEnv *env, jobject thisObj){
	jbyteArray ephemeralkey_byte;

	return ephemeralkey_byte;
};


JNIEXPORT void JNICALL Java_com_example_androidake_MutualAuthenticateChip_set_1ephemeralkey_1from_1party_1CPP
  (JNIEnv *env, jobject thisObj, jbyteArray ephemeralkey_byte){


};


JNIEXPORT void JNICALL Java_com_example_androidake_MutualAuthenticateChip_prepare_1encryption_1CPP
  (JNIEnv *env, jobject thisObj, jboolean){


};


JNIEXPORT jbyteArray JNICALL Java_com_example_androidake_MutualAuthenticateChip_get_1encrypt_1cert_1and_1R_1CPP
  (JNIEnv *env, jobject thisObj){
	jbyteArray encryption_byte;

	return encryption_byte;

};


JNIEXPORT void JNICALL Java_com_example_androidake_MutualAuthenticateChip_set_1encryption_1from_1party_1CPP
  (JNIEnv *env, jobject thisObj, jbyteArray encryption_byte){


};


JNIEXPORT jboolean JNICALL Java_com_example_androidake_MutualAuthenticateChip_verif_1certificate_1CPP
  (JNIEnv *env, jobject thisObj){
	jboolean verif = true;

	return verif;
};


JNIEXPORT void JNICALL Java_com_example_androidake_MutualAuthenticateChip_compute_1session_1key_1CPP
  (JNIEnv *env, jobject thisObj){


};


JNIEXPORT jbyteArray JNICALL Java_com_example_androidake_MutualAuthenticateChip_get_1session_1key_1CPP
  (JNIEnv *env, jobject thisObj){


};