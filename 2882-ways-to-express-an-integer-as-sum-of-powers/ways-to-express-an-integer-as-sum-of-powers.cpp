class Solution {
public:
    int mod=1e9+7;
    int f(vector<int>&arr,int target, int i,vector<vector<int>>&dp){
        if(target==0) return 1;
        if(target<0 || i==arr.size()) return 0;
        if(dp[i][target]!=-1) return dp[i][target];
        int take=f(arr,target-arr[i],i+1,dp);
        int notake=f(arr,target,i+1,dp);
        return dp[i][target]=(take + notake)%mod;
    }
    int numberOfWays(int n, int x) {
        vector<int>arr;
        int i=1;
        int num;
        do{
            num=pow(i,x);
            arr.push_back(num);
            i++;
        }while(num<=n);
        vector<vector<int>>dp(arr.size(),vector<int>(n+1,-1));
        return f(arr,n,0,dp);

    }
};