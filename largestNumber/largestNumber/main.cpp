//
//  main.cpp
//  largestNumber
//
//  Created by JINGNING CAO on 1/21/15.
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

struct MyClass{
bool operator() (int m, int n){
    vector<int> nums1;
    vector<int> nums2;
    while(m > 0){
        nums1.insert(nums1.begin(), m%10);
        m = m/10;
    }
    while(n > 0){
        nums2.insert(nums2.begin(), n%10);
        n = n/10;
    }
    int j = nums1.size();
    int i = 0;
    nums1.insert(nums1.end(), nums2.begin(), nums2.end());
    for(; i < nums1.size(); i++, j++){
        if (nums1[i] == nums1[j % nums1.size()]) continue;
        else if (nums1[i] > nums1[j % nums1.size()] ) return 1;
        else return 0;
    }
    // when two numbers are equal
    return 1;
}
    
}myObject;

string largestNumber(vector<int> &num) {
    // sort the vector decreasingly
    sort(num.begin(), num.end(), myObject );
    if(num[0] == 0) return "0";
    stringstream ss;
    for(auto elem : num){
        ss << elem;
    }
    return ss.str();
}


int main(int argc, const char * argv[]) {
//    vector<int> num = {3, 30, 34, 5, 9};
    vector<int> num = {0, 0, 0, 0, 0, 0, 0, 0};
    cout << largestNumber(num) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
