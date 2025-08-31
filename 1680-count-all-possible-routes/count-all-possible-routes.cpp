class Solution {
    const int mod=1e9+7;
    int dp[201][201];
    int f(int pos , int finish, int fuel , vector<int>&locations){
        int n=locations.size();
        if(fuel<0){
            return 0;
        }
        if(dp[pos][fuel]!=-1) return dp[pos][fuel];
        long long cnt=(pos==finish)?1:0;
        for(int i=0; i<n; i++){
            int need=abs(locations[i]-locations[pos]);
            if(pos!=i && need<=fuel){
                cnt=(cnt+f(i,finish , fuel-need,locations))%mod;
            }
        }
        return dp[pos][fuel]= cnt;
    }
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n=locations.size();
        memset(dp,-1,sizeof(dp));
        return f(start,finish,fuel,locations);
    }
};