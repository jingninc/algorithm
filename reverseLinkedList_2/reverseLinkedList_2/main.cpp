//
//  main.cpp
//  reverseLinkedList_2
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

ListNode *reverseBetween(ListNode *head, int m, int n) {
    if (!head) return NULL;
    ListNode* dummy = new ListNode(-1);
    dummy ->next = head;
    ListNode* pre = dummy;
    for(int i = 0; i < m-1; i++){
        pre= pre->next;
    }
    ListNode* it = pre->next;
    pre ->next = NULL;
    for(int i = m; i <= n; i++){
        ListNode* nextInsert = it->next;
        it->next = pre->next;
        pre->next = it;
        it = nextInsert;
    }
    for(; pre->next; pre=pre->next){}
    pre ->next = it;
    return dummy->next;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
