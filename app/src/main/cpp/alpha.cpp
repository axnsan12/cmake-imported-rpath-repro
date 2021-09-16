#include <android/log.h>
#include <jni.h>

extern const char* hello_beta();

extern "C"
JNIEXPORT void JNICALL
Java_com_example_rpath_MainActivity_callAlpha(JNIEnv *env, jclass clazz) {
    __android_log_print(ANDROID_LOG_INFO, "rpath", "hello from alpha");
    __android_log_print(ANDROID_LOG_INFO, "rpath", "%s", hello_beta());
}
