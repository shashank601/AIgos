class Solution {
public:

    bool g(int cand, vector<int>& weights, int days) {
        int load = 0;
        int trips = 1;
        for (auto& w : weights) {
            if (load + w <= cand) {
                load += w;
            } else {
                trips++;
                load = w;
            }

            if (days < trips) return false;
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int mn = *max_element(weights.begin(), weights.end());        <-- earlier i did weights[0] which was wrong, min a ship can ship is the wt of max element
        int mx = accumulate(weights.begin(), weights.end(), 0);

        int ans = INT_MAX;

        while (mn <= mx) {
            int mid = mn + (mx - mn)/2;
            
            bool res = g(mid, weights, days);

            if (res) {
                mx = mid - 1;
                ans = mid;             <-- only update ans if its valid (res == true)
            } else {
                mn = mid + 1;
            }
        }

        return ans;

    }
};
