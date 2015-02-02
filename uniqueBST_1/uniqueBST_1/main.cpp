//
//  main.cpp
//  uniqueBST_1
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
unordered_map<int, int>tree;
int numTrees(int n) {
    if (n == 0) return 1;
    if (tree.count(n) > 0) return tree[n];
    int sum = 0;
   	for(int i = 0; i <= n-1; i++){
        sum += numTrees(i) * numTrees(n-1-i);
    }
    tree[n] = sum;
    return sum;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
