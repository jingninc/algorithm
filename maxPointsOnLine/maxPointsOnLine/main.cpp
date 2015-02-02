//
//  main.cpp
//  maxPointsOnLine
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

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

int maxPoints(vector<Point> &points) {
    if (points.size() == 0) return 0;
    int maxPt = 1;
    for(int i = 0; i < points.size(); i++){
        unordered_map<double, int> countMap;
        int largest = 0;
        int dup = 0;
        for(int j = 0; j < points.size(); j++){
            if (points[i].x == points[j].x && points[i].y == points[j].y) {
                dup++;
                continue;
            }
            double x_diff = points[j].x-points[i].x;
            double y_diff = points[j].y-points[i].y;
            if (x_diff == 0) {
                largest = max(largest, ++countMap[INT_MAX] + dup);
            } else {
                largest = max(largest, ++countMap[y_diff/x_diff] + dup);
            }
        }
        // largest = max(largest, dup)  when all the points in the vector are at the same point.
        maxPt = max(max(largest, dup), maxPt);
    }
    return maxPt;
}

int main(int argc, const char * argv[]) {
    Point p1(1, 1);
    Point p2(1, 1);
    Point p3(2, 2);
    Point p4(2, 2);
    vector<Point> points = {p1, p2, p3, p4};
    cout << maxPoints(points) << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
