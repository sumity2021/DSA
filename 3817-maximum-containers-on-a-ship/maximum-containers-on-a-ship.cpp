class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        int total=n*n;
        int weight=0;
        int ans=0;
        for(int i=0; i<total; i++){
            weight+=w;
            if(weight<=maxWeight){
                ans++;
            }
        }
        return ans;
    }
};