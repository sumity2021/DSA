class Solution {
    int pal_len(string s , int l , int r ){
        while(l>=0 && r<s.size() && s[l]==s[r]){
            l--;
            r++;
        }
        return r-l-1;
    }
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int st=0, end=0;
        for(int i=0; i<n; i++){
            int len_odd=pal_len(s , i , i);
            int len_even=pal_len(s , i, i+1);
            int len =max(len_odd, len_even);
            if(len>end-st){
                st=i-(len-1)/2;
                end=i+len/2;
            }
        }
        return s.substr(st,end-st+1);

    }
};