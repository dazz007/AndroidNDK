/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_example_androidake_MutualAuthenticateChip */

#ifndef _Included_com_example_androidake_MutualAuthenticateChip
#define _Included_com_example_androidake_MutualAuthenticateChip
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_example_androidake_MutualAuthenticateChip
 * Method:    prepare_MAC_CPP
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_example_androidake_MutualAuthenticateChip_prepare_1MAC_1CPP
  (JNIEnv *, jobject);

/*
 * Class:     com_example_androidake_MutualAuthenticateChip
 * Method:    get_ephemeralkey_CPP
 * Signature: ()[B
 */
JNIEXPORT jbyteArray JNICALL Java_com_example_androidake_MutualAuthenticateChip_get_1ephemeralkey_1CPP
  (JNIEnv *, jobject);

/*
 * Class:     com_example_androidake_MutualAuthenticateChip
 * Method:    set_ephemeralkey_from_party_CPP
 * Signature: ([B)V
 */
JNIEXPORT void JNICALL Java_com_example_androidake_MutualAuthenticateChip_set_1ephemeralkey_1from_1party_1CPP
  (JNIEnv *, jobject, jbyteArray);

/*
 * Class:     com_example_androidake_MutualAuthenticateChip
 * Method:    prepare_encryption_CPP
 * Signature: (Z)V
 */
JNIEXPORT void JNICALL Java_com_example_androidake_MutualAuthenticateChip_prepare_1encryption_1CPP
  (JNIEnv *, jobject, jboolean);

/*
 * Class:     com_example_androidake_MutualAuthenticateChip
 * Method:    get_encrypt_cert_and_R_CPP
 * Signature: ()[B
 */
JNIEXPORT jbyteArray JNICALL Java_com_example_androidake_MutualAuthenticateChip_get_1encrypt_1cert_1and_1R_1CPP
  (JNIEnv *, jobject);

/*
 * Class:     com_example_androidake_MutualAuthenticateChip
 * Method:    set_encryption_from_party_CPP
 * Signature: ([B)V
 */
JNIEXPORT void JNICALL Java_com_example_androidake_MutualAuthenticateChip_set_1encryption_1from_1party_1CPP
  (JNIEnv *, jobject, jbyteArray);

/*
 * Class:     com_example_androidake_MutualAuthenticateChip
 * Method:    verif_certificate_CPP
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_com_example_androidake_MutualAuthenticateChip_verif_1certificate_1CPP
  (JNIEnv *, jobject);

/*
 * Class:     com_example_androidake_MutualAuthenticateChip
 * Method:    compute_session_key_CPP
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_example_androidake_MutualAuthenticateChip_compute_1session_1key_1CPP
  (JNIEnv *, jobject);

/*
 * Class:     com_example_androidake_MutualAuthenticateChip
 * Method:    get_session_key_CPP
 * Signature: ()[B
 */
JNIEXPORT jbyteArray JNICALL Java_com_example_androidake_MutualAuthenticateChip_get_1session_1key_1CPP
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif
