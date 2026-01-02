class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int m=nums.size();
        if(nums[0]==nums[1] || nums[0]==nums[2]) return nums[0];
        if(nums[1]==nums[2]) return nums[1];
        int ele=-1;
        int cnt=0;
        for(int i=3; i<m; i++){
            if(cnt==0){
                ele=nums[i];
                cnt=1;
            }
            else{
                if(ele==nums[i]){
                    cnt++;
                }else{
                    cnt--;
                }
            }
        }
        return ele;
    }
};