//
//  main.cpp
//  uniqueBST_2
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


int id;
void dfs(TreeNode* root){
    if (!root) return;
    dfs(root->left);
    root->val = ++id;
    dfs(root->right);
}

unordered_map<int, vector<TreeNode*>>treeMap;
vector<TreeNode*> generateTrees(int n) {
    if (n == 0) {
        return {NULL};
    }
    if (treeMap.count(n) > 0 ) return treeMap[n];
    vector<TreeNode*> res;
    for(int i = 0; i <= n-1; i++) {
        vector<TreeNode*> v1 = generateTrees(i);
        vector<TreeNode*> v2 = generateTrees(n-1-i);
        for(auto elem1 : v1){
            for(auto elem2 : v2){
                TreeNode* root = new TreeNode(0);
                root->left = elem1;
                root->right = elem2;
                id = 0;
                dfs(root);
                res.push_back(root);
            }
        }
    }   
    return res;
}

void display(TreeNode* root){
    if (!root) return;
    cout << root->val <<", ";
    display(root->left);
    display(root->right);
}

int main(int argc, const char * argv[]) {
    vector<TreeNode*> res = generateTrees(4);
    for(auto e : res){
        display(e);
        cout << endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
