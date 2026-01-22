class Solution {
    bool is_sorted(vector<int>&nums){
        int n=nums.size();
        for(int i=1; i<n; i++){
            if(nums[i]<nums[i-1]) return 0;
        }
        return 1;
    }
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return 0;
        int ans=0;
        vector<int>temp=nums;
        while(!is_sorted(temp)){
            int idx=-1;
            int mini_sum=1e9;
            for(int i=0; i<temp.size()-1; i++){
                int sum=temp[i]+temp[i+1];
                if(sum<mini_sum){
                    mini_sum=sum;
                    idx=i;
                }
            }
            temp[idx]=mini_sum;
            temp.erase(temp.begin()+idx+1);
            ans++;

        }
        return ans;

    }
};