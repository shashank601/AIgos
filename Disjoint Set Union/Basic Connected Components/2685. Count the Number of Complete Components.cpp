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
                rank[p1]++;
            }
        }


    }

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

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        parent.assign(n, -1);
        rank.assign(n, 0);

        for (auto& edge : edges) {
            Union(edge[0], edge[1]);
        }

        vector<int> nodes(n, 0);                         <--- use maps instead
        vector<int> edgesCount(n, 0);                      <--- same


        // for (auto& edge : edges) {
        //     int repr = find(edge[0]);                        <-- root is representative of coponents(we count node or edge per COMPONENETS) 
        //     nodes[repr] += 2;                                    <-- 2 edges doesnt mean 4 nodes eg. [1 0] [0 2]
        //     edgesCount[repr]++;
        // }

        // per componenet
        // num of nodes
        // num of edges

        for (int i = 0; i < n; i++) {
            int repr = find(i);
            nodes[repr]++;
        }



        for (auto& edge : edges) {
            int repr = find(edge[0]);
            edgesCount[repr]++;
        }            

        int complete = 0;

        for (int i = 0; i < n; i++) {
            if (nodes[i] == 0) continue;

            int k = nodes[i];
            int expected = k * (k - 1) / 2;

            if (edgesCount[i] == expected) {
                complete++;
            }
        }

        return complete;


    }
};


===
DSU is just a framework.
It tells you which nodes belong together.
Anything extra (counts, edges, size) → you store it yourself.


=====

Per component:

number of nodes = k
number of edges = e

DSU does NOT track this automatically.
So you track it.

===

Loop all nodes:

root = find(i)
count[root]++

Now:
count[root] = number of nodes in that component

===

Step 3: Count edges per component

Loop all edges:

root = find(u)
edgeCount[root]++

Important:
Each edge belongs to exactly one component
So just assign it to root

===

Because once nodes are grouped, you can:
aggregate anything per group

===

Wrong model:
DSU can’t track info

Correct model:
DSU gives grouping → I attach info to groups   PER rooot in some map
