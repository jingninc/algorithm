//
//  main.cpp
//  combinationSum1
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

void recur(vector<int> &candidates, int gap, size_t start, vector<int> &path, vector<vector<int> > &res){
    if (gap == 0){
        res.push_back(path);
        return;
    }
    if (start == candidates.size() || gap < 0) return;
    for(int i = start; i < candidates.size(); i++){
        path.push_back(candidates[i]);
        recur(candidates, gap-candidates[i], i, path, res);
        path.pop_back();
    }
}

vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    vector<int> path;
    vector<vector<int> > res;
    sort(candidates.begin(), candidates.end());
    recur(candidates, target, 0, path, res);
    return res;
}
int main(int argc, const char * argv[]) {
    vector<int> candidates = {8,7,4,3};
    vector<vector<int> > res =combinationSum(candidates, 11);
    for(auto v : res){
        cout << "[";
        for(auto e : v){
            cout << e << ",";
        }
        cout << "]" << endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
