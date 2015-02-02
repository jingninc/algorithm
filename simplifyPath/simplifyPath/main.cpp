//
//  main.cpp
//  simplifyPath
//
//  Created by JINGNING CAO on 1/20/15.
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


string simplifyPath(string path) {
    stack<string> s;
    for(auto curr = path.begin(); curr < path.end(); ){
        auto found = find(curr, path.end(), '/');
        string tmp(curr, found);
        if (tmp.size() != 0 && tmp != ".") {
            if (tmp == ".." ) {
                if (!s.empty()) s.pop();
            }
            else s.push(tmp);
        }
        curr = found+1;
    }
    string ss;
    if (s.empty()){
        return "/";
    }
    while(!s.empty()){
        ss = '/' + s.top() + ss;
        s.pop();
    }
    return ss;
}

int main(int argc, const char * argv[]) {
    cout << simplifyPath("/a/./b/../../c/") << endl;
    cout << simplifyPath("/a/b/  /ca/../a/") << endl;
    cout << simplifyPath("") << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
