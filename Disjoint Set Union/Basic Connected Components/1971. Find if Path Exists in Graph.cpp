class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int node) {                    <-- find is two phase
        int root = node;
        while (parent[root] != -1) {
            root = parent[root];
        }

        while (node != root) {
            int next = parent[node];
            parent[node] = root;          <-- set each node in the path to root
            node = next;
        }

        return root;
    }

    void Union(int node1, int node2) {
        int p1 = find(node1);
        int p2 = find(node2);

        if (p1 != p2) {
            if (rank[p1] < rank[p2]) {
                parent[p1] = p2;
            } else if (rank[p1] > rank[p2]) {
                parent[p2] = p1;
            } else {
                parent[p2] = p1;
                rank[p2]++;
            }
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        parent.assign(n, -1);
        rank.assign(n, 0);
        for (auto& edge : edges) {
            Union(edge[0], edge[1]);
        }

        int p1 = find(source);
        int p2 = find(destination);
        return p1 == p2;
    }
};
