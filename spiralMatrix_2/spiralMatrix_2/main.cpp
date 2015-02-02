//
//  main.cpp
//  spiralMatrix_2
//
//  Created by JINGNING CAO on 1/22/15.
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

vector<vector<int> > generateMatrix(int n) {
    vector<vector<int> > res(n, vector<int>(n, 0));
    int begin = 0;
    int end = 0;
    int level = 0;
    int id = 1;
    while(true){
        if (begin >= n-end) break;
        for(int col = begin; col < n-end; col++){
            res[level][col] = id++;
        }
        if (++begin >= n-end) break;
        for(int row = begin; row < n-end; row++){
            res[row][n-1-level] = id++;
        }
        if (n-1-begin < end) break;
        for(int col = n-1-begin; col >= end; col--){
            res[n-1-level][col] = id++;
        }
        if (n-1-begin < ++end) break;
        for(int row = n-1-begin; row >= end; row--){
            res[row][level] = id++;
        }
        level++;
    }
    return res;
}

int main(int argc, const char * argv[]) {
    vector<vector<int> > res = generateMatrix(5);
    for(int i = 0; i < res.size(); i++){
        cout << "[";
        for(int j = 0; j < res.size(); j++){
            cout << res[i][j] << ",";
        }
        cout << "]"<< endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
