class Solution {
public:
    void dfs(int node, auto& g, auto& vis) {
        vis[node] = 1;

        for (int i = 0; i < g.size(); i++) {
            if (g[node][i] && !vis[i]) 
                dfs(i, g, vis);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
    
        int n = isConnected.size();
        vector<int> vis(n, 0);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            cnt++;
            dfs(i, isConnected, vis);
        }

        return cnt;
    }
};
