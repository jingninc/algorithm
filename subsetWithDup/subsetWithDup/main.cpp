//
//  main.cpp
//  subsetWithDup
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

void recur(vector<int> &S, vector<vector<int> > &res, vector<int> &path, int curr){
    // leaf node
    res.push_back(path);
    // curr is the starting point of this level
    // i is the current index in this level
    for(int i = curr; i < S.size(); i++){
        if (i-1 >= curr && S[i] == S[i-1]) continue;
        path.push_back(S[i]);
        recur(S, res, path, i+1);
        path.pop_back();
    }
}

vector<vector<int> > subsetsWithDup(vector<int> &S) {
    sort(S.begin(), S.end());
    vector<vector<int> > res;
    vector<int> path;
    recur(S, res, path, 0);
    return res;
}

int main(int argc, const char * argv[]) {
    vector<int> S = {2,3,2};
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
