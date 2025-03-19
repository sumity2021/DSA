class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int st=-1;
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            if(st==-1){
                st=nums[i];
                ans++;
            }
            if(nums[i]-st>k){
                ans++;
                st=nums[i];
            }
        }
        return ans;
    }
};