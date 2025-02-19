class Solution {
public:
    void f(int idx,int n, string & s, vector<string>&str){
        if(idx==n){
            str.push_back(s);
            return;
        }
        for(char it='a'; it<='c'; it++){
            if(s.empty()){
                s.push_back(it);
                f(idx+1,n,s,str);
                s.pop_back();
            }else if(s.back()!=it){
                s.push_back(it);
                f(idx+1,n,s,str);
                s.pop_back();
            }
        }
    }
    string getHappyString(int n, int k) {
        vector<string>str;
        string s="";
        f(0,n,s,str);
        if(str.size()<k){
            return "";
        }
        return str[k-1];
    }
};