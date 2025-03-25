class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>>line;
        for(auto it : buildings){
            int x1=it[0];
            int x2=it[1];
            int val=it[2];
            line.push_back({x1,-val});
            line.push_back({x2,val});
        }
        sort(line.begin(),line.end());
        multiset<int>m={0};
        vector<vector<int>>ans;
        int prev_max=0;
        for(auto it : line){
            int x=it[0];
            int h=it[1];
            if(h<0){
                m.insert(-h);
            }else{
                m.erase(m.find(h));
            }
            int maxi=*m.rbegin();
            if(maxi!=prev_max){
                ans.push_back({x,maxi});
                prev_max=maxi;
            }
        }
        return ans;
    }
};