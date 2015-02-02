//
//  main.cpp
//  validateBST_s2
//
//  Created by JINGNING CAO on 1/5/15.
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

bool valid(TreeNode* root, TreeNode* lower, TreeNode* upper){
    if (!root) return true;
    bool lc = valid(root->left, lower, root);
    bool rc = valid(root->right, root, upper);
    
    if (lower != NULL && lower->val >= root->val) return false;
    if (upper != NULL && upper->val <= root->val) return false;
    return  lc && rc;
}

bool isValidBST(TreeNode *root) {
    return valid(root, NULL, NULL);
}

int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(0);
    root->right = new TreeNode(-1);
    cout << isValidBST(root) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}

