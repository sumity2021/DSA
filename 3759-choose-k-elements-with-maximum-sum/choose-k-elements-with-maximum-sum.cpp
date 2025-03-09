class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<long long>ans(n,0);
        vector<pair<int,pair<int,int>>>temp;
        for(int i=0; i<n; i++){
            temp.push_back({nums1[i],{i,nums2[i]}});
        }
        sort(temp.begin(),temp.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        long long sum=0;
        
        for(int i=1; i<n; i++){
            sum+=temp[i-1].second.second;
            pq.push(temp[i-1].second.second);
            if(pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }
            if(temp[i-1].first==temp[i].first){
                ans[temp[i].second.first]=ans[temp[i-1].second.first];
                continue;
            }
            ans[temp[i].second.first]=sum;
        }
        return ans;
    }
};