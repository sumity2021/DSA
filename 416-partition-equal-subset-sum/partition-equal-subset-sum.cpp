class Solution {
public:
    bool f(vector<int>& nums, int target, int idx,vector<vector<int>>&dp){
        if(target==0) return 1;
        if(target<0 || idx==nums.size()) return 0;
        if(dp[idx][target]!=-1) return dp[idx][target];
        return dp[idx][target]=f(nums,target-nums[idx],idx+1,dp) || f(nums,target,idx+1,dp);
    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum & 1) return 0;
        vector<vector<int>>dp(nums.size(),vector<int>(sum/2+1,-1));
        return f(nums,sum/2,0,dp);
    }
};