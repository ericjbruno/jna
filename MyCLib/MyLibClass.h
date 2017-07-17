/*
 * File:   MyLibClass.h
 * Author: ericjbruno
 */

#ifndef MYLIBCLASS_H
#define MYLIBCLASS_H

//#include "stdio.h"
//#include "stdlib.h"
#include <iostream>

using namespace std;

typedef void (*callback) (int); // for callback

class MyLibClass {
public:
    MyLibClass();
    virtual ~MyLibClass();
    
    int calc(int i);
    string getname(void);
    void callme(callback func);
    void log(string s);
};

#endif /* MYLIBCLASS_H */

