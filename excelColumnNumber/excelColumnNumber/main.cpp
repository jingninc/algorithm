//
//  main.cpp
//  excelColumnNumber
//
//  Created by JINGNING CAO on 1/19/15.
//  Copyright (c) 2015 JINGNING CAO. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int num(char ch){
    return ch-'A'+1;
}

int titleToNumber(string s) {
    int sum = 0;
    for(int i = 0; i < s.size(); i++){
        sum = 26 * sum + num(s[i]);
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    cout << titleToNumber("AB") << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
