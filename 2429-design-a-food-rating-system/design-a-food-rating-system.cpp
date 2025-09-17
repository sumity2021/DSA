class FoodRatings {
    struct cmp {
        bool operator()(const pair<int,string>& a, const pair<int,string>& b) const {
            if (a.first != b.first) return a.first > b.first;   
            return a.second < b.second;                        
        }
    };
    unordered_map<string,set<pair<int,string>,cmp>>m1;
    unordered_map<string,pair<int,string>>m2;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=foods.size();
        for(int i=0; i<n; i++){
            string c=cuisines[i];
            string f=foods[i];
            int r=ratings[i];
            m1[c].insert({r,f});
            m2[f]={r,c};
        }
    }
    
    void changeRating(string food, int newRating) {
        auto [r,c]=m2[food];
        m1[c].erase({r,food});
        m2[food]={newRating,c};
        m1[c].insert({newRating,food});
    }
    
    string highestRated(string cuisine) {
        return m1[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */