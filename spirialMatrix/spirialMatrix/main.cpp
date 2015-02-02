//
//  main.cpp
//  spirialMatrix
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


vector<int> spiralOrder(vector<vector<int> > &matrix) {
    vector<int> res;
    if (matrix.size() == 0 || matrix.front().size() == 0) return res;
    int rows = matrix.size();
    int cols = matrix.front().size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    int row = 0;
    int col = 0;
    while(true){
        if (visited[row][col]) break;
        for(; col < cols && !visited[row][col]; col++){
            visited[row][col] = true;
            res.push_back(matrix[row][col]);
        }
        col--;
        row++;
        if (visited[row][col]) break;
        for(; row < rows && !visited[row][col]; row++){
            visited[row][col] = true;
            res.push_back(matrix[row][col]);
        }
        col--;
        row--;
        if (visited[row][col]) break;
        for(; col >= 0 && !visited[row][col]; col--){
            visited[row][col] = true;
            res.push_back(matrix[row][col]);
        }
        row--;
        col++;
        if (visited[row][col]) break;
        for(; row >= 0 && !visited[row][col]; row--){
            visited[row][col] = true;
            res.push_back(matrix[row][col]);
        }
        col++;
        row++;
    }
    return res;
}

int main(int argc, const char * argv[]) {
//    vector<vector<int> > matrix = {
//        {1, 2, 3, 4, 5, 6, 7},
//        {8, 9, 10, 11, 12, 13, 14},
//        {15, 16, 17, 18, 19, 20, 21},
//        {22, 23, 24, 25, 26, 27, 28},
//        {29, 30, 31, 32, 33, 34, 35},
//        {36, 37, 38, 39, 40, 41, 42},
//        {43, 44, 45, 46, 47, 48, 49},
//    };
    vector<vector<int> > matrix = {
        {1, 2},
        {3, 4}
    };
    vector<int> res = spiralOrder(matrix);
        cout << "[";
        for (auto elem : res){
            cout << elem<< ",";
        }
        cout << "]" << endl;

    std::cout << "Hello, World!\n";
    return 0;
}
