class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int i=0;
        int j=costs.size()-1;
        long long sum=0;
        priority_queue<int,vector<int>,greater<int>>pq1;
        priority_queue<int,vector<int>,greater<int>>pq2;
        while(i<candidates) pq1.push(costs[i++]); 
        while(j>=i && candidates) {pq2.push(costs[j--]); candidates--;}
        while(k--){
            if(pq2.empty() ||(!pq1.empty() && pq1.top()<=pq2.top())){
                sum+=pq1.top();
                pq1.pop();
                if(i<=j){
                    pq1.push(costs[i++]);
                }
            }else{
                sum+=pq2.top();
                pq2.pop();
                if(i<=j){
                    pq2.push(costs[j--]);
                }
            }
        }
        return sum;
    }
};