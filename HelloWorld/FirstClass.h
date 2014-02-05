//
//  FirstClass.h
//  HelloWorld
//
//  Created by Mikael Hermansson on 2014-01-12.
//  Copyright (c) 2014 Mikael Hermansson. All rights reserved.
//

#ifndef __HelloWorld__FirstClass__
#define __HelloWorld__FirstClass__

#include <iostream>

using namespace std;

class MyFirstClass {
public:
    MyFirstClass();

    MyFirstClass(string name);

    MyFirstClass(int intArg);

    MyFirstClass(string name1, string name2);

    void sayHello();

private:
    string stateString;
    int val;

    void internalSayHello();
};



#endif /* defined(__HelloWorld__FirstClass__) */
