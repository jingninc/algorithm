//
//  main.cpp
//  levelOrderTraversal2_s2
//
//  Created by JINGNING CAO on 1/16/15.
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

void dfs(vector<vector<int> > &res, TreeNode *root, int level){
    if (!root) return;
    if (level == res.size()){
        vector<int> tmp;
        res.insert(res.begin(), tmp);
    }
    res[res.size()-1-level].push_back(root->val);
    dfs(res, root->left, level+1);
    dfs(res, root->right, level+1);
}

vector<vector<int> > levelOrderBottom(TreeNode *root) {
    vector<vector<int> > res;
    dfs(res, root, 0);
    return res;
}


int main(int argc, const char * argv[]) {
//    TreeNode* root = new TreeNode(3);
//    root ->left =new TreeNode(9);
//    root ->right =new TreeNode(20);
//    root ->right ->left=new TreeNode(15);
//    root ->right ->right =new TreeNode(7);
    
    TreeNode* root = new TreeNode(1);
    root ->left =new TreeNode(2);
    root ->right =new TreeNode(3);
    root ->right ->left=new TreeNode(5);
    root ->left ->right =new TreeNode(4);
    
    vector<vector<int> > res = levelOrderBottom(root);
    for (auto e : res){
        cout << "[";
        for(int elem : e){
            cout << elem << ",";
        }
        cout << "]" << endl;
    }

    std::cout << "Hello, World!\n";
    return 0;
}
