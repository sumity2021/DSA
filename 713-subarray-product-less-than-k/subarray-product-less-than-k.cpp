class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int prod=1;
        int ans=0;
        if(k==0) return 0;
        for(int i=0; i<n; i++){
            prod*=nums[i];
            while(l<=i && prod>=k){
                prod/=nums[l];
                l++;
            }
            ans+=(i-l+1);
        }
        return ans;
    }
};