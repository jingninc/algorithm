//
//  main.cpp
//  removeDupFromList_S2
//
//  Created by JINGNING CAO on 2/1/15.
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

ListNode *deleteDuplicates(ListNode *head) {
    ListNode* dummy = new ListNode(-1);
    dummy ->next = head;
    ListNode* pre = dummy;
    for(; pre->next; ){
        ListNode* curr = pre->next;
        if (!(curr->next) || (curr->next->val != curr->val)) {
            pre->next = curr;
            // move forward in this case.
            pre=pre->next;
        }
        else {
            for(curr=curr->next; curr && curr->val == pre->next->val;  curr=curr->next){}
            pre->next =curr;
            // don't move forward in this case.
        }
    }
    return dummy->next;
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
