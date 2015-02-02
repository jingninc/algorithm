//
//  main.cpp
//  nextPermutation
//
//  Created by JINGNING CAO on 1/20/15.
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

template<typename T>
void nextPermute(T first, T last){
    if (distance(first, last) <= 1) return;
    auto it = last;
    it--;
    for(;;){
        auto pre = prev(it);
        if (*pre >= *it){
            it--;
        } else{
            auto found = last-1;
            // proceed when the iterating element is less than or equal to the pre element.
            for(; *found <= *pre; found--){}
            iter_swap(pre, found);
            reverse(it, last);
            return;
        }
        if (it == first){
            reverse(it, last);
            return;
        }
    }
}

void nextPermutation(vector<int> &num) {
    nextPermute(num.begin(), num.end());
}	


int main(int argc, const char * argv[]) {
    vector<int> num = {5, 1, 4, 2};
    nextPermutation(num);
    for(auto e : num){
        cout << e << ",";
    }
    std::cout << "Hello, World!\n";
    return 0;
}
