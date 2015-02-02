//
//  main.cpp
//  histogram
//
//  Created by JINGNING CAO on 1/22/15.
//  Copyright (c) 2015 JINGNING CAO. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int largestRectangleArea(vector<int> &height) {
    height.push_back(-1);
    stack<int> s;
    int maxArea = 0;
    for(int i = 0; i < height.size(); ){
        // keep elements in the stack increasingly.
        if (s.empty() || height[s.top()] <= height[i]) {
            s.push(i);
            i++;
        } else{ // !s.empty()
            int rightBound = i;
            int h = height[s.top()];
            s.pop();
            int leftBound = s.empty() ? -1 : s.top();
            maxArea=max(maxArea, h*(rightBound-leftBound-1));
        }
    }
    return maxArea;
}

int main(int argc, const char * argv[]) {
//    vector<int> height = {2,1,5,6,2,3,1,1,1,1,1,1,1};
    vector<int> height = {4,2,0,3,2,5};
    cout << largestRectangleArea(height) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
