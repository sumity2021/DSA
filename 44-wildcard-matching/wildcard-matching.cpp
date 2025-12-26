class Solution {
    int dp[2001][2001];
    bool f(int n , int m , string & s ,string & p){
        if(m==0){
            return n==0;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        bool ans=0;
        if(p[m-1]=='*'){
            ans=f(n,m-1,s,p)||(n>0 && f(n-1,m,s,p));
        }else if(n>0 && ( s[n-1]==p[m-1] || p[m-1]=='?' )){
            ans=f(n-1,m-1 , s,p);
        }
        return dp[n][m]=ans;
    }
public:
    bool isMatch(string s, string p) {
        memset(dp,-1,sizeof(dp));
        return f(s.size(),p.size(),s,p);
    }
};