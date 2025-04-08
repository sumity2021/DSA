class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<long long ,vector<long long>,greater<long long>>pq;
        int n=nums.size();
        long long ans=1;
        int mod=1e9 +7;
        for(int i=0; i<n; i++){
            pq.push(nums[i]);
        }
        while(k--){
            long long top=pq.top();
            pq.pop();
            pq.push(top+1);
        }
        while(!pq.empty()){
            long long top=pq.top();
            pq.pop();
            ans=(ans*top)%mod;
        }
        return ans;
    }
};