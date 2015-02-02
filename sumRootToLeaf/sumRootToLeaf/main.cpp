//
//  main.cpp
//  sumRootToLeaf
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
int total;
void dfs(TreeNode* root, int sum){
    if (!root) {
        return;
    }
    sum = 10*sum + root->val;
    if (!root->left && !root->right){
        total += sum;
        return;
    }
    dfs(root->left, sum);
    dfs(root->right, sum);
}

int sumNumbers(TreeNode *root) {
    total = 0;
    dfs(root, 0);
    return total;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
