//
//  main.cpp
//  subset_S2
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
void recur(vector<vector<int> > &res, vector<int> &path, vector<int> &S, int curr){
    res.push_back(path);
    for(int i = curr; i < S.size(); i++){
        path.push_back(S[i]);
        recur(res, path, S, i+1);
        path.pop_back();
    }
}


vector<vector<int> > subsets(vector<int> &S) {
    sort(S.begin(), S.end());
    vector<vector<int> > res;
    vector<int> path;
    recur(res, path, S, 0);
    return res;
}


int main(int argc, const char * argv[]) {
    vector<int> S = {1,2,3};
    for (vector<int> v : subsets(S)){
        cout << "[" ;
        for (int elem : v){
            cout << elem << ",";
        }
        cout << "]" << endl;
    }

    std::cout << "Hello, World!\n";
    return 0;
}
