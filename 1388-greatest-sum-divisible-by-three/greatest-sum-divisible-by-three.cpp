class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        vector<int>ones;
        vector<int>twos;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            if(nums[i]%3==1) ones.push_back(nums[i]);
            if(nums[i]%3==2) twos.push_back(nums[i]);
        }
        int rem=sum%3;
        if(rem==0) return sum;
        sort(ones.begin(),ones.end());
        sort(twos.begin(),twos.end());
        int first=10001;
        int second=10001;
        int third=10001;
        int size1=ones.size();
        int size2=twos.size();
        if(rem==2){
            if(size1>0) first=ones[0];
            if(size1>1) second=ones[1];
            if(size2>0) third=twos[0];
            sum-=min(first+second,third);
        }else{
            if(size2>0) first=twos[0];
            if(size2>1) second=twos[1];
            if(size1>0) third=ones[0];
            sum-=min(first+second,third);
        }
        return sum;
    }
};