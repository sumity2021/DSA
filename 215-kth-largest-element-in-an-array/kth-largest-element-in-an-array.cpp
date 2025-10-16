class Solution {
    int partition_idx(vector<int>&nums , int st , int end ){
        int i=st;
        int j=end;
        int pivot=nums[st];
        while(i<j){
            while(i<=end && nums[i]<=pivot) i++;
            while(j>=st && nums[j]>pivot) j--;
            if(i<j){
                swap(nums[i],nums[j]);
            }
        }
        swap(nums[j],nums[st]);
        return j;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        int target=n-k;
        while(l<=r){
            int idx=partition_idx(nums ,l , r );
            if(idx==target) return nums[idx];
            else if(idx<target){
                l=idx+1;
            }
            else{
                r=idx-1;
            }
        }
        return -1;
    }
};