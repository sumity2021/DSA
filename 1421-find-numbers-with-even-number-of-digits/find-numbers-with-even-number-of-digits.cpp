class Solution {
public:
    int f(int num){
        int cnt=0;
        while(num){
            cnt++;
            num/=10;
        }
        return cnt;
    }
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            if(f(nums[i])%2==0) ans++;
        }
        return ans;
    }
};