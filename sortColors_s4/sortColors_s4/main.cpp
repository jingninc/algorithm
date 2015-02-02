//
//  main.cpp
//  sortColors_s4
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

template<typename T, typename UnaryPredicate>
T part(T first, T last, UnaryPredicate pred){
    auto pivot = first;
    for(; first != last; first++){
        if (pred(*first)){
            swap(*pivot++, *first);
        }
    }
    return pivot;
}

void sortColors(int A[], int n) {
    auto mid = part(A, A+n, bind1st(equal_to<int>(), 0) );
    part(mid, A+n, bind1st(equal_to<int>(), 1) );
}

int main(int argc, const char * argv[]) {
    int A[] = {2, 1, 0, 0, 1, 0};
//    int A[] = {2, 1};
    sortColors(A, 6);
    for(int i = 0; i < 6; i++){
        cout << A[i] << endl;
    }

    std::cout << "Hello, World!\n";
    return 0;
}
