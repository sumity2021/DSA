class Solution {
public:
    int countCommas(int n) {
        int ans=0;
        while(n){
            ans+=n>999 ? n-999 : 0 ;
            n/=1000;
        }
        return ans;
    }
};