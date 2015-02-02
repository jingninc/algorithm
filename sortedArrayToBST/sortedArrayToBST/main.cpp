//
//  main.cpp
//  sortedArrayToBST
//
//  Created by JINGNING CAO on 1/11/15.
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

template<typename T>
TreeNode* recur(T first, T last){
    if (first == last) return NULL;
    auto mid = first+ distance(first, last)/2;
    TreeNode* root = new TreeNode(*mid);
    TreeNode* lc = recur(first, mid);
    TreeNode* rc = recur(mid+1, last);
    root ->left = lc;
    root->right = rc;
    return root;
}

TreeNode *sortedArrayToBST(vector<int> &num) {
    return recur(num.begin(), num.end() );
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
