class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=n-1;
        for(int x=0; x<=j; x++){
            if(nums[x]==0){
                
                swap(nums[i],nums[x]);
                i++;
                
            }
            if(nums[x]==2){
                
                swap(nums[j],nums[x]);
                j--;
                x--;

            }
        }
    }
};