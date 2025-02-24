class Solution {
public:
    int minSteps(string s, string t) {
        vector<int>freq1(26,0);
        for(auto it : s) freq1[it-'a']++;
        for(auto it : t) freq1[it-'a']--;
        int ans=0;
        for(int i=0; i<26; i++){
            ans+=abs(freq1[i]);
        }
        return ans;
    }
};