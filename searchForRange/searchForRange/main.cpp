//
//  main.cpp
//  searchForRange
//
//  Created by JINGNING CAO on 12/21/14.
//  Copyright (c) 2014 JINGNING CAO. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <unordered_set>
using namespace std;

template <typename T>
T lowerBound(T first, T last, int target){
    while(first != last){
        auto mid = first + distance(first, last)/2;
        if (target > *mid){ // T > mid
            first = mid+1;
        }
        else { // T <= mid ; target <= *mid
            last = mid;
        }
    }
    return first;
}

template <typename T>
T upperBound(T first, T last, int target){
    while(first != last){
        auto mid = first +distance(first, last)/2;
        if (target >= *mid){ // T > mid ; T >= mid
            first = mid + 1;
        }else { // T < mid ; T < mid
            last = mid;
        }
    }
    return first;
}

vector<int> searchRange(int A[], int n, int target) {
    auto lower = lowerBound(A, A+n, target);
    auto upper = upperBound(lower, A+n, target);
    vector<int> v(2, -1);
    if (lower == A+n || ( *lower != target && *(upper-1) != target) )return v;
    else {
        v[0] = distance(A, lower);
        v[1] = distance(A, upper-1);
        return v;
    }
}
int main(int argc, const char * argv[]) {
    int A[] = {1, 2, 2, 2, 2, 2, 3, 3, 4, 4, 4, 8};
    vector<int> res = searchRange(A, 12, 4);
    cout << res[0] << " | " << res[1] << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
