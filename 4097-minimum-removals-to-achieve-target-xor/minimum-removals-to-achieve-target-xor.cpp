class Solution {
    
    int f(int idx ,vector<int>&nums,int target,unordered_map<string,int>&m){
        if(idx<0){
            return (target==0)? 0 : -1e9;
        }
        string state=to_string(idx)+"#"+to_string(target);
        if(m.count(state)){
            return m[state];
        }
        int take=1+f(idx-1,nums,target^nums[idx],m);
        int notake=f(idx-1,nums,target,m);
        return m[state]=max(take,notake);
        
    }
public:
    int minRemovals(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<string,int>m;
        int longest_xor=f(n-1,nums,target,m);
        if(longest_xor<0) return -1;
        return n-longest_xor;
    }
};