//
//  main.cpp
//  strStr
//
//  Created by JINGNING CAO on 1/15/15.
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

int strStr(char *haystack, char *needle) {
    if (strlen(haystack) < strlen(needle) ) return -1;
    int len = strlen(needle);
    if (len == 0) return 0;
    char* tail = haystack;
    for(int i = 0; i < len-1; tail++, i++){}
    // the terminating condition is equivalent to < *tail != '\0' >
    for(char* head = haystack; *tail; head++, tail++){
        char* p = needle;
        char* q = head;
        for(int i = 0; i < len; p++, q++, i++){
            if (*p != *q) break;
        }
        if (!(*p)) return distance(haystack, head);
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    char* h = "abcbcabcabcac";
    char* n = "abca";
    cout << strStr(h, n) <<  endl;
    std::cout << "Hello, World!\n";
    return 0;
}
