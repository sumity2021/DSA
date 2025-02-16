class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        if(n==1) return 0;
        int ans=INT_MAX;
        for(int i=0; i<=1; i++){
            char ch=i+'0';
            int op=0;
            for(int i=0; i<n; i++){
                if(s[i]!=ch){
                    op++;
                }
                ch++;
                ch=(ch-'0')%2+'0';
            }
            ans=min(op,ans);
        }
        return ans;
    }
};