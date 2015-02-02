//
//  main.cpp
//  copyListWithRandom_s2
//
//  Created by JINGNING CAO on 1/22/15.
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

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode *copyRandomList(RandomListNode *head) {
    if (!head) return head;
    // build the mapping relation
    for(RandomListNode* curr =head; curr; ){
        RandomListNode* copy = new RandomListNode(curr->label);
        copy ->next = curr->next;
        curr->next = copy;
        curr = copy->next;
    }
    // add the random pointer for each node
    for(RandomListNode* curr =head; curr; ){
        RandomListNode* copy = curr->next;
        if (curr->random != NULL){
            copy->random = curr->random->next;
        }
        curr = copy->next;
    }
    // delete the mapping pointer for each node.
    // recover the original data structure.
    RandomListNode* dummy = new RandomListNode(-1);
    RandomListNode* pre = dummy;
    for(RandomListNode* curr =head; curr; curr=curr->next){
        pre->next = curr->next;
        pre=pre->next;
        // recover the original structure.
        curr->next = pre->next;
    }
    return dummy->next;
}


int main(int argc, const char * argv[]) {
    RandomListNode* head = new RandomListNode(1);
    head->next = new RandomListNode(2);
    
    RandomListNode* res = copyRandomList(head);
    for(; res; res=res->next){
        cout << res->label << ",";
    }
    cout << endl;
    std::cout << "Hello, World!\n";
    return 0;
}


