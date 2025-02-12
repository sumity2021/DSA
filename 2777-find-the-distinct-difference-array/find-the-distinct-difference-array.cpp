class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        vector<int>m(51,0);
        int n=nums.size();
        int prefix=0;
        vector<int>ans(n,0);
        for(int i=0; i<n; i++){
            if(m[nums[i]]==0){
                prefix++;
            }
            m[nums[i]]++;
            ans[i]+=prefix;
        }
        fill(m.begin(),m.end(),0);
        int suffix=0;
        for(int i=n-1; i>=0; i--){
            ans[i]-=suffix;
            if(m[nums[i]]==0){
                suffix++;
            }
            m[nums[i]]++;
        }
        return ans;
    }
};