//
//  main.cpp
//  restoreIpAddress
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

bool isValid(string s){
    int sum = 0;
    for(char ch : s){
        int digit = ch - '0';
        sum = sum* 10 + digit;
    }
    if ((s[0] == '0' && s.size() > 1) || sum > 255 ) return false;
    return true;
}

void recur(string s, int curr, vector<string> &path, vector<string> &res){
    if (path.size() == 4 && curr == s.size()){
        stringstream ss;
        for(auto e : path){
            ss << e << '.';
        }
        string ip = ss.str();
        ip.pop_back();
        res.push_back(ip);
        return;
    }
    if (s.size()-curr > (4- path.size())*3 ) return;
    if (s.size()-curr < (4- path.size())*1 ) return;
    for(int stop = curr; stop < s.size(); stop++){
        string temp;
        for(int i = curr; i <= stop; i++){
            temp.push_back(s[i]);
        }
        if (!isValid(temp) ) continue;
        path.push_back(temp);
        recur(s, stop+1, path, res);
        path.pop_back();
    }
}


vector<string> restoreIpAddresses(string s) {
    vector<string> path;
    vector<string> res;
   	recur(s, 0, path, res);
    return res;
}


int main(int argc, const char * argv[]) {
    string s = "25525511135";
    
    std::cout << "Hello, World!\n";
    return 0;
}
