//
//  main.cpp
//  spiralMatrix
//
//  Created by JINGNING CAO on 1/17/15.
//  Copyright (c) 2015 JINGNING CAO. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

vector<int> spiralOrder(vector<vector<int> > &matrix) {
    vector<int> res;
    if (matrix.size() == 0 || matrix.front().size() == 0) return res;
    int rows = matrix.size();
    int cols = matrix.front().size();
    int begin = 0;
    int end = 0;
    int level = 0;
    while(true){
        if (begin >= cols - end) break;
        for(int col = begin; col < cols-end; col++){
            res.push_back(matrix[level][col]);
        }
        begin++;
        if (begin >= rows - end) break;
        for(int row = begin; row < rows-end; row++){
            res.push_back(matrix[row][cols-1-level]);
        }
        if (cols -1-begin < end) break;
        for(int col = cols-1-begin; col >= end; col--){
            res.push_back(matrix[rows-1-level][col]);
        }
        end++;
        if (rows - 1- begin < end) break;
        for(int row = rows-1-begin; row >= end; row--){
            res.push_back(matrix[row][level]);
        }
        level++;
    }	
    return res;   
}


int main(int argc, const char * argv[]) {
    vector<vector<int>> matrix = {
            { 1, 2, 3 },
            { 4, 5, 6 },
            { 7, 8, 9 }
    };
    vector<int> res = spiralOrder(matrix);
    for(auto e : res){
        cout << e << ",";
    }
    cout << endl;
    std::cout << "Hello, World!\n";
    return 0;
}







