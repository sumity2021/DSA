class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        stack<int>st;
        int n=nums.size();
        vector<int>left(n,-1);
        vector<int>right(n,n);
        
        for(int i=0; i<n; i++){
            while(!st.empty() && nums[i]>=nums[st.top()]){
                st.pop();
            }
            if(!st.empty()) left[i]=st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && nums[i]>=nums[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                right[i]=st.top();
            }
            st.push(i);
        }

        long long result=0;
        for(int i=0; i<n; i++){
            if(left[i]!=-1 && right[i]!=n) result++;
        }
        return result;
        
    }
};