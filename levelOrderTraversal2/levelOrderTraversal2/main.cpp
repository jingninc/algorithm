//
//  main.cpp
//  levelOrderTraversal2
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

vector<vector<int> > levelOrderBottom(TreeNode *root) {
    vector<vector<int> > res;
    if (!root) return res;
    TreeNode* SPACE = new TreeNode(0);
    queue<TreeNode*> q;
    q.push(SPACE);
    q.push(root);
    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();
        // exclude the case when it is the last space node.
        if (curr == SPACE ){
            if (q.empty()) break;
            vector<int> tmp;
            res.insert(res.begin(), tmp);
            q.push(SPACE);
        } else {
            res.front().push_back(curr->val);
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }    
    return res;
}


int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(3);
    root ->left =new TreeNode(9);
    root ->right =new TreeNode(20);
    root ->right ->left=new TreeNode(15);
    root ->right ->right =new TreeNode(7);
    
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
