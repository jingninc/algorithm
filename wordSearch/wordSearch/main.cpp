
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool valid(vector<vector<char> > &board, string word, int curr, int row, int col, vector<vector<bool>> &visited){
    if (curr == word.size()){
        return true;
    }
    if (row < 0 || row >= board.size() || col < 0 || col >= board.front().size()){
        return false;
    }
    if (visited[row][col]) return false;
    if (board[row][col] != word[curr]) return false;
    visited[row][col] = true;
    bool up = valid(board, word, curr+1, row-1, col, visited);
    bool down = valid(board, word, curr+1, row+1, col, visited);
    bool left = valid(board, word, curr+1, row, col-1, visited);
    bool right = valid(board, word, curr+1, row, col+1, visited);
    bool flag = (up || down || left || right);
    if (!flag) visited[row][col] = false;
    return flag;
}


bool exist(vector<vector<char> > &board, string word) {
    if (board.size() == 0 || board.front().size() == 0) return false;
    int rows = board.size();
    int cols = board.front().size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if (valid(board, word, i, j, 0, visited) ) return true;
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
