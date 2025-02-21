class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char>freq={'a','e','i','o','u'};
        int n=s.size();
        int l=0;
        int cnt=0;
        int ans=0;
        for(int i=0; i<n; i++){
            if(freq.count(s[i])){
                cnt++;
            }
            if((i-l+1)>k){
                if(freq.count(s[l])){
                    cnt--;
                }
                l++;
            }
            ans=max(cnt,ans);
        }
        return ans;
    }
};