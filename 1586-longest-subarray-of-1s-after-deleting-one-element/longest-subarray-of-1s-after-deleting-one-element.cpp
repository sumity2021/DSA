class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int cnt=0;
        int ans=0;
        for(int r=0; r<n; r++){
            if(nums[r]==0) cnt++;
            while(cnt>1){
                if(nums[l]==0) cnt--;
                l++;
            }
            ans=max(r-l+1,ans);
        }
        return ans-1;
    }
};