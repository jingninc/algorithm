//
//  main.cpp
//  multiplyTwoIntegers
//
//  Created by JINGNING CAO on 12/30/14.
//  Copyright (c) 2014 JINGNING CAO. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int multiply(int num1, int num2){
    bool neg = (num1 > 0 && num2 < 0) || (num1 < 0 && num2 > 0);
    unsigned int m = (num1 < 0) ? (0- num1) : num1;
    unsigned int n = (num2 < 0) ? (0- num2) : num2;
    int res = 0;
    for(; n >= 1; ){
        unsigned int multi = 1;
        unsigned int sub = m;
        for(; n >= multi; multi += multi, sub += sub){
            res += sub;
            n -= multi;
            if (sub >= INT_MAX>>1 || multi >= INT_MAX >>1) break;
        }
    }
    return (neg) ? (0- res) : res;
}


int main(int argc, const char * argv[]) {
    cout << multiply(18, 80) << endl;
    cout << multiply(-19, 3) << endl;
    cout << multiply(-1, INT_MIN) << endl;
    cout << multiply(1, INT_MIN) << endl;
    cout << multiply(-1, INT_MAX) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
