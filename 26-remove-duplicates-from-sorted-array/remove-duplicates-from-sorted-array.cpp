class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int last=0;
        for(int i=0; i<n; i++){
            nums[last]=nums[i];
            while(i<n-1 && nums[i]==nums[i+1]) i++;
            last++;
        }
        return last;
    }
};