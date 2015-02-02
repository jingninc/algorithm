//
//  main.cpp
//  minDepthBinaryTree
//
//  Created by JINGNING CAO on 1/20/15.
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

struct Node{
    TreeNode* elem;
    int level;
    Node(TreeNode* e, int i): elem(e), level(i) {}
};

int minDepth(TreeNode *root) {
    if (!root) return 0;
    queue<Node*> q;
    q.push(new Node(root, 1));
    int smallest = INT_MAX;
    while(!q.empty() ){
        Node* curr = q.front();
        q.pop();
        if (!curr->elem->left && !curr->elem->right && curr->level < smallest){
            smallest = curr->level;
            continue;
        }
        // remove the branches.
        if (curr->level >= smallest) continue;
        if (curr->elem->left){
            q.push(new Node(curr->elem->left, curr->level+1) );
        }
        if (curr->elem->right){
            q.push(new Node(curr->elem->right, curr->level+1) );
        }
    }
    return smallest;
}


int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left ->left = new TreeNode(4);
    root->right = new TreeNode(3);
    cout << minDepth(root) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
