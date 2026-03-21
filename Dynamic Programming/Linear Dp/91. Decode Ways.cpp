class Solution {
public:
    /*
    dp[]


    */
    vector<int> dp;
    int g(string s, int idx) {
        if (idx == s.length()) return 1;
        if (dp[idx] != -1) return dp[idx];

        int count = 0;


        if (s[idx] != '0') {
            count += g(s, idx + 1);
        }

        if (idx + 1 < s.length() && s[idx] != '0') {
            int val = (s[idx] - '0') * 10 + (s[idx + 1] - '0');

            if (0 < val and val < 27) {
                count += g(s, idx + 2);
            }
        }
        // s[idx] != 0 && idx + 1 < s.length()

        return dp[idx] = count;
    }

    int numDecodings(string s) {
        dp.assign(s.length(), -1);
        return g(s, 0);
    }
};

[ Time taken: 19m 21s ] <--- dont just try to fit it in known pattern try to reason to save time, every choice dp  is not take/skip
