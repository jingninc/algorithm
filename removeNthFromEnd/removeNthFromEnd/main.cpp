//
//  main.cpp
//  removeNthFromEnd
//
//  Created by JINGNING CAO on 1/15/15.
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
ListNode *removeNthFromEnd(ListNode *head, int n) {
    if (!head || n == 0) return head;
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode* advance = dummy;
    for(int i = 0; i < n+1; advance= advance->next, i++){}
    ListNode* pre = dummy;
    for(; advance; pre=pre->next, advance=advance->next){}
    pre->next = pre->next->next;
    return dummy->next;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
