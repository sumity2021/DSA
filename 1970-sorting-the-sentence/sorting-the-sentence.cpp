class Solution {
public:
    string sortSentence(string s) {
        vector<string>vec(9,"#");
        int n=s.size();
        int i=0;
        while(i<n){
            int j=i;
            while(!isdigit(s[i])){
                i++;
            }
            vec[s[i]-'0'-1]=s.substr(j,i-j);
            i+=2;
        }
        string ans="";
        for(auto it : vec){
            if(it!="#"){
                ans+=it;
                ans.push_back(' ');
            }
        }
        ans.pop_back();
        return ans;

    }
};