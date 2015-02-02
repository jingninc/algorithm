//
//  main.cpp
//  addBinary2
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
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int increment = 0;
    for(int i = 0; i < max(a.size(), b.size() ); i++){
        int val1 = (i < a.size()) ? (a[i]-'0') : 0;
        int val2 = (i < b.size()) ? (b[i]-'0') : 0;
        int sum = val1 + val2 + increment;
        s.insert(s.begin(), (sum%2) + '0');
        increment = sum / 2;
    }
    if (increment > 0) s.insert(s.begin(), increment+ '0');
    return s;
}

int main(int argc, const char * argv[]) {
    cout << addBinary("10", "11") << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
