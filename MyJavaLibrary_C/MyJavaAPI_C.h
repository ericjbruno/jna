/* 
 * File:   MyJavaAPI_C.h
 * Author: ericjbruno
 *
 * Created on November 14, 2016, 12:06 PM
 */

#ifndef MYJAVAAPI_C_H
#define MYJAVAAPI_C_H

#include <iostream>

using namespace std;

extern "C" int calc(int value);
extern "C" const char* getName(void);
extern "C" void log(char* msg);

class MyJavaAPI_C {
public:
    MyJavaAPI_C();
    MyJavaAPI_C(const MyJavaAPI_C& orig);
    virtual ~MyJavaAPI_C();
    
    // API
    int calc(int value);
    const char* getName(void);
    void log(char* msg);
private:
    
};

#endif /* MYJAVAAPI_C_H */

