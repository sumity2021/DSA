class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans;
        int half=n/2;
        for(int i=half; i>=1; i--){
            ans.push_back(-1*i);
        }
        if(n & 1) ans.push_back(0);
        for(int i=1; i<=half; i++){
            ans.push_back(i);
        }
        return ans;
    }
};