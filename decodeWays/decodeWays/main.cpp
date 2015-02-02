//
//  main.cpp
//  decodeWays
//
//  Created by JINGNING CAO on 1/20/15.
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

int numDecodings(string s) {
    if (s.size() == 0) return 0;
    int rows = s.size()+1;
    vector<int> A(rows, 0);
    A[0] = 1;
    for(int i = 1; i < rows; i++){
        if (i-1 >= 0 && s[i-1] >= '1' && s[i-1] <= '9'){
            A[i] += A[i-1];
        }
        if (i-2 >= 0){
            if ( (s[i-2] == '1' && s[i-1] >= '0' && s[i-1] <= '9')
                || (s[i-2] == '2' && s[i-1] >= '0' && s[i-1] <= '6') ){
                A[i] += A[i-2];
            }
        }
    }
    return A[rows-1];
}

int main(int argc, const char * argv[]) {
    cout << numDecodings("1517") << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
