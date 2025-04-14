class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int min_ele=*min_element(nums.begin(),nums.end());
        if(k>min_ele){
            return -1;
        }
        unordered_set<int>s(nums.begin(),nums.end());
        s.insert(k);
        return s.size()-1;
    }
};