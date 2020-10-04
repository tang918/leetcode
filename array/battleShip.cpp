//419：夹板上的战舰
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int rows=board.size();
        int cols = board[0].size();
        int count=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j]=='X'){
                    if(j>0 && board[i][j-1]=='X' || i>0 && board[i-1][j]=='X')continue;
                    count++;
                }
            }
        }
        return count;

    }
};

void test(){
    vector<vector<char>> v1={{'X','.','.','X'},
    {'.','.','.','X'},
    {'.','.','.','X'}
    };
    Solution s;
    cout<<s.countBattleships(v1)<<endl;
}

int main(){
    test();
    return 0;
}