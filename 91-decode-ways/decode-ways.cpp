class Solution {
    int f( int i , string&s, unordered_set<int>&m, int n,vector<int>&dp){
        if(i==n) return 1;
        int ans=0;
        if(s[i]=='0') return 0;
        if(dp[i]!=-1) return dp[i];
        if(i<n-1 && m.count((s[i]-'0')*10 + (s[i+1]-'0'))){
            ans+=f(i+2,s,m,n,dp);
        }
        if(m.count(s[i]-'0')){
            ans+=f(i+1,s,m,n,dp);
        }
        return dp[i]=ans;

    }
public:
    int numDecodings(string s) {
        unordered_set<int>valid;
        int n=s.size();
        vector<int>dp(n,-1);
        for(int i=1; i<=26; i++){
            valid.insert(i);
        }
        return f(0,s,valid,n,dp);
    }
};