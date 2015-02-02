//
//  main.cpp
//  mergeTwoSortedList
//
//  Created by JINGNING CAO on 1/6/15.
//  Copyright (c) 2015 JINGNING CAO. All rights reserved.
//


#include <iostream>
#include <vector>
#include <stack>
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

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode* dummy = new ListNode(-1);
    ListNode* pre = dummy;
    for(; l1 != NULL || l2 != NULL; pre= pre->next ){
        int val1 = (l1 == NULL) ? INT_MAX : l1->val;
        int val2 = (l2 == NULL) ? INT_MAX : l2->val;
        if (val1 < val2) {
            pre->next = l1;
            l1 = l1->next;
        }
        else { //val1 >= val2
            pre ->next = l2;
            l2 =l2->next;
        }
    }     
    return dummy->next;
}

int main(int argc, const char * argv[]) {
//    ListNode* m = new ListNode(1);
//    m->next = new ListNode(2);
//    m ->next ->next = new ListNode(4);
//    m ->next ->next ->next = new ListNode(7);
    
    ListNode* m;
    
    ListNode* n = new ListNode(-8);
    n ->next = new ListNode(0);
    n ->next ->next= new ListNode(3);
    n ->next ->next ->next= new ListNode(6);

    ListNode* sorted = mergeTwoLists(m, n);
    for(; sorted; sorted = sorted->next){
        cout << sorted->val << ",";
    }
    std::cout << "Hello, World!\n";
    return 0;
}
