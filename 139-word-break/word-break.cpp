
class Solution {
    bool check(int idx, int j,string&s,unordered_set<string>&look){
        string str=s.substr(idx,j-idx+1);
        return look.count(str);
    }
    bool f(int idx,string&s, int n,unordered_set<string>&look,vector<int>&dp){
        if(idx==n)return 1;
        if(dp[idx]!=-1) return dp[idx];
        bool ans=0;
        for(int i=idx; i<n; i++){
            if(check(idx,i,s,look)){
                ans|=f(i+1,s,n,look,dp);
            }
        }
        return dp[idx]=ans;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>look(wordDict.begin(),wordDict.end());
        int n=s.size();
        vector<int>dp(n+1,-1);
        return f(0,s,n,look,dp);
    }
};