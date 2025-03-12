class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        int startPosition=lower_bound(nums.begin(),nums.end(),0)-nums.begin();
        int endPosition=lower_bound(nums.begin(),nums.end(),1)-nums.begin();
        return max(startPosition,n-endPosition);
    }
};