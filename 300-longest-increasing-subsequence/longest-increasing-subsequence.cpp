class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0);
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=i-1; j>=0; j--){
                if(nums[i]>nums[j]) dp[i]=max(dp[i],dp[j]);
            }
            dp[i]++;
            ans=max(dp[i],ans);
        }
        return ans;
    }
};