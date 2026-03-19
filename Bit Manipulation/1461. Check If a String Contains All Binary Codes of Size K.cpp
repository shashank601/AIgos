class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = (1 << k);
        vector<int> seen(n, false);

        int mask = n - 1; // if 1000 -> 0111

        int curr = 0;
        for (int i = 0; i < s.length(); i++) {
            curr = (curr << 1 | s[i] - '0') & mask; // num in  curr window of size k
            if (i - k + 1 >= 0) seen[curr] = true;    // vimp condn, so we can skip first invalid ssizes like 1 2 3 .. k - 1
        }

        for (int i = 0; i < n; i++) {   // dont need this we could use a counter which count is 1<<k cells been marked ? early return true
            if (!seen[i]) return false;
        }
        return true;

    }
};



curr << 1 → shift window
| new_bit → add current char
& mask → force it to stay k bits  (0000..00111 doing and with this will only keep first 3 lsb s)
