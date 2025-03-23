class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int m=queries.size();
        vector<int>diff(n+1);
        int k=0;
        int sum=0;
        for(int i=0; i<n; i++){
            while(sum+diff[i]<nums[i]){
                k++;
                if(k>queries.size()) return -1;
                int st=queries[k-1][0];
                int end=queries[k-1][1];
                int val=queries[k-1][2];
                if(end>=i){
                    diff[max(i,st)]+=val;
                    diff[end+1]-=val;
                }
            }
            sum+=diff[i];
        }
        return k;

    }
};