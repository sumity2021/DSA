class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int rem=1e9+7;
        vector<long long>powers;
        int num=1;
        while(n>=num){
            if(n&num) powers.push_back(num);
            num<<=1;
        }
        vector<int>ans;
        for(auto &q : queries){
            int st=q[0];
            int end=q[1];
            int curr=1;
            for(int i=st; i<=end; i++){
                curr=(powers[i]*curr)%rem;
            }
            ans.push_back(curr);
        }
        return ans;
    }
};