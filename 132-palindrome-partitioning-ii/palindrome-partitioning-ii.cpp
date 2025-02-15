class Solution {
public:
    bool ispalindrome(string&s , int i, int j){
        while(i<=j){
            if(s[i]!=s[j]) return 0;
            i++;
            j--;
        }
        return 1;
    }
    int f(string&s , int idx,vector<int>&dp){
        if(idx==s.size()){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int cut=INT_MAX;
        for(int i=idx; i<s.size(); i++){
            if(ispalindrome(s,idx,i)){
                if(i==s.size()-1){
                    cut=0;
                }else{
                    cut=min(cut,1+f(s,i+1,dp));
                }
            }
        }
        return dp[idx]=cut;
    }
    int minCut(string s) {
        vector<int>dp(s.size(),-1);
        return f(s,0,dp);
    }
};