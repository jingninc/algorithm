//
//  main.cpp
//  triangle
//
//  Created by JINGNING CAO on 1/16/15.
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

int minimumTotal(vector<vector<int> > &triangle) {
    int rows = triangle.size();
    if (rows == 0) return 0;
    for(int i = 0; i < rows; i++){
        triangle[i].push_back(INT_MAX);
        triangle[i].insert(triangle[i].begin(), INT_MAX);
    }
    for(int i = 1; i < rows; i++){
        for(int j = 1; j < triangle[i].size()-1; j++){
            triangle[i][j] += min(triangle[i-1][j], triangle[i-1][j-1]);
        }
    }
    int minVal = INT_MAX;
    for(int i = 0; i < triangle[rows-1].size(); i++){
        minVal = min(minVal, triangle[rows-1][i]);
    }
    return minVal;
}


int main(int argc, const char * argv[]) {
    vector<vector<int> > tri = {{46},{43,61},{10,-16,3},{-26,41,36,-72},{-28,-76,-22,26,51},{56,-53,38,67,86,-45}};
    cout << minimumTotal(tri)<< endl;
    std::cout << "Hello, World!\n";
    return 0;
}
