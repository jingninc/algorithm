//
//  main.cpp
//  3SumClosest_s2
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

int threeSumClosest(vector<int> &num, int target) {
    if (num.size() == 0) return -1;
    sort(num.begin(), num.end());
    int smallest = INT_MAX;
    int closest;
    for(auto a = num.begin(); a != num.end(); a++){
        if (a != num.begin() && *a == *prev(a)) continue;
        auto b = next(a);
        auto c = prev(num.end());
        while(b < c){
            int sum = *a + *b + *c;
            if (sum == target) return target;
            else if (sum < target){
                b++;
            } else{
                c--;
            }
            if (abs(sum-target) < smallest){
                smallest = abs(sum-target);
                closest = sum;
            }
        }
    }
    return closest;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
