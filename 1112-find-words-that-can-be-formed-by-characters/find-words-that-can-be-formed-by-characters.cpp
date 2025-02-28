class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int>freq(26,0);
        for( auto it : chars){
            freq[it-'a']++;
        }
        int n=words.size();
        int ans=0;
        for(int i=0; i<n; i++){
            vector<int>temp=freq;
            ans+=words[i].size();
            for(auto it : words[i]){
                temp[it-'a']--;
                if(temp[it-'a']<0){
                    ans-=words[i].size();
                    break;
                }
            }
        }
        return ans;
    }
};