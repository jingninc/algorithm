//
//  main.cpp
//  palindromicNumber
//
//  Created by JINGNING CAO on 1/12/15.
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

bool isPalindrome(int x) {
    // reverse the number will overflow.
    if (x < 0) return false;
    int k = x;
    // to get the most significant digit
    int divisor1 = 1;
    // to get the last digit
    int divisor2 = 10;
    // k /10 > 0 means there is one more digit for this number.
    // don't multiply divisor with 10 until it is greater than k is to prevent overflow 
    while(k /10 > 0){
        k = k/ 10;
        divisor1 *= 10;
    }
    for(; x>0; divisor1 /= 10, divisor1 /= 10){
        int front = x/ divisor1;
        int back = x % divisor2;
        if (front != back) return false;
        x = x % divisor1;
        x /= 10;
    }
    return true;
}


int main(int argc, const char * argv[]) {
    cout << isPalindrome(98789) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
