class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        int n=nums.size();
        unordered_map<int,int>m;
        for(int i=0; i<n; i++){
            m[nums[i]]=i;
        }
        for(auto op : operations){
            int idx=m[op[0]];
            m.erase(op[0]);
            nums[idx]=op[1];
            m[op[1]]=idx;
        }
        return nums;
    }
};