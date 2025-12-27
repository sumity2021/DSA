class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        vector<int>freq(n,0);
        priority_queue<int , vector<int> , greater<int>>avail_rooms;
        priority_queue<vector<long long> , vector<vector<long long >> , greater<vector<long long >>>occupied;
        for(int i=0; i<n; i++){
            avail_rooms.push(i);
        }
        for(auto m : meetings){
            long long st=m[0];
            long long end=m[1];
            int room;
            while(!occupied.empty() && occupied.top()[0]<=st){
                avail_rooms.push(occupied.top()[1]);
                occupied.pop();
            }
            if(!avail_rooms.empty()){
                room=avail_rooms.top();
                avail_rooms.pop();
            }else{
                room=occupied.top()[1];
                end+=(occupied.top()[0]-st);
                occupied.pop();
            }
            freq[room]++;
            occupied.push({end,room});
        }
        int ans=0;
        for(int i=1; i<n; i++){
            if(freq[i]>freq[ans]) ans=i;
        }
        return ans;
    }
};