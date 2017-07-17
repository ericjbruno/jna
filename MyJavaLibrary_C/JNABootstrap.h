/* 
 * File:   JNABootstrap.h
 * Author: ericjbruno
 */
#ifndef JNABOOTSTRAP_H
#define JNABOOTSTRAP_H

#include <jni.h>
#include <iostream>

char* OPTION_CP = (char* )"-Djava.class.path=";

// Path to the Java API code, and the JNA layer for it
char* CUSTOM_LIB = (char* )"/Users/ebruno/dev/MyJavaLibrary_JNA/build/classes:/Users/ericjbruno/Dropbox/dev/MyJavaLibrary/build/classes";

// Paths to the JNA components
char* JNA_LIB = (char* )"/Users/ebruno/dev/MyJavaLibrary_JNA/dist/lib/jna-4.2.2.jar";
char* JNA_PLATFORM_LIB = (char* )"/Users/ebruno/dev/MyJavaLibrary_JNA/dist/lib/jna-platform-4.2.2.ja";

// Path to the native version of the library
char* CUSTOM_C_LIB = (char* )"/Users/ebruno/dev/MyJavaLibrary_C/dist/Debug/GNU-MacOSX";

// Path to parts of the standard Java installation
char* JAVA_LIB = (char* )"/Library/Java/JavaVirtualMachines/jdk1.8.0_131.jdk/Contents/Home/jre/lib";
char* JLI_LIB = (char* )"/Library/Java/JavaVirtualMachines/jdk1.8.0_131.jdk/Contents/Home/jre/lib/jli";
char* SERVER_LIB = (char* )"/Library/Java/JavaVirtualMachines/jdk1.8.0_131.jdk/Contents/Home/jre/lib/server";

//char* JAVA_LIB = (char* )"/Library/Java/JavaVirtualMachines/jdk1.7.0_45.jdk/Contents/Home/jre/lib";
//char* JLI_LIB = (char* )"/Library/Java/JavaVirtualMachines/jdk1.7.0_45.jdk/Contents/Home/jre/lib/jli";
//char* SERVER_LIB = (char* )"/Library/Java/JavaVirtualMachines/jdk1.7.0_45.jdk/Contents/Home/jre/lib/server";

char* SEP = (char* )":";

JavaVM* jvm = NULL;
JNIEnv* env = NULL;
jobject object = NULL;

JNIEnv* create_vm(JavaVM ** jvm, char* classname) {
    JavaVMInitArgs vm_args;
    JavaVMOption options; 
    
    // Path to the java source code  
    int length = strlen(OPTION_CP) +
                 strlen(CUSTOM_LIB) + 
                 strlen(JNA_LIB) +
                 strlen(JNA_PLATFORM_LIB) +
                 strlen(CUSTOM_C_LIB) +
                 strlen(JAVA_LIB) +
                 strlen(JLI_LIB) +
                 strlen(SERVER_LIB) +
                 10;
    
    options.optionString = new char[length];
    strcpy(options.optionString, OPTION_CP);
    strcat(options.optionString, CUSTOM_LIB); strcat(options.optionString, SEP);
    strcat(options.optionString, JNA_LIB); strcat(options.optionString, SEP);
    strcat(options.optionString, JNA_PLATFORM_LIB); strcat(options.optionString, SEP);
    strcat(options.optionString, CUSTOM_C_LIB); strcat(options.optionString, SEP);
    strcat(options.optionString, JAVA_LIB); strcat(options.optionString, SEP);
    strcat(options.optionString, JLI_LIB); strcat(options.optionString, SEP);
    strcat(options.optionString, SERVER_LIB);

    printf("create_vm------------------------------\n");

    vm_args.version = JNI_VERSION_1_6;
    vm_args.nOptions = 1;
    vm_args.options = &options;
    vm_args.ignoreUnrecognized = 0;
    
    printf("Creating the JVM with classpath=%s\n", options.optionString);
    int ret = JNI_CreateJavaVM(jvm, (void**)&env, &vm_args);
    if ( ret < 0 ) {
        printf( "--Unable to Launch JVM\n" );
        return NULL;
    }

    //char* classname = (char* )"myjavalibrary_jna/MyJavaLibrary_JNA";
    printf("Looking for %s\n", classname);
    jclass cls = env->FindClass(classname);
    if ( ! cls ) {
        printf( "--Could not load %s\n", classname );
        return NULL;
    }
    
    printf("Getting main\n");
    jmethodID main_method = env->GetStaticMethodID(cls, "main", "([Ljava/lang/String;)V");
    if ( ! main_method ) {
        printf("--main_method is null!\n");
        return NULL;
    }

    printf("Getting constructor\n");
    jmethodID constructor = env->GetMethodID(cls, "<init>", "()V");
    if ( ! constructor ) {
        printf("--Could not load constructor\n");
        return NULL;
    }
    printf("--------------------------------------\n");

    return env;
}



#endif /* JNABOOTSTRAP_H */

