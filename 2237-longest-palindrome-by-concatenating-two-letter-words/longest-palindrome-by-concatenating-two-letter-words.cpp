class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> m;
        for (auto &w : words) m[w]++;

        int pal = 0;
        bool centerUsed = false;

        for (auto &[word, count] : m) {
            string rev = word;
            swap(rev[0], rev[1]);

            if (word == rev) {  
                pal += (count / 2) * 4; 
                if (count % 2 == 1) centerUsed = true; 
            } 
            else if (m.count(rev)) {  
                int pairs = min(count, m[rev]);
                pal += pairs * 4;
                m.erase(rev);
            }
        }

        if (centerUsed) pal += 2; 

        return pal;
    }
};
