class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int node) {
        int root = node;
        while (parent[root] != -1) {
            root = parent[root];
        }

        while(node != root) {            <--- not parent[node]  bcz of ub chances:   [ if parent[node] == -1   (!= root) ] => node will be -1  => p[-1] crash
            int next = parent[node];
            parent[node] = root;
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
            }
            else if (rank[p1] > rank[p2]) {
                parent[p2] = p1;
            }
            else {
                parent[p2] = p1;
                rank[p1]++;
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();
        parent.assign(n, -1);
        rank.assign(n, 0);

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (isConnected[r][c]) {
                    Union(r, c);
                }
            }
        }

        int cnt = 0;
        for (auto& node : parent) {
            if (node == -1) cnt++;
        }
        return cnt;
    }
};

===
tasks:
“connect a and b”
“are a and b in the same group?”

Naive Approach 1: DFS / BFS every time
Run DFS/BFS from u
Check if v is reachable

bad

===
optimizations:

| Problem time        | Fix              |
| ------------------- | ---------------- |
| While building tree | Union by rank    |   --> union()
| While querying tree | Path compression |   --> find()

====

Case analysis:
Case 1: unequal ranks: Attach smaller tree under bigger tree
→ Height does not increase                                      <---- no chnage in rank

Case 2: equal ranks:   Attach one under the other
→ Height increases by exactly 1                                  <--- +1

====
Rank is not exact height after path compression

====

ds: vetor<int> parent and vetcor<int> rank   
====
in dsu do we take graph nodes and intially make all of them independent then connect based on edges ?
ha!
===


Assume:
Tree A → height = 5
Tree B → height = 1

Case 1 (correct)
Attach smaller under larger:

A
|
B

Height stays ≈ 5
Case 2 (your “same thing” idea)
Attach larger under smaller:

B
|
A

Height becomes ≈ 6

oh! root is +1
