//
//  main.cpp
//  anagram
//
//  Created by JINGNING CAO on 1/18/15.
//  Copyright (c) 2015 JINGNING CAO. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

vector<string> anagrams(vector<string> &strs) {
    unordered_map<string, int> countMap;
    for(int i = 0; i < strs.size(); i++){
        string tmp = strs[i];
        sort(tmp.begin(), tmp.end());
        countMap[tmp]++;
    }
    vector<string> res;
    for(int i = 0; i < strs.size(); i++){
        string tmp = strs[i];
        sort(tmp.begin(), tmp.end());
        if (countMap[tmp] > 1){
            res.push_back(strs[i]);
        }
        
    }
    return res;
}

int main(int argc, const char * argv[]) {
    vector<string> strs = {"", ""};
    vector<string> res = anagrams(strs);
    for(auto e : res){
        cout << e << ",";
    }
    std::cout << "Hello, World!\n";
    return 0;
}
