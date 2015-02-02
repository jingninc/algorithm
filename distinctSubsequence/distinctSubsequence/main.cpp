//
//  main.cpp
//  distinctSubsequence
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};



int numDistinct(string S, string T) {
    // for empty string, the first row/ col represent the empty string.
    int rows = T.size()+1;
    int cols = S.size()+1;
    vector<vector<int>> A(rows, vector<int>(cols, 0));
    // row is T’s character , to match
    // col is S’s character, to choose from.
    for(int i = 0; i < cols; i++){
        A[0][i] = 1;
    }
    for(int row = 1; row < rows; row++){
        for(int col = 1; col < cols; col++){
            if (S[col-1] == T[row-1]){
                A[row][col] += A[row-1][col-1];
            }
            A[row][col] += A[row][col-1];
        }
    }
    return A[rows-1][cols-1];
}

int main(int argc, const char * argv[]) {
//    string S = "rabbbit";
    string S = "";
//    string T = "rabbit";
    string T = "";
    cout << numDistinct(S, T) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}





