class Solution {
public:
    int f(vector<int>&nums, int n,vector<int>&dp){
        if(n<0){
            return 0;
        }
        if(dp[n]!=-1) return dp[n];
        int not_take=f(nums,n-1,dp);
        int take=f(nums,n-2,dp)+nums[n];
        return dp[n]=max(not_take,take);
    }
    int rob(vector<int>& nums) {
        vector<int>nums1;
        vector<int>nums2;
        int n=nums.size();
        if(n==1) return nums[0];
        for(int i=0; i<n; i++){
            if(i!=n-1){
                nums1.push_back(nums[i]);
            }
            if(i!=0){
                nums2.push_back(nums[i]);
            }
        }
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);
        return max(f(nums1,nums1.size()-1,dp1),f(nums2,nums2.size()-1,dp2));
    }
};