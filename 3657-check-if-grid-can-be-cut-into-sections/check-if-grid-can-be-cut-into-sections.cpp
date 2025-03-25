class Solution {
public:
    bool helper(vector<pair<int,int>>&coord){
        sort(coord.begin(),coord.end());
        vector<pair<int,int>>intervals;
        intervals.push_back(coord[0]);
        for(int i=1; i<coord.size(); i++){
            auto &last=intervals.back();
            if(last.second>coord[i].first){
                last.second=max(last.second,coord[i].second);
            }else{
                intervals.push_back(coord[i]);
            }
        }
        return (intervals.size()>2) ? 1 : 0;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int,int>>x,y;
        for(auto it : rectangles){
            x.push_back({it[0],it[2]});
            y.push_back({it[1],it[3]});
        }
        return helper(x) || helper(y);
    }
};