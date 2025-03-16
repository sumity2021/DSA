class Solution {
public:
    bool f(vector<int>& ranks, int cars, long long time){
        long long repaired=0;
        for(int i=0; i<ranks.size(); i++){
            repaired+=sqrt(time/ranks[i]);
            if(repaired>=cars) return true;
        }
        return false;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        sort(ranks.begin(),ranks.end());
        long long  r=(long long)ranks[0]*cars*cars;
        long long l=1;
        while(r>=l){
            long long mid=l+(r-l)/2;
            if(f(ranks,cars,mid)){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};