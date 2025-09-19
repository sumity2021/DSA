class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int st=0;
        int end=n-1;
        while(st<=end){
            int mid=(st+end)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]>=nums[st]){
                if(nums[mid]>target && nums[st]<=target){
                    end=mid-1;
                }else{
                    st=mid+1;
                }
            }else{
                if(nums[mid]<target && nums[end]>=target){
                    st=mid+1;
                }else{
                    end=mid-1;
                }
            }

        }
        return -1;
    }
};