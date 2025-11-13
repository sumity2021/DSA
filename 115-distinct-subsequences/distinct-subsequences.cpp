class Solution {
    vector<vector<int>>dp;
    int f(int i ,int j , string s , string t){
        if(j>=t.size()){
            return 1;
        }
        if(i>=s.size()){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j]=f(i+1,j+1,s,t)+f(i+1,j,s,t);
        }
        return dp[i][j]=f(i+1,j,s,t);
    }
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        dp.resize(n,vector<int>(m,-1));
        return f(0,0,s,t);
    }
};