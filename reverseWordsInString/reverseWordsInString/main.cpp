//
//  main.cpp
//  reverseWordsInString
//
//  Created by JINGNING CAO on 1/3/15.
//  Copyright (c) 2015 JINGNING CAO. All rights reserved.
//
#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

void reverseWords(string &s) {
    if (s.size() == 0) return;
    char const emp = ' ';
    auto head = find_if(s.begin(), s.end(), bind1st(not_equal_to<char>(), emp) );
    if (head == s.end()) {
        s = "";
        return;
    }
    auto tail = find_if(s.rbegin(), s.rend(), bind1st(not_equal_to<char>(), emp) );
    string ss(head, tail);
    s = ss;
//    for(auto it = head, newHead = it; it != tail; ){
//        if (*it != ' ') ss.push_back(*it);
//        else {
//            ss.reverse(newHead, it);
//        }
//    }
    
}

int main(int argc, const char * argv[]) {
    string s = "   the sky is blue   ";
    reverseWords(s);
    cout << s << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
