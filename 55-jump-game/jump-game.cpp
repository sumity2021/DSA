class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int max_idx=0;
        for(int i=0; i<n; i++){
            if(i>max_idx) return 0;
            max_idx=max(max_idx,i+nums[i]);
        }
        return 1;
    }
};