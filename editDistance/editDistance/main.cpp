//
//  main.cpp
//  editDistance
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

int minDistance(string word1, string word2) {
    int cols = word1.size()+1;
    int rows = word2.size()+1;
    vector<vector<int>> S(rows, vector<int>(cols, 0));
    for(int i = 1; i < cols; i++){
        S[0][i] = i;
    }
    for(int i = 1; i < rows; i++){
        S[i][0] = i;
    }
    for(int row = 1; row < rows; row++){
        for(int col = 1; col < cols ; col++){
            if (word2[row-1] == word1[col-1]){
                S[row][col] = S[row-1][col-1];
            } else S[row][col] = S[row-1][col-1]+1;
            if (min(S[row-1][col]+1, S[row][col-1]+1) < S[row][col]){
                S[row][col] = min(S[row-1][col]+1, S[row][col-1]+1);
            }
        }
    }
    return S[rows-1][cols-1];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
