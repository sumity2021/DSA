class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>m;
        int same=0,r=-1;
        long long ans=0;
        for(int i=0; i<n; i++){
            while(same<k && r+1<n){
                r++;
                same+=m[nums[r]];
                m[nums[r]]++;
            }
            if(same>=k){
                ans+=n-r;
            }
            m[nums[i]]--;
            same-=m[nums[i]];
        }
        return ans;
    }
};