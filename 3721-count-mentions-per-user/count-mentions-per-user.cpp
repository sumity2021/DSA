class Solution {
    
public:
    vector<int> countMentions(int n, vector<vector<string>>& events) {
        vector<int>on_time(n,1);
        vector<int>res(n,0);
        int all=0;
        sort(events.begin(),events.end(),[](auto a , auto b){
            int x=stoi(a[1]);
            int y=stoi(b[1]);
            if(x==y) return a[0]>b[0];
            return x<y;
        });
        for(auto e : events){
            string me=e[0];
            int ts=stoi(e[1]);
            if(me=="MESSAGE"){
                if(e[2]=="ALL"){
                    all++;
                }else if(e[2]=="HERE"){
                    for(int i=0; i<n; i++){
                        
                        if(ts>=on_time[i]){
                            res[i]++;
                        }
                    }
                }else{
                    string ids=e[2];
                    for( char &ch : ids){
                        if(!isdigit(ch)){
                            ch=' ';
                        }
                    }
                    stringstream ss(ids);
                    int id;
                    while(ss>>id){
                        res[id]++;
                    }
                    
                }
            }else{
                on_time[stoi(e[2])]=ts+60;
            }

        }
        for(int i=0; i<n; i++){
            res[i]+=all;
        }
        return res;
    }
};