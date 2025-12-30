class Solution {
    long long dp[16][2][288][2][2];
    long long f(string num, int i , bool parity , int sum , bool tight , bool lz){
        if(i==num.size()){
            return sum==0;
        }
        if(dp[i][parity][sum+144][tight][lz]!=-1){
            return dp[i][parity][sum+144][tight][lz];
        }
        int lb=0;
        int ub=(tight)? num[i]-'0' : 9;
        long long res=0;
        for(int j=lb; j<=ub; j++){
            int ns=sum;
            bool np=parity;
            bool nlz= lz &&(j==0);
            if(!nlz){
                if(np) ns+=j;
                else ns-=j;
                np = !np;
            }
            res+=f(num,i+1,np,ns,(tight&&(ub==j)),nlz);
        }
        return dp[i][parity][sum+144][tight][lz]=res;
    }
public:
    long long countBalanced(long long low, long long high) {
        memset(dp,-1,sizeof(dp));
        long long right_ans=f(to_string(high),0,1,0,1,1);
        memset(dp,-1,sizeof(dp));
        long long left_ans=f(to_string(low-1),0,1,0,1,1);
        return right_ans-left_ans;
    }
};