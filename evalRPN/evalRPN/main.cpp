//
//  main.cpp
//  evalRPN
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

bool isOperator(string s){
    string str = "+-*/";
    return (s.size() == 1 && str.find(s) != string::npos);
}

int evalRPN(vector<string> &tokens) {
    stack<string> s;
    for(int i = 0; i < tokens.size(); i++){
        if (!isOperator(tokens[i]) ) {
            s.push(tokens[i]);
        }else {
            int num1 = stoi(s.top());
            s.pop();
            int num2 = stoi(s.top());
            s.pop();
            int val;
            if (tokens[i][0] == '+'){
                val = num2+ num1;
            } else if (tokens[i][0] == '-'){
                val = num2- num1;
            } else if (tokens[i][0] == '*'){
                val = num2* num1;
            } else {
                val = num2/ num1;
            }
            stringstream ss;
            ss << val;
            s.push(ss.str());
        }
    }
    return stoi(s.top());
}

int main(int argc, const char * argv[]) {
//    vector<string> tokens = {"2", "1", "+", "3", "*"};
//    vector<string> tokens = {"4", "13", "5", "/", "+"};
    vector<string> tokens = {"3","-4","+"};
    cout << evalRPN(tokens) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
