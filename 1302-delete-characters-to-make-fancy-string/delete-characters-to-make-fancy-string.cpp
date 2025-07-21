class Solution {
public:
    string makeFancyString(string s) {
        string ans="";
        char prev=' ';
        int count=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]==prev){
                count++;
            }else{
                count=0;
            }
            if(count<=1){
                ans.push_back(s[i]);
            }
            prev=s[i];
        }
        return ans;
    }
};