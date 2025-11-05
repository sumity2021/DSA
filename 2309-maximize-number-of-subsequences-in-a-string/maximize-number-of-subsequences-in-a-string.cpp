class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        int n=text.size();
        long long ans=0;
        int st=0,end=0;
        for(int i=0; i<n; i++){
            if(text[i]==pattern[1]){
                ans+=st;
                end++;
            }
            if(pattern[0]==text[i]){
                st++;
            }
        }
        return ans+max(st,end);
    }
};