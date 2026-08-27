class Solution {
public:
    int countTrapezoids(vector<vector<int>>& arr) {
        int mod=1e9+7;
        unordered_map<int,long long>m;
        int n=arr.size();
        for(auto &p : arr){
            m[p[1]]++;          // arr=(1,0),(2,0),(3,1)   --> map = {0,2},{1,1}
        }
        long long segsofar=0;
        int ans=0;
        for(auto& [y,c] : m){
            long long seg=(c*(c-1)/2)%mod;
            ans=(ans+segsofar*seg%mod)%mod;
            segsofar=(segsofar+seg)%mod;
        }
        return ans;
    }
};