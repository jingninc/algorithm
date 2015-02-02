//
//  main.cpp
//  sortColors
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
    if (n <= 0) return;
    int head = 0;
    int tail = n-1;
    for(int i = 0; i <= tail; ){
        if (A[i] == 0 && i != head) {
            swap(A[i], A[head]);
            head++;
        }
        else if (A[i] == 2 && i != tail) {
            swap(A[i], A[tail]);
            tail--;
        }
        else { // A[i] == 1
            i++;
        }
    }
    
}

int main(int argc, const char * argv[]) {
//    int A[] = {2, 1, 0, 0, 1, 0};
    int A[] = {1, 0};
    sortColors(A, 2);
    for(int i = 0; i < 2; i++){
        cout << A[i] << endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
