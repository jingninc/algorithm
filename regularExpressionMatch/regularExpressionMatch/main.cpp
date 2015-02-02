//
//  main.cpp
//  regularExpressionMatch
//
//  Created by JINGNING CAO on 1/16/15.
//  Copyright (c) 2015 JINGNING CAO. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

bool isSame(const char* s, const char* p){
    if (*s == '\0') return false;
    if (*p == '.') return true;
    return (*p == *s);
}

bool isMatch(const char *s, const char *p) {
    if (*p == '\0') return (*s == '\0');
 //   cout << *p << " | " << *s << endl;
    if (*(p+1) != '*'){
        // p still has letter to match, s should not has no letter remaining.
        return isSame(s, p) && isMatch(s+1, p+1);
    } else{ // *(p+1) == ‘*’
        // s can has no letter to match as long as p match no letter.
        if (isMatch(s, p+2)) return true;
        for(auto curr = s; *curr != '\0' && isSame(curr, p); curr++){
            if (isMatch(curr+1, p+2)) return true;
        }
        // when curr != *p or curr == ‘\0’ quit the loop
        return false;
    }
}


int main(int argc, const char * argv[]) {
 //   cout << isMatch("aab", "c*a*b") << endl;
 //   cout << isMatch("aa", ".*") << endl;
    cout << isMatch("aaba", "ab*a*c*a") << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
