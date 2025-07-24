class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);
        int n = s.size();
        int mostfreq = 0;
        
        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
            if (freq[s[i] - 'a'] >= freq[mostfreq]) {
                mostfreq = s[i] - 'a';
            }
        }

        if (2 * freq[mostfreq] - 1 > n) return "";

        int i = 0;
        while (freq[mostfreq]) {
            s[i] = 'a' + mostfreq;
            i += 2;
            freq[mostfreq]--;
        }

        for (int j = 0; j < 26; j++) {
            while (freq[j]--) {
                if (i >= n) i = 1;
                s[i] = 'a' + j;
                i += 2;
            }
        }

        return s;
    }
};
