//
//  main.cpp
//  longestSubstring
//
//  Created by JINGNING CAO on 1/26/15.
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

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> countMap;
    int head = 0;
    int tail = 0;
    int longest = 0;
    for(; tail < s.size(); tail++){
        countMap[s[tail]]++;
        if (countMap[s[tail]] > 1){
            // ensure all element in the window appearing just once.
            for(; head < tail && countMap[s[head]] == 1;head++){
                countMap[s[head]]--;
            }
            countMap[s[head++]]--;
        }
        longest = max(longest, tail-head+1);
    }
    return longest;
}

int main(int argc, const char * argv[]) {
    cout << lengthOfLongestSubstring("abbaccdfeebacc") << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
