class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
        int maj_ele=0;
        int cnt=0;
        for(int i=0; i<n; i++){
            if(cnt==0){
                maj_ele=nums[i];
            }
            if(nums[i]==maj_ele)cnt++;
            else cnt--;
        }
        cnt=0;
        for(int i=0; i<n; i++){
            if(nums[i]==maj_ele) cnt++;
        }
        int leftcnt=0;
        int rightcnt=cnt;
        for(int i=0; i<n; i++){
            int leftsize=i+1;
            int rightsize=n-i-1;
            if(nums[i]==maj_ele){
                leftcnt++;
                rightcnt--;
            }
            if(2*leftcnt>leftsize && 2*rightcnt>rightsize) return i;
        }
        return -1;
    }
};