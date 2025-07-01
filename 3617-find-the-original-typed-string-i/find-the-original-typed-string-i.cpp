class Solution {
public:
    int possibleStringCount(string word) {
        int n=word.size();
        int res=1;
        for(int i=0; i<n; i++){
            int cnt=0;
            while(i<n-1 && word[i]==word[i+1]){
                cnt++;
                i++;
            }
            res+=cnt;
        }
        return res;
        
        
    }
};