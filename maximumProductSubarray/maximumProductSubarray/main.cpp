//
//  main.cpp
//  maximumProductSubarray
//
//  Created by JINGNING CAO on 12/30/14.
//  Copyright (c) 2014 JINGNING CAO. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

struct num{
    int max;
    int min;
};

int maxProduct(int A[], int n) {
    if (n == 0) return 0;
    num S;
    S.max = 1;
    S.min = 1;
    int maxProd = INT_MIN;
    for(int i = 0; i < n; i++){
        int maxVal = max(max(S.max * A[i], S.min * A[i]), A[i]);
        int minVal = min(min(S.max* A[i], S.min* A[i]), A[i]);
        S.max = maxVal;
        S.min = minVal;
        if (S.max > maxProd) maxProd = S.max;
    }
    return maxProd;
}

int main(int argc, const char * argv[]) {
    int A[] = {2,3,-2,4};
    cout << maxProduct(A, 4) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
