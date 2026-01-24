class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l=0;
        int r=n-1;
        int ans=0;
        while(l<r){
            int pair_sum=nums[l]+nums[r];
            ans=max(ans,pair_sum);
            l++;
            r--;
        }
        return ans;
    }
};