//
//  Calculate.cpp
//  HelloWorld
//
//  Created by Mikael Hermansson on 2014-01-12.
//  Copyright (c) 2014 Mikael Hermansson. All rights reserved.
//

#include "Calculate.h"

int addInt(int left, int right) {
    return left + right;
}

int subtractInt(int left, int right) {
    return left - right;
}

int multipyInt(int left, int right) {
    return left * right;
}

double divideInt(int left, int right) {
    double dLeft = left;
    double dRight = right;
    return dLeft/dRight;
}