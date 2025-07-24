class Solution {
public:
    void backtrack(vector<int>&freq,unordered_set<string>&ans,string str){
        ans.insert(str);
        for(int i=0; i<26; i++){
            if(freq[i]>0){
                str.push_back(i+'A');
                freq[i]--;
                backtrack(freq,ans,str);
                freq[i]++;
                str.pop_back();
            }
        }
    }
    int numTilePossibilities(string tiles) {
        vector<int>freq(26,0);
        unordered_set<string>ans;
        for(char ch : tiles) freq[ch-'A']++;
        backtrack(freq,ans,"");
        return ans.size()-1;
    }
};