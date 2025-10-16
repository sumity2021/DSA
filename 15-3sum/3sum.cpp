class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int i=0;
        while(i<n){
            int target=-nums[i];
            int st=i+1;
            int end=n-1;
            while(st<end){
                int left=nums[st];
                int right=nums[end];
                if(left + right==target){
                    ans.push_back({nums[i], left , right});
                    while(st<end && nums[st]==left) st++;
                    while(st<end && nums[end]==right) end--;
                }
                else if(left + right<target){
                    while(st<end && nums[st]==left) st++;
                }
                else{
                    while(st<end && nums[end]==right) end--;
                }
            }
            while(i<n-1 && nums[i]==nums[i+1]) i++;
            i++;
        }
        return ans;
        
    }
};