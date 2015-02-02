//
//  main.cpp
//  multiplyString
//
//  Created by JINGNING CAO on 1/22/15.
//  Copyright (c) 2015 JINGNING CAO. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <queue>
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

string multiply(string num1, string num2) {
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    string res(num1.size()+num2.size(), '0');
    int carry = 0;
    for(int i = 0; i < num1.size(); i++){
        carry = 0;
        for(int j = 0; j < num2.size(); j++){
            int sum = carry + (num1[i]-'0') * (num2[j]-'0') + (res[i+j]-'0');
            res[i+j] = sum%10 + '0';
            carry = sum/10;
        }
        if (carry > 0) res[i+num2.size()] = carry+'0';
    }
    reverse(res.begin(), res.end());
    auto found = find_if(res.begin(), res.end(), bind1st(not_equal_to<char>(), '0') );
    if (found == res.end()) return "0";
    res.erase(res.begin(), found);
    return res;
}

int main(int argc, const char * argv[]) {
    string num1 = "154";
    string num2 = "9872";
    cout << multiply(num1, num2) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
