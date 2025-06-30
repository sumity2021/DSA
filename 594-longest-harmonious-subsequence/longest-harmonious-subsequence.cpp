class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto it : nums){
            m[it]++;
        }
        int ans=0;
        for(auto & [key,val] : m){
            if(m.find(key+1)!=m.end()){
                ans=max(ans,val+m[key+1]);
            }
        }
        return ans;
    }
};