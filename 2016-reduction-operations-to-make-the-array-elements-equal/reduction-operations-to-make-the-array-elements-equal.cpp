class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        sort(nums.begin(),nums.end());
        unordered_set<int>s;
        for(int i=0; i<n; i++){
            int unique=s.size();
            if(s.count(nums[i])){
                ans+=(unique-1);
            }else{
                ans+=unique;
            }
            s.insert(nums[i]);
        }
        return ans;
    }
};