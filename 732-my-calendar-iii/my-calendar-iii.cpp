class MyCalendarThree {
    map<int,int>m;
public:
    MyCalendarThree() {
    }
    
    int book(int start, int end) {
        m[start]++;
        m[end]--;
        int ans=0;
        int maxi=0;
        for(auto & [key,val]:m){
            maxi+=val;
            ans=max(maxi,ans);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */