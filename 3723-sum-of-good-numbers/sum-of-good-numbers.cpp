class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        for(int i=0; i<n; i++ ){
            bool prev=1;
            bool next=1;
            if(i+k<n && nums[i]<=nums[i+k]) next=0;
            if(i-k>=0 && nums[i]<=nums[i-k]) prev=0;
            if(next && prev) sum+=nums[i];
        }
        return sum;
    }
};