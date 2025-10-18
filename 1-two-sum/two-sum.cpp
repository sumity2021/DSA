class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>m;
        int st=-1;
        int end=-1;
        int n=nums.size();
        for(int i=0; i<n; i++){
            int ele=target-nums[i];
            if(m.count(ele)){
                st=m[ele];
                end=i;
                return {st,end};
            }
            m[nums[i]]=i;
        }
        return {st,end};
    }
};