class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        vector<int>index(26,0);
        for(int i=0; i<n; i++){
            index[s[i]-'a']=i;
        }
        int max_idx=0;
        int prev_idx=0;
        vector<int>ans;
        for(int i=0; i<n; i++){
            max_idx=max(max_idx,index[s[i]-'a']);
            if(max_idx==i){
                ans.push_back(i-prev_idx+1);
                prev_idx=i+1;
            }
        }
        return ans;
    }
};