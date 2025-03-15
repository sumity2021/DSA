class Solution {
public:
    bool f(vector<int>&dist,double hour, int speed){
        double time_taken=0;
        for(int i=0; i<dist.size(); i++){
            time_taken=ceil(time_taken);
            time_taken+=(double)dist[i]/speed;
        }
        return time_taken<=hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if(hour<=dist.size()-1) return -1;
        int l=1;
        int r=1e7;
        while(l<=r){
            int mid=(l+r)/2;
            if(f(dist,hour,mid)){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return l;

    }
};