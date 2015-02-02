//
//  main.cpp
//  intersectionOfLinkedList
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

int getLen(ListNode* head){
    int len = 0;
    while(head != NULL){
        len++;
        head = head->next;
    }
    return len;
}


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int len1 = getLen(headA);
    int len2 = getLen(headB);
    if (len1 == 0 || len2 == 0) return NULL;
    while (len1 != len2){
        if (len1 > len2) {
            headA= headA->next;
            len1--;
        } else{
            headB = headB->next;
            len2--;
        }
    }
    for(int i = 0; i < len1; headA=headA->next, headB=headB->next, i++){
        if (headA == headB) return headA;
    }
    return NULL;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
