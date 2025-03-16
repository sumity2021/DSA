class Solution {
public:
    int f(vector<int>& nums,int i, int target,vector<unordered_map<int,int>>&dp){
        if(i==nums.size()) return target==0;
        if(dp[i].count(target)) return dp[i][target];
        int add=f(nums,i+1,target-nums[i],dp);
        int sub=f(nums,i+1,target+nums[i],dp);
        return dp[i][target]=add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<unordered_map<int,int>>dp(nums.size());
        return f(nums,0,target,dp);

    }
};