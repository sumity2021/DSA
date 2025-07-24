class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>m;
        int sum=0;
        int ans=0;
        m[0]=1;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            if(m.count(sum-k)){
                ans+=m[sum-k];
            }
            m[sum]++;
        }
        return ans;
    }
};