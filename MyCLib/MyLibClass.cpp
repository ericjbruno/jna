/* 
 * File:   MyLibClass.cpp
 * Author: ericjbruno
 */

#include "MyLibClass.h"

MyLibClass* m = new MyLibClass();
int value = 10;

extern "C" void callme(callback func) { 
    return m->callme(func); 
}

extern "C" int calc(int i) { 
    return m->calc(i); 
}

extern "C" const char* getname(void) {
    return strdup( m->getname().c_str() );
}

extern "C" void log(char* s) {
    return m->log(s);
}

MyLibClass::MyLibClass() { /* ... */ }

MyLibClass::~MyLibClass() { /* ... */ }

int MyLibClass::calc(int i) {
    return i * 2;
}

string MyLibClass::getname() {
    return "Eric J. Bruno";
}

void MyLibClass::callme(callback func) {
    if ( func ) {
        func( ++value );
    }
}

void MyLibClass::log(string s) {
    cout << s;
    cout << "\n";
}
