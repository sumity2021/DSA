class Solution {
    int helper(vector<int>& nums, int goal){
        int n=nums.size();
        int l=0;
        unordered_map<int,int>m;
        int cnt=0;
        for(int r=0; r<n; r++){
            m[nums[r]]++;
            while(m.size()>goal){
                m[nums[l]]--;
                if(m[nums[l]]==0)m.erase(nums[l]);
                l++;
            }
            cnt+=(r-l+1);
        }
        return cnt;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums,k)-helper(nums,k-1);
    }
};