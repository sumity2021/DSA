class Solution {
    bool is_prime(int num){
        if(num<2)return 0;
        for(int i=2; i*i<=num; i++){
            if(num%i==0) return 0;
        }
        return 1;
    }
    vector<int>f(int n){
        vector<bool>vis(n+1,0);
        vis[0]=vis[1]=1;
        for(int i=2; i*i<=n; i++){
            if(vis[i]) continue;
            for(int j=i*i; j<=n; j+=i){
                vis[j]=1;
            }
        }
        vector<int>ans;
        for(int i=2; i<=n; i++){
            if(!vis[i]){
                ans.push_back(i);
            }
        }
        return ans;
        
        
    }
public:
    int largestPrime(int n) {
        vector<int>primes=f(n);
        int m=primes.size();
        int sum=0;
        int ans=0;
        for(int r=0; r<m; r++){
            sum+=primes[r];
            if(sum>n) break;
            if(is_prime(sum)){
                ans=max(ans,sum);
            }
        }
        return ans;
    }
};