class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        long long maxtriplet=0;
        long long maxleft=0;
        long long maxdiff=0;
        for(int i=0; i<n; i++){
            maxtriplet=max(maxtriplet,1LL*maxdiff*nums[i]);
            maxdiff=max(maxdiff,maxleft-nums[i]);
            maxleft=max(maxleft,1LL*nums[i]);
        }
        return maxtriplet;
    }
};