class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        int max=0;
        int min=0;
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                max++;
                min++;
            }
            else if(s[i]==')'){
                max--;
                min--;
            }
            else{
                min--;
                max++;
            }
            if(min<0) min=0;
            if(max<0) return 0;
        }
        return min==0;
    }
};