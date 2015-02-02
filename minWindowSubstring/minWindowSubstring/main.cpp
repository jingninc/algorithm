//
//  main.cpp
//  minWindowSubstring
//
//  Created by JINGNING CAO on 1/18/15.
//  Copyright (c) 2015 JINGNING CAO. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

string minWindow(string S, string T) {
    unordered_map<char, int> countMap;
    for(char ch : T){
        if (countMap.count(ch) == 0 ) countMap[ch] = 1;
        else countMap[ch]++;
    }
    int head = -1;
    int tail = 0;
    int minLen = INT_MAX;
    int minHead = -1;;
    for(; tail < S.size(); tail++){
        if (countMap.count(S[tail]) > 0 ){
            countMap[S[tail]]--;
            auto it = countMap.begin();
            for(; it != countMap.end(); it++){
                if (it->second > 0) break;
            }
            if (it == countMap.end()){
                for(; head+1 <= tail; ){
                    if (countMap.count(S[head+1]) == 0 ){
                        head++;
                    } else if (countMap[S[head+1]] < 0){ // countMap.count(S[head+1]) != 0
                        countMap[S[head+1]]++;
                        head++;
                    } else break;
                }
                if (tail-head < minLen){
                    minLen = tail-head;
                    minHead = head+1;
                }
            }
        }
    }
    if (minHead == -1) return "";
    return S.substr(minHead, minLen);
}

int main(int argc, const char * argv[]) {
    string S = "ADOBECODEBANC";
    string T = "EN";
    cout << minWindow(S, T) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}







