//
//  main.cpp
//  sortList
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *sortList(ListNode *head) {
    if (!head || !head->next) return head;
    ListNode* fast = head->next;
    ListNode* slow = head;
    for(; fast->next && fast->next->next; fast=fast->next->next, slow=slow->next){}
    ListNode* back = slow->next;
    slow->next = NULL;
    ListNode* p = sortList(head);
    ListNode* q = sortList(back);
    ListNode* dummy = new ListNode(-1);
    // terminating condition should not be opposite.
    for(ListNode* pre = dummy; p || q; pre=pre->next){
        int val1 = (p == NULL) ? INT_MAX : p->val;
        int val2 = (q == NULL) ? INT_MAX : q->val;
        if (val1 < val2){
            pre->next = p;
            p = p->next;
        } else{
            pre->next = q;
            q= q->next;
        }
    }
    return dummy->next;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
