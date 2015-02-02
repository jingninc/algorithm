//
//  main.cpp
//  isSymmetric_S3
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

bool isSymmetric(TreeNode *root) {
    if (!root) return true;
    stack<TreeNode*> s1;
    stack<TreeNode*> s2;
    TreeNode* lc = root->left;
    TreeNode* rc = root->right;
    s1.push(lc);
    s2.push(rc);
    while(!s1.empty() && !s2.empty() ){
        lc = s1.top();
        s1.pop();
        rc = s2.top();
        s2.pop();
        if (!lc && !rc) continue;
        if ((!lc && rc) || (lc && !rc)) return false;
        // lc && rc
        if (lc->val != rc->val) return false;
        s1.push(lc->right);
        s1.push(lc->left);
        s2.push(rc->left);
        s2.push(rc->right);
    }
    if ( (s1.empty() && !s2.empty() ) || (!s1.empty()&& s2.empty() )) return false;
    return true;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
