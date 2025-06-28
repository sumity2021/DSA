class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        vector<pair<int,int>>temp;
        for(int i=0; i<n; i++){
            temp.emplace_back(i,nums[i]);
        }
        sort(temp.begin(),temp.end(),[&](auto x1, auto x2){ return x1.second > x2.second; });
        vector<int>ans;
        sort(temp.begin(),temp.begin()+k);
        for(int i=0; i<k; i++){
            ans.emplace_back(temp[i].second);
        }
        return ans;
    }
};