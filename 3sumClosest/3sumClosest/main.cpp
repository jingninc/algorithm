//
//  main.cpp
//  3sumClosest
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
    for(int i = 0; i < num.size(); i++){
        if (i-1 >= 0 && num[i] == num[i-1]) continue;
        int a = num[i];
        int head = i+1;
        int tail = num.size()-1;
        while(head < tail){
            int sum = num[head]+num[tail]+a;
            if (sum == target) return target;
            else if (sum < target){
                head++;
            } else{
                tail--;
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
