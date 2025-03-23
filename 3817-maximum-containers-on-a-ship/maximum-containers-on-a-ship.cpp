class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        int ans=maxWeight/w;
        return (ans<=n*n)? ans: n*n;
    }
};