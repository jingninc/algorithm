//
//  main.cpp
//  searchInRotatedArray
//
//  Created by JINGNING CAO on 1/3/15.
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

template<typename T>
int rotateSearch(T first, T last, int target){
    auto const head = first;
    while(next(first) < last){
        auto mid = first + distance(first, last)/ 2;
        if (*mid == target) return distance(head, mid);
        // stay at the front part.
        if (*mid > *first){
            if (target >= *first && target < *mid){
                last = mid;
            } else {
                first = mid;
            }
        }
        else { // at the back  mid < first
            if (target > *mid && target <= *last){
                first = mid;
            } else {
                last = mid;
            }
        }
    }
    if (*first == target) return distance(head, first);
    if (*last == target) return distance(head, last);
    return -1;
}

int search(int A[], int n, int target) {
    if (n == 0) return -1;
    return rotateSearch(A, A+n-1, target);
}

int main(int argc, const char * argv[]) {
    int A[] = {4,5,6,7,8,1,2,3};
    cout << search(A, 8, 8) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
