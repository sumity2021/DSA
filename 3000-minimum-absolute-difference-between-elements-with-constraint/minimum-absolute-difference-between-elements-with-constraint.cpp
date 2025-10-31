class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int n=nums.size();
        set<int>s;
        int ans=1e9;
        for(int i=0; i<n; i++){
            if(i>=x){
                s.insert(nums[i-x]);
                cout<<nums[i-x]<<" ";
            }
            auto it1 =s.lower_bound(nums[i]);
            auto it2=s.upper_bound(nums[i]);
            if(it1!=s.end()){
                ans=min(ans,abs(nums[i]-*it1));
            }
            if(it2!=s.begin()){
                it2--;
                ans=min(ans,abs(nums[i]-*it2));
            }
            
        }
        return ans;
    }
};