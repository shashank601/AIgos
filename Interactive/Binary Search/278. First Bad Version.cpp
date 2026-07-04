// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        int i = 1;
        int j = n - 1;

        int ans = n;

        while (i <= j) {

            int mid = i + (j - i)/2;

            int res = isBadVersion(mid);

            if (res) {
                j = mid - 1;
                ans = mid;

                // if (isBadVersion(mid - 1)) {

                // }
            } else {
                i = mid + 1;
            }
        }

        return ans;


    }
};
