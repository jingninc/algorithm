//
//  main.cpp
//  nQueens
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

bool isValid(vector<int> &path, int curr, int id){
    for(int i = 0; i < path.size(); i++){
        if (id == path[i]) return false;
        if (abs(curr-i) == abs(id-path[i]) ) return false;
    }
    return true;
}

void recur(vector<vector<string> > &res, vector<int> &path, int n, int curr){
    if (curr == n){
        vector<string> v;
        for(int id : path){
            string tmp(n, '.');
            tmp[id] = 'Q';
            v.push_back(tmp);
        }
        res.push_back(v);
    }
    for(int j = 0; j < n; j++){
        if (isValid(path, curr, j)){
            path.push_back(j);
            recur(res, path, n, curr+1);
            path.pop_back();
        }
    }
    
}


vector<vector<string> > solveNQueens(int n) {
    vector<vector<string> > res;
    vector<int> path;
    recur(res, path, n, 0);    
    return res;
}

int main(int argc, const char * argv[]) {
    vector<vector<string> > res = solveNQueens(5);
    for(auto v : res){
        cout << "["<<endl;
        for(auto s : v){
            cout << s << endl;
        }
        cout << "]" << endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
