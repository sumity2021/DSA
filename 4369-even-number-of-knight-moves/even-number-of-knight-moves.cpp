class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        int manhattan_dist=abs(target[0]-start[0])+abs(target[1]-start[1]);
        return !(manhattan_dist&1);
    }
};