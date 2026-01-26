class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& nums) {
        int n=nums.size();
        int min_diff=1e9;
        sort(nums.begin(),nums.end());
        for(int i=0; i<n-1; i++){
            int x=nums[i];
            int y=nums[i+1];
            min_diff=min(min_diff,y-x);
        }
        vector<vector<int>>ans;
        for(int i=0; i<n-1; i++){
            int x=nums[i];
            int y=nums[i+1];
            if(y-x==min_diff){
                ans.push_back({x,y});
            }
        }
        return ans;
    }
};