class Solution {
public:

    bool dfs(auto& adj, int src, int destn, auto& vis) {
        if (src == destn) return true;

        for (auto neigh : adj[src]) {
            if (vis[neigh]) continue;
            vis[neigh] = true;
            if (dfs(adj, neigh, destn, vis))
                return true;
        }


        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        
        for (auto pair : edges) {
            int u = pair[0];
            int v = pair[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(n, false);
        vis[source] = true;

        return dfs(adj, source, destination, vis);

    }
};
