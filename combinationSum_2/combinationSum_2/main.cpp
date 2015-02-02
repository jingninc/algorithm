//
//  main.cpp
//  combinationSum_2
//
//  Created by JINGNING CAO on 1/25/15.
//  Copyright (c) 2015 JINGNING CAO. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
void recur(vector<vector<int> > &res, vector<int> &path, vector<int> &num, int gap, int start){
    if (gap == 0){
        res.push_back(path);
        return;
    }
    if (gap < 0) return;
    for(int i = start; i < num.size(); i++){
        // eliminate duplicate cases.
        if (i-1 >= start && num[i] == num[i-1]) continue;
        path.push_back(num[i]);
        recur(res, path, num, gap-num[i], i+1);
        path.pop_back();
    }
}


vector<vector<int> > combinationSum2(vector<int> &num, int target) {
    vector<vector<int> > res;
    vector<int> path;
    sort(num.begin(), num.end());
    recur(res, path, num, target, 0);
    return res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
