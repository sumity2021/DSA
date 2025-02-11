class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>m;
        int n=nums.size();
        for(int i=0; i<n; i++){
            if(m.count(target-nums[i])){
                return {i,m[target-nums[i]]};
            }
            m[nums[i]]=i;
        }
        return {};
    }
};