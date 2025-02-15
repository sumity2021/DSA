class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,int>m;
        long long ans=0;
        long long n=nums.size();
        for(int i=0; i<n; i++){
            int diff=nums[i]-i;
            int gp=m[diff];
            ans+=i-gp;
            m[diff]++;
        }
        return ans;
        
    }
};