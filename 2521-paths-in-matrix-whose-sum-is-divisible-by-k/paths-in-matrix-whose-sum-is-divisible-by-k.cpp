class Solution {
public:
    const int mod=1e9+7;
    int f(vector<vector<int>>& grid,long long i,long long j,long long sum , int k ,vector<vector<vector<long long>>>&dp){
        long long n=grid.size();
        long long m=grid[0].size();
        if(i>=n || j>=m ) return 0;
        if(i==n-1 && j==m-1 ){
            return (sum+grid[i][j]%k)%k==0;
        }
        if(dp[i][j][sum]!=-1) return dp[i][j][sum];
        long long down=f(grid,i+1,j, (sum+grid[i][j]%k)%k,k,dp);
        long long right=f(grid,i,j+1,(sum+grid[i][j]%k)%k,k,dp);
        return dp[i][j][sum]=(right+down)%mod;

    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        long long n=grid.size();
        long long m=grid[0].size();
        vector<vector<vector<long long>>>dp(n,vector<vector<long long>>(m, vector<long long>(k,-1)));
        return f(grid,0,0,0,k,dp );
    }
};