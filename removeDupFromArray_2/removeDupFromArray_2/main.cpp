//
//  main.cpp
//  removeDupFromArray_2
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
int removeDuplicates(int A[], int n) {
    if (n <= 2) return n;
    int newHead = 2;
    for(int i = 2; i < n; i++){
        if (A[i] != A[newHead-2]) A[newHead++] = A[i];
    }
    return newHead;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
