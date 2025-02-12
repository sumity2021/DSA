class Solution {
public:
    int numtosum(int num){
        int ans=0;
        while(num>0){
            int rem=num%10;
            ans+=rem;
            num/=10;
        }
        return ans;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,int>m;
        int n=nums.size();
        int maxi=-1;
        for(int i=0; i<n; i++){
            int key=numtosum(nums[i]);
            if(m.find(key)==m.end()){
                m[key]=nums[i];
            }else{
                maxi=max(maxi,nums[i]+m[key]);
                m[key]=max(m[key],nums[i]);
            }
        }
        return maxi;

    }
};