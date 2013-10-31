#include <string.h>
#include <jni.h>

jstring Java_pl_ndk_ndktest_MainActivity_invokeNativeFunction(JNIEnv* env, jobject javaThis) {
  return (*env)->NewStringUTF(env, "Hello from native code!");
}
