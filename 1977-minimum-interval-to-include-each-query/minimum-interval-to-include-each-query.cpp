class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& A, vector<int>& queries) {
        vector<int>ans;
        unordered_map<int,int>m;
        vector<int>Q=queries;
        sort(Q.begin(),Q.end());
        sort(A.begin(),A.end());
        int i=0;
        int n=A.size();
        priority_queue<pair<int,int>>pq;
        for( int q : Q){
            while(i<n && q>=A[i][0]){
                int l=A[i][0];
                int r=A[i][1];
                pq.push({l-r-1,r});
                i++;
            }
            while( pq.size() && pq.top().second<q){
                pq.pop();
            }
            m[q]=pq.size()? -pq.top().first : -1;
        }
        for(int q : queries){
            ans.push_back(m[q]);
        }
        return ans;
    }
};