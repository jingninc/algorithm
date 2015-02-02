//
//  main.cpp
//  subsetWithDup_s2
//
//  Created by JINGNING CAO on 1/8/15.
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
void recur(vector<pair<int, int>> &v, vector<int> &path, vector<vector<int> > &res, int curr){
    if (curr == v.size()){
        res.push_back(path);
        return;
    }
    int val = v[curr].first;
    int count = v[curr].second;
    for(int times = 0; times <= count; times++){
        for(int i = 0; i < times; i++){
            path.push_back(val);
        }
        recur(v, path, res, curr+1);
        for(int i = 0; i < times; i++){
            path.pop_back();
        }
    }
}


vector<vector<int> > subsetsWithDup(vector<int> &S) {
    unordered_map<int, int> countMap;
    for_each(S.begin(), S.end(), [&countMap](int e){
        if (countMap.count(e) == 0){
            countMap[e] = 1;
        } else countMap[e]++;
    });
    vector<pair<int, int>> v;
    for_each(countMap.begin(), countMap.end(), [&v](pair<int, int> elem){
        v.push_back(elem);
    });
    vector<int> path;	    
    vector<vector<int> > res;
    sort(v.begin(), v.end());
    recur(v, path, res, 0);
    return res;
}

int main(int argc, const char * argv[]) {
    vector<int> S = {2,3,2, 2};
    subsetsWithDup(S);
    for (vector<int> v : subsetsWithDup(S)){
        cout << "[" ;
        for (int elem : v){
            cout << elem << ",";
        }
        cout << "]" << endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
