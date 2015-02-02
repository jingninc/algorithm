//
//  main.cpp
//  populateNextPointer_2
//
//  Created by JINGNING CAO on 1/18/15.
//  Copyright (c) 2015 JINGNING CAO. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode *root) {
    if (!root) return;
    for(TreeLinkNode* currLevel = root; currLevel; ){
        TreeLinkNode* dummy = new TreeLinkNode(-1);
        TreeLinkNode* nextLevel = dummy;
        for(; currLevel != NULL; currLevel = currLevel->next){
            if (currLevel->left) {
                nextLevel->next = currLevel->left;
                nextLevel = nextLevel->next;
            }
            if (currLevel->right){
                nextLevel->next = currLevel->right;
                nextLevel = nextLevel->next;
            }	
        }
        currLevel = dummy->next;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
