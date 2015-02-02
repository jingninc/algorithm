//
//  main.cpp
//  search2DMatrix
//
//  Created by JINGNING CAO on 1/3/15.
//  Copyright (c) 2015 JINGNING CAO. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

bool searchMatrix(int first, int last, vector<vector<int> > &matrix, int target){
    int const rows = matrix.size();
    int const cols = matrix.front().size();

    while(first +1 < last){
        int mid = first + (last-first)/2;
        int midVal = matrix[mid/cols][mid%cols];
        if (midVal == target) return true;
        if (midVal > target){
            last = mid;
        } else {
            first = mid;
        }
    }
    return (matrix[first/cols][first%cols] == target) || (matrix[last/cols][last%cols] == target);
}

bool searchMatrix(vector<vector<int> > &matrix, int target) {
    if (matrix.size() == 0 || matrix.front().size() == 0) return false;
    return searchMatrix(0, matrix.size() * matrix.front().size()- 1, matrix, target);
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> matrix = {{1, 1}};
    cout << searchMatrix(matrix, 0) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
