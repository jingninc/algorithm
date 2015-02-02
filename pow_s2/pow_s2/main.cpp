//
//  main.cpp
//  pow_s2
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

double power(double x, unsigned int n){
    if (n == 0) return 1;
    if (n == 1) return x;
    double half = power(x, n/2);
    double res = half* half;
    if (n % 2 == 0) return res;
    return res* x;
}


double pow(double x, int n) {
    bool neg = (n < 0);
    unsigned int m = (neg) ? (0- n) : n;
    return (neg) ? (1.0 / power(x, m)) : power(x, m);
}

int main(int argc, const char * argv[]) {
    cout << pow(3, -5) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
