class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        vector<int>m(256,-1);
        int l=0;
        int ans=0;
        for(int r=0; r<n; r++){
            if(m[s[r]]!=-1){
                l=max(l,m[s[r]]+1);
            }
            m[s[r]]=r;
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};