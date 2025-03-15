class Solution {
public:
    bool f(vector<int>& nums, int k, int capability){
        int homes=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<=capability){ homes++; i++;}
        }
        return k<=homes;
    }
    int minCapability(vector<int>& nums, int k) {
        int l=0;
        int r=1e9;
        while(l<=r){
            int mid=(l+r)/2;
            if(f(nums,k,mid)){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};