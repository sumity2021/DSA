class Solution {
public:
    int f(vector<int>&nums, int target, int idx){
        if(target==0 && idx==nums.size()) return 1;
        if(idx==nums.size()) return 0;
        int add=f(nums,target-nums[idx], idx+1);
        int sub=f(nums,target+nums[idx], idx+1);
        return add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return f(nums,target, 0);
    }
};