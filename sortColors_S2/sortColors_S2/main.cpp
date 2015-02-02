//
//  main.cpp
//  sortColors_S2
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

void sortColors(int A[], int n) {
    int head = 0;
    for(int i = head; i < n; i++){
        if (A[i] == 0){
            if (head != i){
                swap(A[i], A[head]);
            }
            head++;
        }
    }
    for(int i = ++head; i < n; i++){
        if (A[i] == 1){
            if (i != head){
                swap(A[i], A[head]);
            }
            head++;
        }
    }
}


int main(int argc, const char * argv[]) {
    //int A[] = {2, 1, 0, 0, 1, 0};
    int A[] = {2, 1};
    sortColors(A, 2);
    for(int i = 0; i < 2; i++){
        cout << A[i] << endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
