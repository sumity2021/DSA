class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.size();
        int l=0;
        int r=9;
        unordered_map<string ,int>m;
        while(r<n){
            string sb=s.substr(l,r-l+1);
            m[sb]++;
            r++;
            l++;
        }
        vector<string>ans;
        for(auto [key,val]:m){
            if(val>=2){
                ans.push_back(key);
            }
        }
        return ans;

    }
};