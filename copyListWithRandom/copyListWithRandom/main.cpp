//
//  main.cpp
//  copyListWithRandom
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

unordered_map<RandomListNode*, RandomListNode*> nodeMap;
RandomListNode *copyRandomList(RandomListNode *head) {
    RandomListNode* dummy = new RandomListNode(-1);
    RandomListNode* pre = dummy;
    for(RandomListNode* curr = head; curr; curr=curr->next) {
        RandomListNode* node, *target;
        if (nodeMap.count(curr) == 0){
            node = new RandomListNode(curr->label);
        } else node = nodeMap[curr];
        // point is the case when curr->random is null.
        if (curr->random == NULL) target = NULL;
        else if (nodeMap.count(curr->random) == 0){
            target = new RandomListNode(curr->random->label);
        } else target = nodeMap[curr->random];
        pre->next = node;
        node->random = target;
        pre=pre->next;
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
