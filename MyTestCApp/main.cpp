/* 
 * File:   main.cpp
 * Author: ericjbruno
 */

#include <cstdlib>

#include <cstdlib>
#include <iostream>
#include "MyJavaAPI_C.h"

#include <unistd.h>

unsigned int microseconds = 1000000;

using namespace std;

int main(int argc, char** argv) {

    int val = 2;

    bool useCPP = false; // use the C or C++ API?
    
    if ( useCPP ) {
        // Use C++ API
        MyJavaAPI_C* pMyJavaAPI = new MyJavaAPI_C();
        
        const char* thisGuy = pMyJavaAPI->getName();
        
        pMyJavaAPI->log( (char* )thisGuy );
        
        for ( int x = 0; x < 5; x++ ) {
            val = pMyJavaAPI->calc(val);
            printf("In C++: value returned: %d\n", val);
        }
        delete pMyJavaAPI;
    }
    else {
        // Use C API
        const char* thisGuy = getName();
        
        log( (char* )thisGuy );
        
        for ( int x = 0; x < 5; x++ ) {
            val = calc(val);
            printf("In C: value returned: %d\n", val);
        }
    }
    
    return 0;
}

