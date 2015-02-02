//
//  main.cpp
//  insertInterval
//
//  Created by JINGNING CAO on 1/16/15.
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


struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    for(auto curr = intervals.begin(); curr != intervals.end(); ){
        if (newInterval.end < curr->start){
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        } else if (newInterval.start > curr->end){
            curr++;
        } else {
            newInterval.start = min(curr->start, newInterval.start);
            newInterval.end = max(curr->end, newInterval.end);
            curr = intervals.erase(curr);
        }
    }        
    intervals.push_back(newInterval);
    return intervals;
}

int main(int argc, const char * argv[]) {
        vector<Interval> intervals = {*new Interval(1, 3), *new Interval(6, 9)};
        Interval* inserted = new Interval(2, 5);
        vector<Interval> res = insert(intervals, *inserted);
        for (Interval elem : res){
            cout << elem.start << " " << elem.end << endl;
        }
    
    
//        vector<Interval> intervals;
//            intervals.push_back(Interval(1, 3));
//            intervals.push_back(Interval(5, 7));
//            intervals.push_back(Interval(9, 12));
//            intervals.push_back(Interval(15, 17));
//        Interval inserted(0, 15);
    
//    vector<Interval> intervals;
//    intervals.push_back(Interval(2, 5));
//    Interval inserted(0, 1);
//    vector<Interval> res = insert(intervals, inserted);
//    for(auto it : res){
//        cout << it.start << " | " << it.end << endl;
//    }

    std::cout << "Hello, World!\n";
    return 0;
}
