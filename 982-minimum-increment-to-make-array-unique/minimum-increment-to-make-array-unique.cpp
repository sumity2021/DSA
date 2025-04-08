class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int n=nums.size();
        for(int i=1; i<n; i++){
            if(nums[i]<=nums[i-1]){
                int diff=abs(nums[i]-nums[i-1]);
                nums[i]+=diff+1;
                ans+=diff+1;
            }
        }
        return ans;
    }
};