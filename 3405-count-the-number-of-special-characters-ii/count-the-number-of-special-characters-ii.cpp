class Solution {
    bool valid(string word , char lower , char upper){
        int cnt_lower=0;
        int cnt_upper=0;
        int n=word.size();
        for(int i=0; i<n; i++){
            if(word[i]==lower){
                if(cnt_upper>0) return 0;
                cnt_lower++;
            }
            if(word[i]==upper) cnt_upper++;
        }
        return cnt_lower && cnt_upper;
    }
public:
    int numberOfSpecialChars(string word) {
        int ans=0;
        for(int i=0; i<26; i++){
            char lower='a'+i;
            char upper='A'+i;
            ans+=valid(word,lower,upper);
        }
        return ans;
    }
};