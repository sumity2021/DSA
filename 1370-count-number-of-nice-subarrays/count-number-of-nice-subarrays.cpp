class Solution {
    int helper(vector<int>& nums, int goal){
        if(goal<0) return 0;
        int n=nums.size();
        int l=0;
        int sum=0;
        int cnt=0;
        for(int r=0; r<n; r++){
            sum+=nums[r];
            while(sum>goal){
                sum-=nums[l];
                l++;
            }
            cnt+=(r-l+1);
        }
        return cnt;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0; i<n; i++){
            nums[i]=nums[i]%2;
        }
        return helper(nums,k)-helper(nums,k-1);
    }
};