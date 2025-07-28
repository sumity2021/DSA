class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        if(n==k) return "0";
        stack<int>st;
        for(int i=0; i<n; i++){
            int ch=num[i]-'0';
            while(!st.empty() && st.top()>ch && k>0){
                st.pop();
                k--;
            }
            st.push(ch);
        }
        while(k--) st.pop();
        string ans;
        while(!st.empty()){
            ans.push_back(st.top()+'0');
            st.pop();
        }
        while(ans.size()>1 && ans.back()=='0') ans.pop_back();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};