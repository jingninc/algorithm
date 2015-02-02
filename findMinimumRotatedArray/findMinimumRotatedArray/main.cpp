//
//  main.cpp
//  findMinimumRotatedArray
//
//  Created by JINGNING CAO on 1/15/15.
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

int search(vector<int> &num, int first, int last){
    // there is at least one element between two pointers.
    while(first + 1 < last){
        int mid = first + (last- first) /2;
        if (num[mid] > num[first] && num[mid] < num[last]){
            return num[first];
        }else{ // it is not a sorted array.
            if (num[mid] > num[first]){
                first = mid;
            } else { // num[mid] < num[last]
                last = mid;
            }
        }
    }
    return min(num[first], num[last]);
}


int findMin(vector<int> &num) {
    if (num.size() == 0) return 0;	      
    return search(num, 0, num.size()-1);    
}

int main(int argc, const char * argv[]) {
    vector<int> num = {4, 5, 6, 7, 9, 10, 11, -9};
    cout << findMin(num) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}




