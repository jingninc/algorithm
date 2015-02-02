//
//  main.cpp
//  mergeKSortedList
//
//  Created by JINGNING CAO on 1/14/15.
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


ListNode* mergeSort(ListNode* head){
    if (!head || !head->next) return head;
    ListNode* fast = head->next;
    ListNode* slow = head;
    for(; fast->next && fast->next->next; fast=fast->next->next, slow=slow->next){}
    ListNode* back = slow->next;
    slow->next = NULL;
    ListNode* p = mergeSort(head);
    ListNode* q = mergeSort(back);
    ListNode* dummy = new ListNode(-1);
    ListNode* pre = dummy;
    for(; p || q; pre= pre->next){
        int num1 = (p == NULL) ? INT_MAX : p->val;
        int num2 = (q == NULL) ? INT_MAX : q->val;
        if (num1 < num2){
            pre->next = p;
            p = p->next;
        } else {
            pre ->next= q;
            q = q->next;
        }
    }
    return dummy->next;
}


ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.size() == 0) return NULL;
    ListNode* dummy = new ListNode(-1);
    ListNode* pre = dummy;
    for(int i = 0; i < lists.size(); i++){
        for(ListNode* it = lists[i]; it; it= it->next){
            pre->next = it;
            pre =pre->next;
        }
    }        
    return mergeSort(dummy->next);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
