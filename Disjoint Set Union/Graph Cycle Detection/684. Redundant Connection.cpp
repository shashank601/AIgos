class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int node) {   // didnt returns -1
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
    
    void Union(int node1, int node2) {
        int p1 = find(node1);
        int p2 = find(node2);
        if (p1 != p2) {
            if (rank[p1] < rank[p2]) {
                parent[p1] = p2;
            } else if (rank[p2] < rank[p1]) {
                parent[p2] = p1;
            } else {
                parent[p2] = p1;
                rank[p1]++;
            }
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.assign(n + 1, -1);
        parent[0] = INT_MIN;    
        
        rank.assign(n + 1, 0);   
        rank[0] = INT_MIN;    


        for (auto& edge : edges) {
            int p1 = find(edge[0]);
            int p2 = find(edge[1]);


            if (p1 == p2) {
                return edge;  // not p1 p2
            } else {
                Union(p1, p2);
            }
        }
        return {};

    }
};


===

one node conn. but other not conn  => union() will add a node to that comp.
both node are independent yet  => 2 comp, union() will make 1 comp, not join to any other comp
both have same parent(this case) => union() will do nothing but since this is an unprocessed edge it  means  cycle`s last edge of input. all prev edges of cycle already processed 
  
====
You add edges one by one.
At some point, an edge connects
two nodes that are already indirectly connected.

Example:
1—2
2—3
  
Now add: 1—3
  
There is already a path: 1 → 2 → 3
So adding (1,3) creates a cycle.


Cycle happens when:
two nodes already belong to same connected component  <-- new edge but its nodes are already connected somehow so this edge will make a cycle if added to  the componenet



====
  
how to quickly check if two nodes are already connected?

if find(u) == find(v)
→ already connected
→ adding edge creates cycle


===
Cycle detection rule
if find(u) == find(v)
    → cycle detected
else
    → union(u, v)


=====

Step-by-step example
Edges:
[1,2], [2,3], [1,3]

Step 1: (1,2)
find(1)=1, find(2)=2 → different
→ union → component: {1,2}

Step 2: (2,3)
find(2)=1, find(3)=3 → different
→ union → component: {1,2,3}

Step 3: (1,3)
find(1)=1, find(3)=1 → same
→ cycle detected

===

Different roots → safe to connect  
Same root → cycle

====

Only edges inside the cycle can ever trigger:
find(u) == find(v)

===

Forget DSU for a second

You are doing this:
for (edges in order) {
    if (this edge makes a cycle) {
        ans = edge;
    }
}

Does this edge create a cycle?

===

  
If only one cycle → one detection → returned     (our problem )
If multiple cycles → overwrite → last returned         if multiple cycle change code instead of early return overwrite an "ans" edge 

===
  
unprocessed edge
having same parent
implies cycle.

===

our code only catches last edge of input 
