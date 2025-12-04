class Solution {
public:
    int countCollisions(string directions) {
        int n=directions.size();
        stack<char>st;
        int ans=0;
        for(char d :directions){
            if(st.empty()){
                st.push(d);
                continue;
            }
            if(st.top()=='S' && d=='L'){
                ans++;
                
            }
            else if(d=='L' && st.top()=='R'){
                ans+=2;
                st.pop();
                while(!st.empty() && st.top()=='R'){
                    ans++;
                    st.pop();
                }
                st.push('S');
            }
            else if(d=='S'){
                while(!st.empty() && st.top()=='R'){
                    ans++;
                    st.pop();
                }
                st.push('S');

            }
            else{
                st.push(d);
            }
            
        }
        return ans;
    }
};