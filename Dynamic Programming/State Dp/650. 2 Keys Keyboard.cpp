1.
class Solution {
public:
    int g(int n, int len, int copy, auto& dp) {
        if (len >= n) {
            if (len == n) return 0;
            return INT_MAX;
        }
        if (dp[len][copy] != -1) return dp[len][copy];

        int a = INT_MAX, b = INT_MAX;
        if (len != copy) {
            a = g(n, len * 2, len, dp); // copy + paste imm
            if (a != INT_MAX) a++;
        }

        if (copy != 0) {
            b = g(n, len + copy, copy, dp); // paste
        }

        return dp[len][copy] = min(a, b) == INT_MAX ? INT_MAX : min(a, b) + 1;
    }
    int minSteps(int n) {
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return g(n, 1, 0, dp);
    }
};

====
2.
class Solution {
public:
    int g(int n, int len, int copy, auto& dp) {
        if (len >= n) {
            if (len == n) return 0;
            return INT_MAX;
        }
        if (dp[len][copy] != -1) return dp[len][copy];

        int a = INT_MAX, b = INT_MAX;
        if (len != copy) {
            a = g(n, len, len, dp); // copy
        }
        if (copy != 0) {

            b = g(n, len + copy, copy, dp); // paste
        }

        return dp[len][copy] = min(a, b) == INT_MAX ? INT_MAX : min(a, b) + 1;
    }
    int minSteps(int n) {
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return g(n, 1, 0, dp);
    }
};

====
both ways are shameful
its very ineff
more ineff then my recursive soln

3.
class Solution {
public:
    int ans;
    // t is what in the clipbord
    void g(int n, int i, int t, int cost) {
        if (n <= i) {
            if (n == i) ans = min(ans, cost);
            return;
        }
        
        
        g(n,i * 2, i, cost + 2);// copy paste
        if ( t > 0)
            g(n,i + t, t, cost + 1); // paste
    }
    int minSteps(int n) {
      ans = INT_MAX;
      g(n, 1, 0, 0);
      return ans;
    }
};

====
wow 
removing memo improved sc by 10x


4.
class Solution {
public:
    int g(int n, int len, int copy) {
        if (len >= n) {
            if (len == n) return 0;
            return INT_MAX;
        }
      

        int a = INT_MAX, b = INT_MAX;
        if (len != copy) {
            a = g(n, len, len); // copy
        }
        if (copy != 0) {
            b = g(n, len + copy, copy); // paste
        }

        return min(a, b) == INT_MAX ? INT_MAX : min(a, b) + 1;
    }
    int minSteps(int n) {
        return g(n, 1, 0);
    }
};
