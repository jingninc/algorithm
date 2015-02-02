//
//  main.cpp
//  rotateList
//
//  Created by JINGNING CAO on 1/25/15.
//  Copyright (c) 2015 JINGNING CAO. All rights reserved.
//

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


int getLen(ListNode* head){
    int len = 0;
    while(head){
        len++;
        head=head->next;
    }
    return len;
}

ListNode *rotateRight(ListNode *head, int k) {
    if (!head) return head;
    k = k % getLen(head);
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode* advance = dummy;
    for(int i = 0; i < k; i++, advance =advance->next){}
    ListNode* pre = dummy;
    for(; advance->next; advance=advance->next, pre=pre->next){}
    advance->next = dummy->next;
    ListNode* newHead = pre->next;
    pre->next = NULL;        
    return newHead;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
