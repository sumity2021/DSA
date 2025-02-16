class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        long long ans=0;
        sort(pizzas.begin(),pizzas.end(),greater<int>());
        int n=pizzas.size();
        int k=n/4;
        int odd=(k+1)/2;
        int even=k-odd;
        for(int i=0; i<odd; i++){
            ans+=pizzas[i];
        }
        odd++;
        for(int i=0; i<even; i++){
            ans+=pizzas[odd+2*i];
        }
        return ans;
    }
};