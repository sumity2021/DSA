class Solution {
public:
    vector<int> findLonely(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return arr;
        sort(arr.begin(),arr.end());
        vector<int>ans;
        if(arr[0]!=arr[1]-1 && arr[0]!=arr[1]){
            ans.push_back(arr[0]);
        }
        for(int i=1; i<n-1; i++){
            if(arr[i]!=arr[i-1] && arr[i]!=arr[i-1]+1 && arr[i]!=arr[i+1] && arr[i]!=arr[i+1]-1){
                ans.push_back(arr[i]);
            }
        }
        if(arr[n-1]!=arr[n-2] && arr[n-1]!=arr[n-2]+1){
            ans.push_back(arr[n-1]);
        }
        return ans;
    }
};