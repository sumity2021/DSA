class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n=target.size();
        int prev=0;
        int ans=0;
        for(int i=0; i<n; i++){
            if(prev<target[i]){
                ans+=abs(prev-target[i]);
            }
            prev=target[i];
        }
        return ans;
    }
};