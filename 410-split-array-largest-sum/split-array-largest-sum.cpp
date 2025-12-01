class Solution {
    int f(vector<int>& nums, int mid){
        int sum=0;
        int k=0;
        for(int num : nums){
            if(sum+num>mid){
                sum=0;
                k++;
            }
            sum+=num;
        }
        return k;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int ans=-1;
        int l=*max_element(nums.begin(),nums.end());
        int r=accumulate(nums.begin(),nums.end(),0);
        while(l<=r){
            int mid=(l+r)/2;
            if(f(nums,mid)>=k){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return l;
    }
};