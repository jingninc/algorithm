//
//  main.cpp
//  grayCode
//
//  Created by JINGNING CAO on 1/9/15.
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

vector<int> grayCode(int n) {
    vector<int> res;
    res.push_back(0);
    if (n <= 0) return res;
    for(int i = 1; i <= n; i++){
        int prefix = 1 << (i-1);
        int size = res.size();
        for(int j = size-1; j >= 0; j--){
            res.push_back(res[j] | prefix); // | represents addition here.
        }
    }
    return res;
    
}

int main(int argc, const char * argv[]) {
    vector<int> res = grayCode(4);
    for(auto e : res){
        cout << e << endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
