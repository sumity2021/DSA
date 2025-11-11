class Solution {
    vector<vector<vector<int>>>dp;
    vector<int>check(string s , int n , int m){
        int ones=0;
        int zeroes=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='1') ones++;
            else zeroes++;
        }
        return {ones, zeroes};
    }
    int f(vector<string>&s , int i, int n , int m , int len){
        if(i>=len){
            return 0;
        }
        if(dp[i][n][m]!=-1) return dp[i][n][m];
        int take=0, notake=0;
        vector<int>bits=check(s[i],n, m);

        if(bits[0]<=n && bits[1]<=m){
            take=1+f(s,i+1,n-bits[0], m-bits[1], len);
        }
        notake=f(s,i+1,n,m,len);
        return dp[i][n][m]=max(take,notake);

    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        dp.resize(601,vector<vector<int>>(101,vector<int>(101,-1)));
        return f(strs,0,n,m,strs.size());
    }
};