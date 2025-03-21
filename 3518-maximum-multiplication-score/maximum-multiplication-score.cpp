class Solution {
public:
    long long f(vector<int>& a, vector<int>& b, int j, int i,vector<vector<long long>>&dp){
        if(j==4){
            return 0;
        }
        if(i==b.size()) return LLONG_MIN;
        if(dp[j][i]!=-1) return dp[j][i];
        long long take=f(a,b,j+1,i+1,dp);
        if(take!=LLONG_MIN) take+=(long long)a[j]*b[i];
        long long notake=f(a,b,j,i+1,dp);
        return dp[j][i]=max(take,notake);
    }
    long long maxScore(vector<int>& a, vector<int>& b) {
        int n=b.size();
        vector<vector<long long>>dp(4,vector<long long>(n,-1));
        return f(a,b,0,0,dp);
    }
};