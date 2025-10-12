class Solution {
    vector<vector<int>>dp;
    int f(int i , int amt, vector<int>& coins){
        if(i==coins.size()){
            return amt==0;
        }
        if(dp[i][amt]!=-1) return dp[i][amt];
        int take=0;
        if(coins[i]<=amt){
            take=f(i,amt-coins[i],coins);
        }
        int notake=f(i+1,amt,coins);
        return dp[i][amt]=take+notake;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        dp.resize(n+1,vector<int>(amount+1,-1));
        return f(0,amount,coins);
    }
};