//
//  main.cpp
//  twoSum
//
//  Created by JINGNING CAO on 1/10/15.
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

vector<int> twoSum(vector<int> &numbers, int target) {
    unordered_map<int, vector<int>> numMap;
    for(int i = 0; i < numbers.size(); i++){
        if (numMap.count(numbers[i]) == 0 ) numMap[numbers[i]] = {i+1};
        else numMap[numbers[i]].push_back(i+1);
    }
    for(int i = 0; i < numbers.size(); i++){
        if (numMap.count(target-numbers[i]) == 0) continue;
        int a = i+1;
        for(int b : numMap[target-numbers[i]]){
            if (a < b) return {a, b};
        }
    }
    return {-1, -1};
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
