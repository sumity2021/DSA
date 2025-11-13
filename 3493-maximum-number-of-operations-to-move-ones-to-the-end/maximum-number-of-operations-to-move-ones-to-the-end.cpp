class Solution {
public:
    int maxOperations(string s) {
        int n=s.size();
        int ans=0;
        int ones=0;
        int i=0;
        while(i<n){
            if(s[i]=='0'){
                ans+=ones;
                while(s[i]=='0') i++;
            }else{
                ones++;
                i++;
            }
        }
        return ans;
    }
};