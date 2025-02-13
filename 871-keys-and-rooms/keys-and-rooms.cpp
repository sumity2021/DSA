class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        queue<int>q;
        q.push(0);
        int size=0;
        vector<int>vis(n,0);
        vis[0]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            size++;
            for(auto it : rooms[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
        return size==n;
    }
};