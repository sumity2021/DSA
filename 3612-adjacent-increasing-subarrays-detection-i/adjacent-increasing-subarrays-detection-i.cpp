class Solution {
    int check(vector<int>&nums, int st , int end){
        for(int i=st; i<end; i++){
            if(nums[i]>=nums[i+1]) return 0;
        }
        return 1;
    }
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0; i<=n-2*k; i++){
            if(check(nums,i,i+k-1)&& check(nums, i+k, i+k+k-1)) return 1;
        }
        return 0;
    }
};