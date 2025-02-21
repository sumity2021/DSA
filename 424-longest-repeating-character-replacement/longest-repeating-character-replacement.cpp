class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int ans=0;
        for(char ch='A'; ch<='Z'; ch++){
            int op=k;
            int l=0;
            for(int i=0; i<n; i++){
                if(ch!=s[i]){
                    op--;
                }
                while(op<0){
                    if(s[l]!=ch){
                        op++;
                    }
                    l++;
                }
                ans=max(ans,i-l+1);
            }
        }
        return ans;
    }
};