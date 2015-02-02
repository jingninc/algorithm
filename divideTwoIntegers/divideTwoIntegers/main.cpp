//
//  main.cpp
//  divideTwoIntegers
//
//  Created by JINGNING CAO on 1/13/15.
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


int divide(int dividend, int divisor) {
    bool neg = (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0);
    unsigned int m = (dividend < 0) ? (0- dividend) : dividend;
    unsigned int n = (divisor < 0) ? (0- divisor) : divisor;
    unsigned int sum = 0;
    for(; m >= n; ){
        int multi = 1;
        unsigned int sub = n;
        for(; m >= sub; multi += multi, sub += sub){
            m -= sub;
            sum += multi;
            if (sub > INT_MAX/2 || multi > INT_MAX/2){
                break;
            }
        }
    }
    // sum is unsigned int type that can exceed the limit of int_max
    // if final result is positive, it can not exceed the limit of INT_MAX
    if (sum > INT_MAX && !neg) return INT_MAX;
    return (neg) ? (0- sum) : sum;    
}

int main(int argc, const char * argv[]) {
    cout << divide(88, 7) << endl;
    cout << divide(-75, 6) << endl;
    cout << divide(-7, 19) << endl;
    cout << divide(INT_MIN,-1) << endl;
    cout << divide(INT_MAX,1) << endl;
    cout << divide(INT_MAX, -1) << endl;
    cout << divide(INT_MIN,1) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
