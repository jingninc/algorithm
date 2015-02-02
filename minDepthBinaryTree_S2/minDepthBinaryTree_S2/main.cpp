//
//  main.cpp
//  minDepthBinaryTree_S2
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// judge whether it is the leaf node by the existence of the cousin.
int dfs(TreeNode* root, bool cousin){
    if (!root) return (cousin) ? INT_MAX : 0;
    int lc = dfs(root->left, (root->right != NULL) );
    int rc = dfs(root->right, (root->left != NULL) );
    return 1 + min(lc, rc);
}

int minDepth(TreeNode *root) {
    if (!root) return 0;
    return dfs(root, false);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
