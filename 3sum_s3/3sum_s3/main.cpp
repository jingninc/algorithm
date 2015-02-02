//
//  main.cpp
//  3sum_s3
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

vector<vector<int> > threeSum(vector<int> &num) {
    vector<vector<int>> res;
    if (num.empty()) return res;
    sort(num.begin(), num.end());
    for(int i = 0; i < num.size(); i++){
        if (i -1 >= 0 && num[i] == num[i-1]) continue;
        int a = num[i];
        int head = i+1;
        int tail = num.size()-1;
        while(head < tail){
            int sum = a + num[head]+num[tail];
            if (sum == 0){
                vector<int> tmp{a, num[head], num[tail]};
                res.push_back(tmp);
                // although one solution is found, keep searching another one.
                head++;
                tail--;
            } else if (sum < 0){
                head++;
            } else {
                tail--;
            }
        }
    }
    res.erase(unique(res.begin(), res.end()), res.end()) ;
    return res;
}

int main(int argc, const char * argv[]) {
    vector<int> num= {-2,0,1,1,2};
    vector<vector<int> > res = threeSum(num);
    for(auto v : res){
        cout << "[";
        for(auto e : v){
            cout << e << ",";
        }
        cout << "]"<< endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
