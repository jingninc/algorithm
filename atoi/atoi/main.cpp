//
//  main.cpp
//  atoi
//
//  Created by JINGNING CAO on 1/29/15.
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

int atoi(const char *str) {
    if (str == NULL) return 0;
    while(*str == ' ' ){
        str++;
    }
    bool neg = false;
    if (*str == '+'){
        neg = false;
        str++;
    } else if (*str == '-'){
        neg = true;
        str++;
    }
    int num = 0;
    for(; *str != '\0'; str++){
        if (*str - '0' >= 0 && *str - '0' <= 9){
            int digit = *str - '0';
            // overflow
            if (num > INT_MAX/10 || (num == INT_MAX/10 && digit > INT_MAX % 10 )) {
                return neg ? INT_MIN : INT_MAX;
            }
            num = 10 * num + digit;
        } else{
            break;
        }
    }
    return neg ? (0-num) : num;
}



int main(int argc, const char * argv[]) {
    cout << atoi("   +-658 ") << endl;
    cout << atoi("2147483647") << endl;
    cout << atoi("2147483648") << endl;
    cout << atoi("2147483657") << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
