class Solution {
    bool isAnagram(string s1 , string s2){
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        return s1==s2;
    }
public:
    vector<string> removeAnagrams(vector<string>& words) {
        stack<string>st;
        int n=words.size();
        for(int i=0; i<n; i++){
            if(st.empty() || !isAnagram(st.top(),words[i])){
                st.push(words[i]);
            }
        }
        vector<string>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};