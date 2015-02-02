//
//  main.cpp
//  longestCommonPrefix
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

string common(string str1, string str2){
    if (str1.size() == 0 || str2.size() == 0) return "";
    int i = 0;
    while(i < min(str1.size(), str2.size() )){
        if (str1[i] != str2[i]) break;
        i++;
    }
    return str1.substr(0, i);
}


string longestCommonPrefix(vector<string> &strs){
    if (strs.size() == 0) return "";
    string s = strs[0];
    for(int i = 1; i < strs.size(); i++){
        s = common(s, strs[i]);
    }
    return s;
}


int main(int argc, const char * argv[]) {
    vector<string> strs = {"", "bac", "bac", "bc"};
    cout << longestCommonPrefix(strs) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
