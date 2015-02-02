//
//  main.cpp
//  interLeaveString
//
//  Created by JINGNING CAO on 1/13/15.
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

bool isInterleave(string s1, string s2, string s3) {
    if (s1.size() + s2.size() != s3.size()) return false;
    if (s2.size() == 0 ) return (s1 == s3);
    if (s1.size() == 0) return (s2 == s3);
    int rows = s2.size()+1;
    int cols = s1.size()+1;
    vector<vector<bool>> A(rows, vector<bool>(cols, false));
    A[0][0] = true;
    for(int row = 1; row < rows; row++){
        if (A[row-1][0] && s2[row-1] == s3[row-1]) A[row][0] = true;
    }
    for(int col = 1; col < cols; col++){
        if (A[0][col-1] && s1[col-1] == s3[col-1]) A[0][col] = true;
    }
    for(int row = 1; row < rows; row++){
        for(int col = 1; col < cols; col++){
            if (A[row-1][col] && s2[row-1] == s3[row+col-1]) A[row][col] = true;
            if (A[row][col-1] && s1[col-1] == s3[row+col-1]) A[row][col] = true;
        }
    }
    return A[rows-1][cols-1];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
