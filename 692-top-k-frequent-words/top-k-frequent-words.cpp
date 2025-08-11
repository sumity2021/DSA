class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>m;
        for( auto w : words){
            m[w]++;
        }
        vector<pair<int , string>>temp;
        vector<string>ans;
        for(auto [key,val] : m){
            temp.push_back({val,key});
        }
        sort(temp.begin(),temp.end(),[&](auto a ,auto b){
            if(a.first==b.first){
                return b.second>a.second;
            }
            return a.first>b.first;
        });
        for(int i=0; i<k; i++){
            ans.push_back(temp[i].second);
        }
        return ans;
    }
};