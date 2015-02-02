//
//  main.cpp
//  longestCommonPrefix_s2
//
//  Created by JINGNING CAO on 1/10/15.
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

string longestCommonPrefix(vector<string> &strs){
    if (strs.size() == 0) return "";
    string s = strs[0];
    int rightMost = s.size();
    for(int i = 1; i < strs.size(); i++){
        for(int pos = 0; pos < rightMost; pos++){
            if (strs[i][pos] != s[pos]) rightMost = pos;
        }
    }
    return s.substr(0, rightMost);
}


int main(int argc, const char * argv[]) {
    vector<string> strs = { "bac", "bac", "bc"};
    cout << longestCommonPrefix(strs) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
