class Solution {
public:
    int maxPower(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0; i<n; i++){
            int l=i;
            while(i<n-1 && s[i]==s[i+1]) i++;
            ans=max(ans,i-l+1);
        }
        return ans;
    }
};