class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        unordered_map<int,int>m;
        for(int i=0; i<n; i++){
            m[nums[i]]++;
        }
        if(m.size()==n){
            return 0;
        }
        int i=0;
        while(i<=n-3){
            if((n-i)>m.size()){
                ans++;
            }
            m[nums[i]]--;
            if(m[nums[i]]==0)m.erase(nums[i]);
            m[nums[i+1]]--;
            if(m[nums[i+1]]==0)m.erase(nums[i+1]);
            m[nums[i+2]]--;
            if(m[nums[i+2]]==0)m.erase(nums[i+2]);
            i+=3;
        }
        if((n-i)>m.size()){
            ans++;
        }
        return ans;
    }
};