class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n=nums.size();
        unordered_map<int,int>m;
        for(int i=0; i<n; i++){
            int mod=(nums[i]%value +value)%value;
            nums[i]=mod;
            if(m.count(mod)){
                nums[i]+=m[mod]*value;
            }
            m[mod]++;
        }
        sort(nums.begin(),nums.end());
        for(int i=0; i<n; i++){
            cout<<nums[i]<<" ";
        }
        if(nums[0]!=0) return 0;
        for(int i=0; i<n-1; i++){
            if(abs(nums[i]-nums[i+1])>1)return nums[i]+1;
        }
        return nums[n-1]+1;
        
    }
};