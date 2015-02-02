//
//  main.cpp
//  LRUCache
//
//  Created by JINGNING CAO on 1/22/15.
//  Copyright (c) 2015 JINGNING CAO. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <sstream>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class LRUCache{
private:
    struct CacheNode{
        int key;
        int val;
        CacheNode(int m, int n): key(m), val(n) {}
    };
    int capacity;
    list<CacheNode*> cacheList;
    unordered_map<int, list<CacheNode*>::iterator>cacheMap;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
       	if (cacheMap.count(key) == 0) return -1;
        else {	// move the found node to the beginning of the list.
            auto found = cacheMap[key];
            cacheList.splice(cacheList.begin(), cacheList, found);
            cacheMap[key] = cacheList.begin();
            return cacheList.front()->val;
        }
    }
    
    void set(int key, int value) {
        if (cacheMap.count(key) == 0 ){
            if (cacheList.size() == capacity){
                // this step can be forgotten. the mapping of the node to be deteled in the hashmap should be deleted.
                CacheNode* last = cacheList.back();
                cacheMap.erase(last->key);
                cacheList.pop_back();
            }
            cacheList.push_front(new CacheNode(key, value));
            cacheMap[key] = cacheList.begin();
        } else{
            auto found = cacheMap[key];
            cacheList.splice(cacheList.begin(), cacheList, found);
            cacheList.front()->val = value;
            cacheMap[key] = cacheList.begin();
        }
    }
};

int main(int argc, const char * argv[]) {
//    LRUCache c(2);
//    c.set(2, 1);
//    c.set(1, 1);
//    cout << c.get(2) << endl; //1
//    c.set(4, 1);
//    cout << c.get(1) << endl; // -1
//    cout << c.get(2) << endl; // 1
    
        LRUCache c(2);
        c.set(2,1);
        c.set(1,1);
        c.set(2,3);
        c.set(4,1);
        cout << c.get(1) << endl; //-1
        cout << c.get(2) << endl; //3

    std::cout << "Hello, World!\n";
    return 0;
}
