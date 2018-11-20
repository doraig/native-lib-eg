#include "library.h"

#include <iostream>
#include <string>
using namespace std;

JNIEXPORT jstring JNICALL Java_com_pigopoyo_jni_Main_message(JNIEnv *env, jobject thisObj, jstring msg) {
    const char *inStr = env->GetStringUTFChars(msg, NULL);
    if (NULL == inStr) {
        cout << "Hello World from C++!" << endl;
    }
    else {
        cout << "Hello World from C++! " << inStr << endl;
    }
    env->ReleaseStringUTFChars(msg, inStr);
    string outStr;
    cout << "Enter the string: ";
    getline(cin, outStr);
    cout << "Response from C++! " << outStr << endl;
    return env->NewStringUTF(outStr.c_str());
}

JNIEXPORT jdouble JNICALL Java_com_pigopoyo_jni_Main_avg(JNIEnv *env, jobject thisObj, jint n1, jint n2) {
    double returnVal;
    returnVal =  ((jdouble)n1 + n2)/2.0;
    return returnVal;
}


JNIEXPORT jdoubleArray JNICALL Java_com_pigopoyo_jni_Main_sumAvg(JNIEnv *env, jobject thisObj, jintArray numbers) {

    jint *intArray = env->GetIntArrayElements(numbers, NULL);

    if (NULL == intArray) return NULL;
    jsize length = env -> GetArrayLength(numbers);

    jint sum = 0;

    for (int i = 0 ; i < length; i++) {
        sum += intArray[i];
    }

    jdouble  avg = (jdouble)sum/length;
    env->ReleaseIntArrayElements(numbers, intArray, 0);

    jdouble outArray[] = {(jdouble)sum, avg};

    jdoubleArray  output = env->NewDoubleArray(2);

    env->SetDoubleArrayRegion(output, 0, 2, outArray);

    return output;
}

JNIEXPORT void JNICALL Java_com_pigopoyo_jni_Main_modifyValues(JNIEnv *env, jobject thisObj) {

    jclass cls = env->GetObjectClass(thisObj);

    jfieldID  jfieldID1 = env->GetFieldID(cls, "number", "I");

    if(NULL == jfieldID1) return;

    jint number = env -> GetIntField(thisObj, jfieldID1);

    cout << "In C++ the value is : " << number << endl;

    number = 99;

    env->SetIntField(thisObj, jfieldID1, number);


    jfieldID  jfieldID2 = env->GetStaticFieldID(cls, "number2", "D");

    if(NULL == jfieldID2) return;

    jdouble number2 = env -> GetStaticDoubleField(cls, jfieldID2);

    cout << "In C++ the value is : " << number2 << endl;

    number2 = 99.89;

    env->SetStaticDoubleField(cls, jfieldID2, number2);

    return;

}

JNIEXPORT void JNICALL Java_com_pigopoyo_jni_Main_nativeCall(JNIEnv *env, jobject thisObj) {
    jclass cls = env->GetObjectClass(thisObj);
    jmethodID  jmethodID1 = env->GetMethodID(cls, "callBack", "()V");

    if (NULL == jmethodID1) return;

    env->CallVoidMethod(thisObj, jmethodID1);
}

