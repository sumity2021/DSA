class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int st=0;
        int end=k-1;
        int ans=1e9;
        while(end<n){
            int pairsum=nums[end]-nums[st];
            ans=min(ans,pairsum);
            st++;
            end++;
        }
        return ans;
    }
};