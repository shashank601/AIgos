class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> res;
        res.reserve(queries.size());
        vector<int> pref(arr.size());
        pref[0] = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            pref[i] =  pref[i - 1] ^ arr[i];
        }


        for (auto q : queries) {
            int l = q[0];
            int r = q[1];

            int ans = l - 1 >= 0 ? pref[r] ^ pref[l - 1] : pref[r];
            res.push_back(ans);;
        }

        return res;
    }
};
