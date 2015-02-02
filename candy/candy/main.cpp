//
//  main.cpp
//  candy
//
//  Created by JINGNING CAO on 1/23/15.
//  Copyright (c) 2015 JINGNING CAO. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
using namespace std;

int candy(vector<int> &ratings) {
    if (ratings.empty()) return 0;
    if (ratings.size() == 1) return 1;
    vector<int> sweet(ratings.size(), 1);
    for(int i = 1; i < ratings.size(); i++){
        // the second condition is necessary here, only two conditions are satisfied, then the element is updated.
        if (ratings[i] > ratings[i-1] && sweet[i] <= sweet[i-1]){
            sweet[i] = sweet[i-1] + 1;
        }
    }
    for(int i = ratings.size()-2; i >= 0; i--){
        if (ratings[i] > ratings[i+1] && sweet[i] <= sweet[i+1]){
            sweet[i] = sweet[i+1] + 1;
        }
    }
    int sum = 0;
    return accumulate(sweet.begin(), sweet.end(), sum);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
