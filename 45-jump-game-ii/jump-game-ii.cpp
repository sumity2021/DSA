class Solution {
public:
    int f(vector<int>& nums, int i,vector<int>&dp){
        int n=nums.size();
        if(i==n-1){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int mini=INT_MAX;
        for(int j=1; j<=nums[i]; j++){
            if(i+j>=n) break;
            int jumps=f(nums,i+j,dp);
            if(jumps!=INT_MAX){
                mini=min(mini,jumps);
            } 
        }
        return dp[i]=(mini==INT_MAX)? INT_MAX: mini+1;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return f(nums,0,dp);
    }
};