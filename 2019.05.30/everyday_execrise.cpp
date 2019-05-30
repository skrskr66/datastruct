//对于一个给定的井字棋棋盘，请设计一个高效算法判断当前玩家是否获胜。
//给定一个二维数组board，代表当前棋盘，
//其中元素为1的代表是当前玩家的棋子，为0表示没有棋子，为-1代表是对方玩家的棋子。
#include <iostream>
#include <vector>
using  namespace std;
class Board{
  public:
    bool checkWon(vector<vector<int> > board) {
      //write code here
        //vector<vector<int> >board(n+1,vector<int>(m+1,0));
        //判断行
        for(int i = 0;i < 3;i++)
        {
          if(board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != 0)
          {
            return true;
          }
        }
      //判断列
      for(int j = 0;j < 3;j++)
      {
        if(board[j][0] == board[j][1] && board[j][0] == board[j][2] && board[j][0] != 0)
        {
          return true;
        }
      }

      if(board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != 0)
      {
        return true;
      }
      else if(board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != 0)
      {
        return true;
      }
      return false;

    }
};
