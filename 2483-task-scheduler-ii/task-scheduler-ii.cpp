class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int ,long long>m;
        int n=tasks.size();
        long long days=0;
        for(int i=0; i<n; i++){
            if(m.count(tasks[i])){
                long long diff=(m[tasks[i]]+space)-days;
                days+=(diff>0)? diff: 0;
                
            }
            days++;
            m[tasks[i]]=days;
        }
        return days;
    }
};