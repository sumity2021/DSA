class Solution {
public:
    int numSub(string s) {
        int ans=0;
        int cnt=0;
        int mod=1e9+7;
        int n=s.size();
        for(int i=0; i<n; i++){
            if(s[i]=='1'){
                cnt++;
            }else{
                cnt=0;
            }
            ans=(ans+cnt)%mod;
            
        }
        return ans;
    }
};