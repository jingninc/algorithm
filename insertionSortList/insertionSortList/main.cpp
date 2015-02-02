//
//  main.cpp
//  insertionSortList
//
//  Created by JINGNING CAO on 1/13/15.
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



//ListNode *insertionSortList(ListNode *head) {
//    if (!head) return head;
//    ListNode* dummy = new ListNode(-1);
//    for(ListNode* insert = head; insert; ){
//        ListNode* nextInsert = insert->next;
//        ListNode* pre = dummy;
//        ListNode* node = new ListNode(insert->val);
//        for(; pre->next; ){
//            if (node->val <= pre->next->val){
//                node->next = pre->next;
//                pre->next = node;
//                break;
//            } else pre=pre->next;
//        }
//        if (!pre->next) pre->next = node;
//        insert = nextInsert;
//    }   
//    return dummy->next;
//}

ListNode *insertionSortList(ListNode *head) {
    if (!head) return head;
    ListNode* dummy = new ListNode(-1);
    dummy->next = NULL;
    for(ListNode* insert = head; insert; ){
        ListNode* nextInsert = insert->next;
        ListNode* pre = dummy;
        for(; pre->next; ){
            if (insert->val <= pre->next->val){
                insert->next = pre->next;
                pre->next = insert;
                break;
            } else pre=pre->next;
        }
        // for the first node, inserted node points to NULL, dummy node points to inserted node.
        if (!pre->next) {
            insert->next = pre->next;
            pre->next = insert;
        }
        insert = nextInsert;
    }
    return dummy->next;
}


int main(int argc, const char * argv[]) {
    ListNode* head = new ListNode(7);
    head ->next = new ListNode(4);
    head ->next->next = new ListNode(2);
    head ->next ->next->next= new ListNode(6);
    head ->next ->next ->next->next= new ListNode(3);
    ListNode* res = insertionSortList(head);
    for(; res; res= res->next){
        cout << res->val << ",";
    }

    std::cout << "Hello, World!\n";
    return 0;
}
