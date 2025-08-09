class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        for(int i=0; i<n; i++){
            tasks[i].push_back(i);
        }
        auto cmp =[](auto &a ,auto &b){
            if(a[1]==b[1]) return a[2]>b[2];
            return a[1]>b[1];
        };
        sort(tasks.begin(),tasks.end());
        vector<int>ans;
        int j=0;
        long long t=0;
        priority_queue<vector<int>,vector<vector<int>>,decltype(cmp)>pq(cmp);
        while(pq.size() || j<n){
            while(j<n && tasks[j][0]<=max(t,(long long)tasks[0][0])){
                pq.push(tasks[j]);
                j++;
            }
            if(pq.empty()){
                pq.push(tasks[j]);
                j++;
            }
            vector<int>node=pq.top();
            pq.pop();
            t=max(t+(long long)node[1],(long long)node[0]+(long long)node[1]);
            ans.push_back(node[2]);
        }
        return ans;
    }
};