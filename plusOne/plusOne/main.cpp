//
//  main.cpp
//  plusOne
//
//  Created by JINGNING CAO on 1/23/15.
//  Copyright (c) 2015 JINGNING CAO. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;

vector<int> plusOne(vector<int> &digits) {
    if (digits.empty()) return digits;
    int carry = 1;
    for(auto it = digits.rbegin(); it != digits.rend(); it++){
        int sum = *it + carry;
        *it = sum % 10;
        carry = sum/10;
    }
    if (carry > 0) digits.insert(digits.begin(), carry);
    return digits;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
