class Solution {
public:
    int f(vector<int>& arr, int x, vector<int>&dp){
        if(x<0){
            return INT_MAX;
        }
        if(x==0){
            return 0;
        }
        if(dp[x]!=-1){
            return dp[x];
        }
        int ans=INT_MAX;
        for(int i=0; i<arr.size(); i++){
            ans=min(ans,f(arr,x-arr[i],dp));
        }
        return dp[x]=(ans==INT_MAX)? ans: ans+1;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
        sort(coins.begin(),coins.end());
        int res=f(coins,amount,dp);
        return (res==INT_MAX)? -1:res;
    }
};