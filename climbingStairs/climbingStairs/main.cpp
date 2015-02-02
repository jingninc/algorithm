//
//  main.cpp
//  climbingStairs
//
//  Created by JINGNING CAO on 1/9/15.
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

unordered_map<int, int> stepMap;
int climbStairs(int n) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    if (stepMap.count(n) > 0) return stepMap[n];
    int curr = climbStairs(n-1)+ climbStairs(n-2);
    stepMap[n] = curr;
    return curr;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
