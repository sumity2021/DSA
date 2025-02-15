class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long >,greater<long long>>pq;
        for(auto it : nums){
            pq.push(it);
        }
        int ans=0;
        while(pq.top()<k && pq.size()>=2){
            long long x=pq.top();
            pq.pop();
            long long y=pq.top();
            pq.pop();
            long long num=2*x+y;
            pq.push(num);
            ans++;
        }
        return ans;
    }
};