class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        int n=text.size();
        long long ans=0;
        unordered_map<char,int>m;
        for(int i=0; i<n; i++){
            if(text[i]==pattern[1]){
                ans+=m[pattern[0]];
            }
            m[text[i]]++;
        }
        return ans+max(m[pattern[0]],m[pattern[1]]);
    }
};