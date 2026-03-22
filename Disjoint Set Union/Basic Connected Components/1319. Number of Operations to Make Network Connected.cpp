class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int node) {
        int root = node;

        while (parent[root] != -1) {
            root = parent[root];
        }

        while (node != root) {
            int next = parent[node];
            parent[node] = root;
            node = next;
        }
        return root;
    }

    void unite(int node1, int node2) {
        int p1 = find(node1);
        int p2 = find(node2);

        if (p1 != p2) {
            if (rank[p1] < rank[p2]) {
                parent[p1] = p2;
            } else if (rank[p1] > rank[p2]) {
                parent[p2] = p1;
            } else {
                parent[p2] = p1;
                rank[p1]++;
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int sz = connections.size();
        if (n - 1  > sz) return -1;
        
        parent.assign(n, -1);
        rank.assign(n, 0);

        for (auto& connection : connections) {
            unite(connection[0], connection[1]);
        }

        int count = 0;
        for (auto& root : parent) {
            if (root == -1)
                count++;
        }

        return count - 1;
        
    }
};
