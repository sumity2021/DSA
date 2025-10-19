class Solution {
    vector<vector<int>>dp;
    int f(int i, int target ,vector<int>& nums ){
        if(target==0) return 0;
        if(i==nums.size()){
            return -1e9;
        }
        if(dp[i][target]!=-1) return dp[i][target];
        int take=-1e9;
        if(nums[i]<=target) take=1+f(i+1,target-nums[i],nums);
        int notake=f(i+1,target,nums);
        return dp[i][target]=max(take, notake);
    }
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n=nums.size();
        dp.resize(n+1,vector<int>(target+1 ,-1));
        int ans=f(0,target,nums);
        return ans>=1 ? ans : -1;
    }
};