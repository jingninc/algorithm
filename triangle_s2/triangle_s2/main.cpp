//
//  main.cpp
//  triangle_s2
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
    for(int i = rows-2; i >= 0; i--){
        for(int j = 0; j < triangle[i].size(); j++){
            triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
        }
    }
    return triangle[0][0];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
