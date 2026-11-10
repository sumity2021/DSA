class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int>dp(n,0);
        for(int i=0; i<n; i++){
            int first=0,second=0,third=0;
            if(i-3>=0){
                third=dp[i-3];
            }
            if(i-2>=0){
                second=dp[i-2];
            }
            if(i-1>=0){
                first=dp[i-1];
            }
            dp[i]=min({first+1,second+4,third+9})+costs[i];
        }
        return dp[n-1];
    }
};