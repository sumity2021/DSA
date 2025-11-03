class Solution {
public:
    void helper(vector<vector<int>>&matrix, int row , int col, int m ,int n){
        for(int i=col-1; i>=0; i--){
            if(matrix[row][i]==1 || matrix[row][i]==2) break;
            matrix[row][i]=0;
        }

        for(int i=col+1; i<n; i++){
            if(matrix[row][i]==1 || matrix[row][i]==2) break;
            matrix[row][i]=0;
        }

        for(int i=row+1; i<m; i++){
            if(matrix[i][col]==1 || matrix[i][col]==2) break;
            matrix[i][col]=0;
        }

        for(int i=row-1; i>=0; i--){
            if(matrix[i][col]==1 || matrix[i][col]==2) break;
            matrix[i][col]=0;
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>matrix(m,vector<int>(n,-1));
        for( auto x : walls){
            matrix[x[0]][x[1]]=1;
        }
        for(auto x : guards){
            matrix[x[0]][x[1]]=2;
        }
        for(auto x : guards){
            helper(matrix, x[0], x[1], m , n);
        }
        int ans=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]==-1){
                    ans++;
                }
            }
        }
        return ans;
    }
};