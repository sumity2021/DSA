class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int h_len=hBars.size();
        int v_len=vBars.size();
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int max_h=0;
        int max_v=0;
        for(int i=0; i<h_len; i++){
            if(hBars[i]==1 || hBars[i]==n+2) continue;
            int cnt=0;
            int curr=hBars[i];
            while(i<h_len && hBars[i]==curr){
                cnt++;
                i++;
                curr++;
            }
            i--;
            max_h=max(max_h,cnt);
        }
        for(int i=0; i<v_len; i++){
            if(vBars[i]==1 || vBars[i]==m+2) continue;
            int cnt=0;
            int curr=vBars[i];
            while(i<v_len && vBars[i]==curr){
                cnt++;
                i++;
                curr++;
            }
            i--;
            max_v=max(max_v,cnt);
        }
        return (min(max_h,max_v)+1)*(min(max_h,max_v)+1);
    }
};