class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    void Union(int node1, int node2) {
        int p1 = find(node1);
        int p2 = find(node2);
        if (p1 != p2) {
            if (rank[p1] > rank[p2]) {
                parent[p2] = p1;
            } else if (rank[p1] < rank[p2]) {
                parent[p1] = p2;
            } else {
                parent[p1] = p2;
                rank[p2]++;
            }
        }
    }

    int find(int node) {
        int root = node;
        while (parent[root] != -1) {
            root = parent[root];
        }

        while (root != node) {
            int next = parent[node];
            parent[node] = root;
            node = next;
        }
        return root;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.assign(n, -1);
        rank.assign(n, 0);

        for (auto& edge : edges) {
            Union(edge[0], edge[1]);
        }

        unordered_map<int, int> nodesCnt;

        for (int i = 0; i < n; i++) {
            int p = find(i);
            nodesCnt[p]++; 
        }
        
        long long ans = 0;
        long long remain = n;

        for (auto& [root, freq] : nodesCnt) {
            ans += freq * (remain - freq);
            remain -= freq;
        }
        return ans;

    }
};


====
  
Instead of:
count everything → divide later

Do:
count only once from the start

===

ub:
x * (n - x)
“This double counts pairs”

==

B cannot see A anymore
so (B, A) is impossible to count

===
Reducing n removes already-counted groups
→ so reverse pairs can’t happen


===
remaining = n
for size in sizes:
    ans += size * (remaining - size)
    remaining -= size

[a b c]
a => b, c
b => c  (not a)
c => empty   (not a, b)
  

====

Mathematical view (clean)
Instead of:

for every i:
    size[i] * (n - size[i])

You convert to:
for i:
    size[i] * sum(size[j]) where j > i
