//
//  main.cpp
//  addBinary
//
//  Created by JINGNING CAO on 1/16/15.
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


string addBinary(string a, string b) {
    string s;
    auto p = a.rbegin();
    auto q = b.rbegin();
    int increment = 0;
    for(; p != a.rend() || q != b.rend(); ){
        int val1 = (p == a.rend()) ? 0 : (*p - '0');
        int val2 = (q == b.rend()) ? 0 : (*q - '0');
        if (p != a.rend()) p++;
        if (q != b.rend()) q++;
        int sum = val1 + val2 + increment;
        char tmp = (sum % 2) + '0';
        increment = sum / 2;
        s.insert(s.begin(), tmp);
    }
    if (increment > 0) s.insert(s.begin(), increment+ '0');
    return s;
}

int main(int argc, const char * argv[]) {
    cout << addBinary("10", "11") << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
