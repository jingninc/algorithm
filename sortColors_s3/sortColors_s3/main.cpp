//
//  main.cpp
//  sortColors_s3
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
    int count[3];
    fill(count, count+3, 0);
    for(int i = 0; i < n; i++){
        count[A[i]]++;
    }
    for(int id = 0, i = 0; i < 3; i++){
        for(int j = 0; j < count[i]; j++){
            A[id++] = i;
        }
    }
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
