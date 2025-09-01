class Solution {
public:
    double cal_gain(int x , int y){
        return  (double)(x+1)/(y+1) - (double)x/y;
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,pair<int,int>>>pq;
        for ( auto it : classes){
            pq.push({cal_gain(it[0],it[1]),{it[0],it[1]}});
        }
        while(extraStudents--){
            auto it = pq.top();
            auto x=it.second;
            pq.pop();
            pq.push({cal_gain(x.first+1,x.second+1),{x.first+1,x.second+1}});
        }
        double ans=0;
        while(!pq.empty()){
            auto it = pq.top();
            auto x=it.second;
            pq.pop();
            ans+=(double)x.first/x.second;
        }
        return ans/classes.size();
    }
};