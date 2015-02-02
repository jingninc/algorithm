//
//  main.cpp
//  pow
//
//  Created by JINGNING CAO on 1/16/15.
//  Copyright (c) 2015 JINGNING CAO. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

double pow(double x, int n) {
    bool neg = (n < 0);
    unsigned int m = (neg) ? (0- n) : n;
    double res = 1;
    for(; m >= 1; ){
        double sub = x;
        unsigned int multi = 1;
        for(; m >= multi; multi += multi, sub *= sub){
            res *= sub;
            m -= multi;
            if (multi > INT_MAX/2) break;
        }
    }	
    return neg ? (1.0 / res) : res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
