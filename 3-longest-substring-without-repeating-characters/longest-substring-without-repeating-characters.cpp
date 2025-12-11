class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char, int>m;
        int l=0;
        int ans=0;
        for(int r=0; r<n; r++){
            if(m.count(s[r])){
                l=max(l,m[s[r]]+1);
            }
            m[s[r]]=r;
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};