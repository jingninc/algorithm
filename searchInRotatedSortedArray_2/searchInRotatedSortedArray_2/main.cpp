//
//  main.cpp
//  searchInRotatedSortedArray_2
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

template<typename T>
bool binarySearch(T first, T last, int target){
    auto const head = first;
    while(next(first) < last){
        auto mid = first+ distance(first, last)/ 2;
        if (*mid == target) return true;
        // *mid != target
        if (*mid == *first) {// infer that first != target, drop it
            first++;
        } else if (*mid > *first){
            if (target >= *first && target < *mid){
                last = mid;
            } else {
                first = mid;
            }
        } else {// *mid < *first
            if (target > *mid && target <= *last){
                first = mid;
            } else {
                last = mid;
            }
        }
    }
    return (*first == target) || (*last == target);
}

bool search(int A[], int n, int target) {
    if (n == 0) return false;
    return binarySearch(A, A+n-1, target);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
