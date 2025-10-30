class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        int m=bank[0].size();
        int prev=0;
        int ans=0;
        for(int i=0; i<n; i++){
            int lasers=0;
            cout<<prev<<'\n';
            for(int j=0; j<m; j++){
                if(bank[i][j]=='1'){
                    ans+=prev;
                    lasers++;
                }
            }
            if(lasers!=0){
                prev=lasers;
            }
        }
        return ans;
    }
};