//
//  main.cpp
//  firstMissingPositive
//
//  Created by JINGNING CAO on 1/16/15.
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

int firstMissingPositive(int A[], int n) {
    if (n == 0) return 0;
    for(int i = 0; i < n; ){
        if (i+1 != A[i] && A[i]-1 >= 0 && A[i]-1 < n && A[A[i]-1] != A[i]){
            swap(A[i], A[A[i]-1]);
        }else { // i == A[i]
            i++;
        }
    }
    for(int i = 0; i < n; i++){
        if (i+1 != A[i]) return i+1;
    }
    return n+1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
