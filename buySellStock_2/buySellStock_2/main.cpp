//
//  main.cpp
//  buySellStock_2
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

int maxProfit(vector<int> &prices) {
    if (prices.size() < 2) return 0;
    vector<int> balance = prices;
    for(int i = 1; i < balance.size(); i++){
        balance[i] -= prices[i-1];
    }
    int prof = 0;
    // maximum sum for at most n subsequences.
    // in problem one, it is the maximum sum for at most 1 subsequence.
    for(int i = 1; i < balance.size(); i++){
        if (balance[i] > 0) prof += balance[i];
    }
    return prof;
}


int main(int argc, const char * argv[]) {
 //   vector<int> prices = {3, 2, 5, 7, 2, 0, 3};
    vector<int> prices = {3, 0};
    cout << maxProfit(prices) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
