//
//  main.cpp
//  setMatrixZeros
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

bool isZero(int row, int col, vector<vector<int> > &matrix){
    if (row >= 0){ // check the nth row
        for(int i = 0; i < matrix.front().size(); i++){
            if (matrix[row][i] == 0) {
                return true;
            }
        }
        return false;
    } else { // col > 0   check the nth col
        for(int i = 0; i < matrix.size(); i++){
            if (matrix[i][col] == 0) {
                return true;
            }
        }
        return false;
    }
}

void setZeroes(vector<vector<int> > &matrix) {
    if (matrix.size() == 0 || matrix.front().size() == 0) return;
    int rows = matrix.size();
    int cols = matrix.front().size();
    bool firstRow = isZero(0, -1, matrix);
    bool firstCol = isZero(-1, 0, matrix);
    
    // check the nth column
    for(int i = 1; i < cols; i++){
        if (isZero(-1, i, matrix)) matrix[0][i] = 0;
    }
    for(int i = 1; i < rows; i++){
        if (isZero(i, -1, matrix)) matrix[i][0] = 0;
    }
    for(int i = 1; i < rows; i++){
        for(int j = 1; j < cols; j++){
            if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
        }
    }
    if (firstRow) {
        for(int i = 0; i < cols; i++){
            matrix[0][i] = 0;
        }
    }
    if (firstCol) {
        for(int i = 0; i < rows; i++){
            matrix[i][0] = 0;
        }
    }

}


int main(int argc, const char * argv[]) {
    vector<vector<int> >matrix={{0,2,3},
                                {4,5,6},
                                {7,8,9}};
    setZeroes(matrix);
    for (auto v : matrix){
        cout << '[';
        for(int elem : v){
            cout << elem <<" ,";
        }
        cout << ']'<<endl;
    }
    cout << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
