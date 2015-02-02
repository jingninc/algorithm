//
//  main.cpp
//  reorderList
//
//  Created by JINGNING CAO on 1/8/15.
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

void reverse(ListNode* &root){
    if (!root) return;
    ListNode* dummy = new ListNode(-1);
    dummy->next = NULL;
    for(ListNode* insert = root; insert; ){
        ListNode* nextInsert = insert->next;
        insert ->next = dummy->next;
        dummy->next = insert;
        insert = nextInsert;
    }
    root = dummy->next;
}   

void reorderList(ListNode *head) {
    if (!head || !head->next) return;
    ListNode* fast = head ->next;
    ListNode* slow = head;
    for(; fast->next && fast->next->next; fast=fast->next->next, slow=slow->next){}
    // cut into two lists.
    ListNode* back = slow ->next;
    slow->next = NULL;
    reverse(back);
    ListNode* dummy = new ListNode(-1);
    ListNode* pre= dummy;
    for(; head && back; ){
        ListNode* headNext = head->next;
        ListNode* backNext = back->next;
        pre->next = head;
        pre = pre->next;
        pre->next = back;
        pre = pre->next;
        head = headNext;
        back = back->next;
    }
    if (!head) pre->next = back;
    else pre->next = head;
    head = dummy->next;
}

int main(int argc, const char * argv[]) {
    ListNode *head = new ListNode(1);
    head -> next = new ListNode(2);
    head -> next -> next = new ListNode(3);
    head -> next -> next -> next= new ListNode(4);
    head -> next -> next -> next -> next = new ListNode(5);
    reorderList(head);
    while (head != NULL){
        cout << (head -> val) << endl;
        head = head -> next;
    }

    std::cout << "Hello, World!\n";
    return 0;
}
