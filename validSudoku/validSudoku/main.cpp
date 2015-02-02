//
//  main.cpp
//  validSudoku
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

bool isValidSudoku(vector<vector<char> > &board) {
    if (board.size() == 0 || board.front().size() == 0) return false;
    bool used[9];
    fill(used, used+9, false);
    int rows = board.size();
    int cols = board.front().size();
    for(int row = 0; row < rows; row++){
        fill(used, used+9, false);
        for(int i = 0; i < cols; i++){
            if (board[row][i] == '.') continue;
            if (used[board[row][i]-'1'] == false){
                used[board[row][i]-'1'] = true;
            } else return false;
        }
    }
    for(int col = 0; col < cols; col++){
        fill(used, used+9, false);
        for(int i = 0; i < rows; i++){
            if (board[i][col] == '.') continue;
            if (used[board[i][col]-'1'] == false){
                used[board[i][col]-'1'] = true;
            } else return false;
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            fill(used, used+9, false);
            // it should be remembered here ===> row < 3*i+3
            for(int row = i*3; row < 3*i+3; row++){
                for(int col = j *3; col < 3*j+3; col++){
                    if (board[row][col] == '.') continue;
                    if (used[board[row][col]-'1'] == false) {
                        used[board[row][col]-'1']= true;
                    } else return false;
                }
            }
        }
    }
    return true;
    
}

int main(int argc, const char * argv[]) {

    std::cout << "Hello, World!\n";
    return 0;
}
