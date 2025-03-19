class Solution {
public:
    bool check(string a, string b){
        bitset<26>bs;
        for(auto it : a){
            bs.set(it-'a');
        }
        bitset<26>bs2;
        for(auto it : b){
            if(bs2.test(it-'a')) return 0;
            bs2.set(it-'a');
            if(bs.test(it-'a')==1) return 0;
        }
        return 1;
    }
    int dfs(vector<string>& arr,string & s, int i){
        if(i==arr.size()){
            return 0;
        }
        int take=0,notake=0;
        if(check(s,arr[i])){
            string str=s+arr[i];
            take=arr[i].size() + dfs(arr,str,i+1);
        }
        notake=dfs(arr,s,i+1);
        return max(take,notake);
        
    }
    int maxLength(vector<string>& arr) {
        
        string s="";
        return dfs(arr,s,0);
    }
};