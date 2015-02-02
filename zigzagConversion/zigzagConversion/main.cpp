//
//  main.cpp
//  zigzagConversion
//
//  Created by JINGNING CAO on 1/7/15.
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

string convert(string s, int nRows) {
    if (nRows <= 1) return s;
    vector<string> v(nRows);
    int unit = 2* (nRows-1);
    for(int i = 0; i < s.size(); i++){
        int id = i% unit;
        if (id <= nRows-1){
            v[id].push_back(s[i]);
        } else {
            v[unit- id].push_back(s[i]);
        }
    }
    stringstream ss;
    for(string str : v){
        ss << str;
    }
    return ss.str();
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
