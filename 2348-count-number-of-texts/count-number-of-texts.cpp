class Solution {
public:
    int countTexts(string p) {
        int n = p.size();
        const int mod = 1e9 + 7;
        vector<long long> dp3(n+1, 0), dp4(n+1, 0);
        dp3[0] = dp4[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 3 && j <= i; j++) {
                dp3[i] = (dp3[i] + dp3[i-j]) % mod;
            }
            for (int j = 1; j <= 4 && j <= i; j++) {
                dp4[i] = (dp4[i] + dp4[i-j]) % mod;
            }
        }

        long long ans = 1;
        for (int i = 0; i < n; i++) {
            int cnt = 1;
            while (i < n-1 && p[i] == p[i+1]) {
                cnt++;
                i++;
            }
            if (p[i] == '7' || p[i] == '9')
                ans = (ans * dp4[cnt]) % mod;
            else
                ans = (ans * dp3[cnt]) % mod;
        }

        return ans;
    }
};
