class Solution {
    int dp[11][2][11];
    int f(string num , int i , bool tight , int ones){
        if(i==num.size()){
            return ones;
        }
        if(dp[i][tight][ones]!=-1){
            return dp[i][tight][ones];
        }
        int lb=0;
        int ub=(tight)? (num[i]-'0') : 9;
        int ans=0;
        for(int j=lb; j<=ub; j++){
            ans+=f(num,i+1,(tight && (j==ub)),ones+(j==1));
        }
        return dp[i][tight][ones]=ans;
    }
public:
    int countDigitOne(int n) {
        memset(dp,-1,sizeof(dp));
        return f(to_string(n),0,1,0);
    }
};