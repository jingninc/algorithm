//
//  main.cpp
//  reverseInteger
//
//  Created by JINGNING CAO on 1/11/15.
//  Copyright (c) 2015 JINGNING CAO. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int reverse(int x) {
    int sum = 0;
    while(x != 0){
        if (sum > INT_MAX/ 10 || sum < INT_MIN/10) return 0;
        sum = 10* sum+ x%10;
        x = x/10;
    }
    return sum;
}


int main(int argc, const char * argv[]) {
    cout << reverse(1463847412)<< endl;
    std::cout << "Hello, World!\n";
    return 0;
}
