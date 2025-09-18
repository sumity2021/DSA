class TaskManager {
    struct cmp{
        bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
            if (a.first != b.first) return a.first > b.first;   
            return a.second > b.second;                        
        }
    };
    unordered_map<int , pair<int,int>>m;
    set<pair<int,int>,cmp>s;
public:
    TaskManager(vector<vector<int>>& tasks) {
        int n=tasks.size();
        for(int i=0; i<n; i++){
            int u=tasks[i][0];
            int t=tasks[i][1];
            int p=tasks[i][2];
            s.insert({p,t});
            m[t]={p,u};
        }
    }
    
    void add(int u, int t, int p) {
        s.insert({p,t});
        m[t]={p,u};
    }
    
    void edit(int t, int np) {
        s.erase({m[t].first,t});
        m[t].first=np;
        s.insert({np,t});
    }
    
    void rmv(int t) {
        s.erase({m[t].first,t});
        m.erase(t);
    }
    
    int execTop() {
        if(s.empty()) return -1;
        int t =s.begin()->second;
        int ans=m[t].second;
        m.erase(t);
        s.erase(s.begin());
        return ans;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */