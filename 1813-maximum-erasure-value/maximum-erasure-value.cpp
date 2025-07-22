class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int>m;
        int n=nums.size();
        int l=0;
        int sum=0;
        int maxi=0;
        for(int r=0; r<n; r++){
            m[nums[r]]++;
            sum+=nums[r];
            while(l<n && m[nums[r]]>1){
                sum-=nums[l];
                m[nums[l]]--;
                l++;
            }
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};