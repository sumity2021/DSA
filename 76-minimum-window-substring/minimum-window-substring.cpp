class Solution {
    bool check(vector<int>&freqt,vector<int>&freq){
        for(int i=0; i<256; i++){
            if(freq[i]<freqt[i]) return 0;
        }
        return 1;
    }
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(m>n) return "";
        vector<int>freqt(256,0);
        for(int i=0; i<m; i++) freqt[t[i]]++;
        vector<int>freq(256,0);
        int l=0;
        int len=INT_MAX;
        int bestL=0;

        for(int r=0; r<n; r++){
            freq[s[r]]++;
            while(check(freqt,freq)){
                freq[s[l]]--;
                if((r-l+1)<len){
                    len=r-l+1;
                    bestL=l;
                }
                l++;
            }
        }
        if(len==INT_MAX) return "";
        return s.substr(bestL,len);
    }
};