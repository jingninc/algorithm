//
//  main.cpp
//  3sum
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

vector<vector<int> > threeSum(vector<int> &num) {
    sort(num.begin(), num.end());
    unordered_map<int, vector<int>> numMap;
    vector<vector<int> > res;
    for(int i = 0; i < num.size(); i++){
        if (numMap.count(num[i]) == 0){
            numMap[num[i]] = {i};
        } else numMap[num[i]].push_back(i);
    }
    for(int i = 0; i < num.size(); i++){
        // skip the duplicate case
        if (i-1 >= 0 && num[i] == num[i-1]) continue;
        int a = num[i];
        for(int j = i+1; j < num.size(); j++){
            int b = num[j];
            if (numMap.count(0-b-a)==0 ) continue;
            for(int k : numMap[0-b-a]){
                if (k > j) {
                    res.push_back({a, b, num[k]});
                }
            }
        }
    }
    sort(res.begin(), res.end());
//    if (res.size() == 0) return res;
//    vector<vector<int> > tmp;
//    tmp.push_back(res[0]);
//    for(int i = 1, j = 0; i < res.size(); i++){
//        if (res[i] != tmp[j]){
//            tmp.push_back(res[i]);
//            j++;
//        }
//    }
//    res.erase(unique(res.begin(), res.end()), res.end());
    return res;
}


int main(int argc, const char * argv[]) {
    vector<int> num = {-1, 0, 1, 2, -1, -1, -4};
    vector<vector<int>> res = threeSum(num);
    for (vector<int> v : res){
        cout << "[";
        for (auto e : v){
            cout << e << ",";
        }
        cout << "]"<< endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
