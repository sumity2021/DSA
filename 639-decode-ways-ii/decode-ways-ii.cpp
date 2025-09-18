class Solution {
    unordered_set<int>m;
    vector<int>dp;
    const int mod=1e9+7;
    int f(int i, string&s){
        int n=s.size();
        if(i==n) return 1;
        if(s[i]=='0') return 0;
        if(dp[i]!=-1) return dp[i];
        int ans=0;
        if(s[i]=='*'){
            for(int j=1; j<=9; j++){
                ans=(ans+f(i+1,s))%mod;
                if(i+1<n){
                    if(s[i+1]=='*'){
                        for(int k=1; k<=9; k++){
                            if(m.count(j*10+k)){
                                ans=(ans+f(i+2,s))%mod;
                            }
                        }
                    }else{
                        if(m.count(j*10+(s[i+1]-'0'))){
                            ans=(ans+f(i+2,s))%mod;
                        }
                    }
                }
            }
        }else{
            ans=(ans+f(i+1,s))%mod;
            if(i+1<n){
                if(s[i+1]=='*'){
                    for(int k=1; k<=9; k++){
                        if(m.count((s[i]-'0')*10+k)){
                            ans=(ans+f(i+2,s))%mod;
                        }
                    }
                }else{
                    if(m.count((s[i]-'0')*10+(s[i+1]-'0'))){
                        ans=(ans+f(i+2,s))%mod;
                    }
                }
            }

        }
        return dp[i]=ans%mod;
    }
public:
    Solution(){
        for(int i=1; i<=26; i++){
            m.insert(i);
        }
    }
    int numDecodings(string s) {
        int n=s.size();
        dp.resize(n,-1);
        return f(0,s)%mod;
    }
};