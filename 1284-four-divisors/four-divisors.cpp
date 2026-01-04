class Solution {
    int f(int n){
        int cnt=0;
        int sum=0;
        for(int i=1; i*i<=n; i++){
            if(n%i==0){
                cnt++;
                sum+=(i);
                if(n/i!=i){
                    cnt++;
                    sum+=(n/i);
                }
            }
        }
        if(cnt==4){
            return sum;
        }
        return -1;

    }
public:
    int sumFourDivisors(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(auto num : nums){
            int div_sum=f(num);
            cout<<div_sum<<endl;
            if(div_sum!=-1){
                ans+=div_sum;
            }
        }
        return ans;
    }
};