//
//  main.cpp
//  constructFromPosAndIn
//
//  Created by JINGNING CAO on 1/20/15.
//  Copyright (c) 2015 JINGNING CAO. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
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

template<typename T>
TreeNode* build(T head1, int len1, T head2, int len2){
    if (len1 == 0) return NULL;
    int rootVal = *(head2+ len2-1);
    auto rootPos = find(head1, head1+len1, rootVal);
    int leftLen = distance(head1, rootPos);
    int rightLen = len1-1-leftLen;
    TreeNode* root = new TreeNode(rootVal);
    root->left = build(head1, leftLen, head2, leftLen);
    root->right = build(rootPos+1, rightLen, head2+leftLen, rightLen);
    return root;
}


TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    return build(inorder.begin(), inorder.size(), postorder.begin(), postorder.size());
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
