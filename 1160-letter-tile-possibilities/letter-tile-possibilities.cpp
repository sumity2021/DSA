class Solution {
public:
    int backtrack(vector<int>&freq){
        int ans=0;
        for(int i=0; i<26; i++){
            if(freq[i]>0){
                ans++;
                freq[i]--;
                ans+=backtrack(freq);
                freq[i]++;
            }
        }
        return ans;
    }
    int numTilePossibilities(string tiles) {
        vector<int>freq(26,0);
        for(char ch : tiles) freq[ch-'A']++;
        return backtrack(freq);
        
    }
};