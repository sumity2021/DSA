class Solution {
public:
    bool solve(vector<int>&arr, int m, int k, int mid){
        int n=arr.size();
        int res=0;
        for(int i=0; i<n; i++){
            int cnt=0;
            while(i<n && arr[i]<=mid){
                cnt++;
                i++;
            }
            res+=cnt/k;
        }
        return res>=m;
    }
    int minDays(vector<int>& bloomday, int m, int k) {
        int n=bloomday.size();
        int start=0;
        int end=*max_element(bloomday.begin(),bloomday.end());
        if((long long) m*k>n) return -1;
        while(start<=end){
            int mid=(start+end)/2;
            if(solve(bloomday,m, k, mid)){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return start;
    }
};