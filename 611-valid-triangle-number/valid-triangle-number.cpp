class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=n-1; i>=2; i--){
            int l=0;
            int r=i-1;
            while(l<r){
                int sum=nums[l]+nums[r];
                if(sum>nums[i]){
                    ans+=(r-l);
                    r--;
                }else{
                    l++;
                }
            }
        }
        return ans;
    }
};