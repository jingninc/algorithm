//
//  main.cpp
//  removeDupFromList
//
//  Created by JINGNING CAO on 1/12/15.
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

ListNode *deleteDuplicates(ListNode *head) {
    if (!head) return head;
    ListNode* pre = head;
    for(; pre->next; ){
        ListNode* curr= pre->next;
        if (curr->val == pre->val){
            pre->next = curr->next;
        } else { // curr->val != pre->val  proceed
            pre= pre->next;
        }
    }
    return head;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
