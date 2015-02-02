//
//  main.cpp
//  searchInsertionPosition
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
int search(T first, T last, int target){
    auto const head = first;
    while(next(first) < last){
        auto mid = first + distance(first, last)/2 ;
        if (*mid == target) return distance(head, mid);
        else if (*mid < target) first = mid;
        else last = mid;
    }
    if (target > *last) return distance(head, last)+1;
    // target <= *last
    if (target > *first) return distance(head, last);
    // target <= *first
    else return distance(head, first);
}

int searchInsert(int A[], int n, int target) {
    if (n == 0) return -1;
    return search(A, A+n-1, target);
}

int main(int argc, const char * argv[]) {
    int A[] = {1, 3, 5, 6};
    cout << searchInsert(A, 4, 2) << endl;
    cout << searchInsert(A, 4, 5) << endl;
    cout << searchInsert(A, 4, 7) << endl;
    cout << searchInsert(A, 4, 0) << endl;
    
//    int A[] = {1};
//    cout << searchInsert(A, 1, 0) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
