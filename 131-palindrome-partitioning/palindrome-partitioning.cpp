class Solution {
public:
    bool ispalindrome(int i, int j , string&s){
        while(i<=j){
            if(s[i]!=s[j]) return 0;
            i++;
            j--;
        }
        return 1;
    }
    void f(string&s ,vector<string>&path, vector<vector<string>>&ans, int idx){
        if(idx==s.size()){
            ans.push_back(path);
            return;
        }
        for(int i=idx; i<s.size(); i++){
            if(ispalindrome(idx,i,s)){
                path.push_back(s.substr(idx,i-idx+1));
                f(s,path,ans,i+1);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>path;
        vector<vector<string>>ans;
        if(s.size()==0) return ans;
        f(s,path,ans,0);
        return ans;
    }
};