class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int cnt=1;
        int max_cnt=0;
        sort(nums.begin(),nums.end());
        for(int i=0; i<n; i++){
            while(i<n-1 && nums[i]==nums[i+1]) i++;
            if(i<n-1 && nums[i]+1==nums[i+1]) cnt++;
            else cnt=1;
            max_cnt=max(max_cnt,cnt);
        }
        return max_cnt;
    }
};