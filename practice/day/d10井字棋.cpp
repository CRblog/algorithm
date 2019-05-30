class Board {
public:
    bool checkWon(vector<vector<int> > board) {
        // write code here

        for(int i=0;i<3;i++)
            {
              if(board[i][0]==1&&board[i][0]==board[i][1]&&board[i][1]==board[i][2])
                {
                return true;
                }
              if(board[0][i]==1&&board[0][i]==board[1][i]&&board[1][i]==board[2][i])
                {
                return true;
                }
            }
             if(board[0][0]==1&&board[0][0]==board[1][1]&&board[1][1]==board[2][2])
                {
                return true;
                }
             if(board[0][2]==1&&board[0][2]==board[1][1]&&board[1][1]==board[2][0])
                {
                return true;
                }
        return false;
    }
};
