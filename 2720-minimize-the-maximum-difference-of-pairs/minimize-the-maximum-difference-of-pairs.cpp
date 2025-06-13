class Solution {
public:
    int f(vector<int>& nums, int diff){
        int count=0;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i+1]-nums[i]<=diff){
                count++;
                i++;
            }
        }
        return count;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int st=0;
        int end=1e9;
        while(st<end){
            int mid=(st+end)/2;
            if(f(nums,mid)<p){
                st=mid+1;
            }else{
                end=mid;
            }
        }
        return st;
    }
};