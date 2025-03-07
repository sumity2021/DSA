class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool>prime(right+1,1);
        prime[1]=0;
        for(long long i=2; i<=right; i++){
            if(prime[i]){
                for(long long j=i*i; j<=right; j+=i){
                    prime[j]=0;
                }
            }
        }
        vector<int>ans;
        for(int i=left; i<=right; i++){
            if(prime[i]){
                ans.push_back(i);
            }
        }
        if(ans.size()<2) return {-1,-1};
        int diff=INT_MAX;
        int var1=-1;
        int var2=-1;
        for(int i=0; i<ans.size()-1; i++){
            if(ans[i+1]-ans[i]<diff){
                diff=ans[i+1]-ans[i];
                var1=ans[i];
                var2=ans[i+1];
            }
        }
        return {var1,var2};
        
    }
};