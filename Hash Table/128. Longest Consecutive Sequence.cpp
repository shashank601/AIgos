class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;

        for (auto& num : nums) {
            st.insert(num);
        }        

        int ans = 0;
        for (auto& num : st) {            <-- iterate over set and not input (bcz of dups i got tle)
            if (!st.count(num - 1)) {
                int cnt = 1;
                int val = num;
                while (st.count(val + 1)) {
                    val += 1;
                    cnt++;
                }

                ans = max(cnt, ans);

            }
        }

        return ans;
    }
};
