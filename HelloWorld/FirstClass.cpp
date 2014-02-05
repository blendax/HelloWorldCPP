//
//  FirstClass.cpp
//  HelloWorld
//
//  Created by Mikael Hermansson on 2014-01-12.
//  Copyright (c) 2014 Mikael Hermansson. All rights reserved.
//

#include "FirstClass.h"

using namespace std;

void MyFirstClass::sayHello(){
    internalSayHello();
}

void MyFirstClass::internalSayHello(){
    cout << "Hello " << stateString << "\n";
}

MyFirstClass::MyFirstClass() : val(7) {
    stateString = to_string(val);
}

MyFirstClass::MyFirstClass(string name) : stateString(name) {
}

MyFirstClass::MyFirstClass(string name1, string name2){
    stateString = name1 + " " + name2;
}