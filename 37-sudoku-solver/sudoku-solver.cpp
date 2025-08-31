class Solution {
    bool valid(int i , int j ,int num,vector<vector<vector<int>>>&check){
        int sub_pos=(i/3)*3+(j/3);
        if(check[0][sub_pos][num]!=-1) return 0;
        if(check[1][i][num]!=-1) return 0;
        if(check[2][j][num]!=-1) return 0;
        return 1;
    }
    bool f(int pos ,vector<vector<vector<int>>>&check,vector<vector<char>>& board){
        if(pos==81)return 1;
        int i=pos/9;
        int j=pos%9;
        if(board[i][j]!='.') return f(pos+1,check,board);
        for(int x=1; x<=9; x++){
            if(valid(i,j,x,check)){
                int sub_pos=(i/3)*3+(j/3);
                check[0][sub_pos][x]=x;
                check[1][i][x]=x;
                check[2][j][x]=x;
                board[i][j]=x+'0';
                if(f(pos+1,check,board))return 1;
                check[0][sub_pos][x]=-1;
                check[1][i][x]=-1;
                check[2][j][x]=-1;
                board[i][j]='.';

            }
        }
        return 0;

    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<vector<int>>>check(3,vector<vector<int>>(9,vector<int>(10,-1)));
        for(int i=0; i<n; i++ ){
            for(int j=0; j<m; j++){
                if(board[i][j]=='.') continue;
                int pos=(i/3)*3+(j/3);
                int ele=board[i][j]-'0';
                check[0][pos][ele]=ele;
                check[1][i][ele]=ele;
                check[2][j][ele]=ele;
            }
        }
        f(0,check,board);
    }
};