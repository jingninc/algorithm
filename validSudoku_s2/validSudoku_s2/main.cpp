//
//  main.cpp
//  validSudoku_s2
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


bool valid(vector<vector<char> > &board, int i, int j){
    if (board[i][j] == '.') return true;
    int rows = board.size();
    int cols = board.front().size();
    for(int row = 0; row < rows; row++){
        if (row != i && board[row][j] == board[i][j]) return false;
    }
    for(int col = 0; col < cols; col++){
        if (col != j && board[i][col] == board[i][j]) return false;
    }
    int m = (i/3)* 3;
    int n = (j/3)* 3;
    for(int row = m; row < m+3; row++){
        for(int col = n; col < n+3; col++){
            if (row != i && col != j && board[row][col] == board[i][j])
                return  false;
        }
    }
    return true;
}

bool isValidSudoku(vector<vector<char> > &board) {
    if (board.size() == 0 || board.front().size() == 0) return false;
    for(int row = 0; row < board.size(); row++){
        for (int col = 0; col < board.front().size(); col++){
            if (!valid(board, row, col) ) return false;
        }
    }
    return true;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
