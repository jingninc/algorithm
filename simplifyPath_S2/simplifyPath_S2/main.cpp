//
//  main.cpp
//  simplifyPath_S2
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

string simplifyPath(string path) {
    vector<string> v;
    // use a bi-direction linked list to implement.
    for(auto curr = path.begin(); curr != path.end(); ){
        // skip the first letter which is '/'
        curr++;
        auto found = find(curr, path.end(), '/');
        string tmp(curr, found);
        // if tmp == '.’, do nothing.
        if (tmp.size() > 0 && tmp != "."){
            if (tmp == ".."){
                if (!v.empty()) v.pop_back();
            }
            else { // tmp == any possible string
                v.push_back(tmp);
            }
        }
        curr = found;
    }
    if (v.empty()) return "/";
    stringstream ss;
    for(auto elem : v){
        ss << '/' << elem;
    }	
    return ss.str();
}


int main(int argc, const char * argv[]) {
    cout << simplifyPath("/a/./b/../../c/") << endl;
    cout << simplifyPath("/a/b/  /ca/../a/") << endl;
    cout << simplifyPath("") << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
