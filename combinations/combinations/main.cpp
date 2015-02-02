//
//  main.cpp
//  combinations
//
//  Created by JINGNING CAO on 12/21/14.
//  Copyright (c) 2014 JINGNING CAO. All rights reserved.
//
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <unordered_set>
using namespace std;

void recur(vector<int> &num, vector<int> &path, vector<vector<int>> &res, int gap, size_t step){
    if (gap == 0){
        res.push_back(path);
        return;
    }
    if (gap > num.size()-step){
        return;
    }
    for(int i = step; i < num.size(); i++){
        path.push_back(num[i]);
        recur(num, path, res, gap-1, i+1);
        path.pop_back();
    }
}

vector<vector<int> > combine(int n, int k) {
    vector<int> num(n, 0);
    for(int i = 0; i < num.size(); i++){
        num[i] = i+1;
    }
    vector<int> path;
    vector<vector<int>> res;
    recur(num, path, res, k, 0);
    return res;
}
int main(int argc, const char * argv[]) {
    vector<vector<int> > res = combine(4, 2);
    for(auto v : res){
        cout << "[";
        for(int elem : v){
            cout << elem << "-";
        }
        cout << "]" << endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
