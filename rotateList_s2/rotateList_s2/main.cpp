//
//  main.cpp
//  rotateList_s2
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

ListNode *rotateRight(ListNode *head, int k) {
    // two corner case cann't be ignored.
    if (k == 0 || !head) return head;
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode* advance = dummy;
    // if k is more than the total length of the list, k = k%(len).
    for(int i = 0; i < k;advance = (advance->next) ? advance->next : dummy->next, i++){}
    ListNode* pre = dummy;
    for(; advance->next; advance=advance->next, pre=pre->next){}
    // cut
    head = pre->next;
    pre->next = NULL;
   	for(advance = head; advance->next; advance=advance->next){}
    advance->next = dummy->next;
    return head;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
