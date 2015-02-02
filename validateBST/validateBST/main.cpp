//
//  main.cpp
//  validateBST
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
struct BST{
    TreeNode* root;
    int upper;
    int lower;
    bool valid;
    BST(TreeNode* tn, int i, int j, bool b): root(tn), upper(i), lower(j),
    valid(b){}
};

BST const LEAF = BST(NULL, INT_MIN, INT_MAX, true);
BST dfs(TreeNode* root){
    if (!root) return LEAF;
    BST lc = dfs(root->left);
    BST rc = dfs(root->right);
    
    int lo = min(root->val, lc.lower);
    int up = max(root->val, rc.upper);
    bool isValid = (lc.upper < root->val) && (rc.lower > root->val) && lc.valid && rc.valid;
    return BST(root, up, lo, isValid);
}

bool isValidBST(TreeNode *root) {
    BST res = dfs(root);
    return res.valid;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
