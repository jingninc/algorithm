//
//  main.cpp
//  generateParanthesis
//
//  Created by JINGNING CAO on 1/23/15.
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

//void generate(vector<char> &symbols, string &path, vector<string> &res, int left, int right, int limits){
//    if (left == limits && right == limits){
//        res.push_back(path);
//        return;
//    }
//    if (right > left || left > limits || right > limits) return;
//    for(int i = 0; i < symbols.size(); i++){
//        path.push_back(symbols[i]);
//        if (i == 0) {
//            generate(symbols, path, res, left+1, right, limits);
//        } else generate(symbols, path, res, left, right+1, limits);
//        path.pop_back();
//    }
//}
//
//vector<string> generateParenthesis(int n) {
//    vector<char> symbols = {'(', ')'};
//    string path;
//    vector<string> res;
//    generate(symbols, path, res, 0, 0, n);
//    return res;
//}

void generate(string path, vector<string> &res, int left, int right, int limits){
    // returning condition: once the left reaches the limits
    // the remaining action is just to add right operand
    if (left == limits){
        path.insert(path.end(), limits-right, ')');
        res.push_back(path);
        return;
    }
    if (right > left) return;
    path.push_back('(');
    generate(path, res, left+1, right, limits);
    path.pop_back();
    
    path.push_back(')');
    generate(path, res, left, right+1, limits);
    path.pop_back();
}

vector<string> generateParenthesis(int n) {
    string path;
    vector<string> res;
    generate(path, res, 0, 0, n);
    return res;
}
int main(int argc, const char * argv[]) {
    vector<string> res = generateParenthesis(3);
    for(auto e : res){
        cout << e << endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
