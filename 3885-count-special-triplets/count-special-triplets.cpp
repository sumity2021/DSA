class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>m1;
        unordered_map<int,int>m2;
        for(int i=n-1; i>=0; i--){
            m2[nums[i]]++;
        }
        int ans=0;
        int mod=1e9+7;
        for(int i=0; i<n; i++){
            m2[nums[i]]--;
            long long left=m1[2*nums[i]];
            long long right=m2[2*nums[i]];
            ans=(ans + (left*right)%mod)%mod;
            m1[nums[i]]++;
        }
        return ans;
    }
};