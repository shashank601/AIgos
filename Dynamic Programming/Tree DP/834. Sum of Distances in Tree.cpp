class Solution {
public:

    int g(vector<vector<int>>& adj, vector<int>& ans, auto& subtree, int parent, int root, int depth) {
        int count = 0;

        for (auto neigh : adj[root]) { 
            if (parent == neigh) continue;   
            count += g(adj, ans, subtree, root, neigh, depth + 1);
        }
        ans[0] += depth;
        subtree[root] = count + 1;
        return count + 1;
    }


    void f(vector<vector<int>>& adj, int parent, vector<int>& ans, int n, vector<int>& subtree, int root) {
        
        for (auto neigh : adj[root]) {
            if (neigh == parent) continue;
            ans[neigh] = ans[root] - subtree[neigh] + (n - subtree[neigh]); 
            f(adj, root, ans, n, subtree, neigh);
        }
    }


    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto pair : edges) {
            int l = pair[0];
            int r = pair[1];
            adj[l].push_back(r);
            adj[r].push_back(l);
        }

        vector<int> subtree(n);
        vector<int> ans(n);

        g(adj, ans, subtree, -1, 0, 0);
        f(adj, -1, ans, n, subtree, 0);

        return ans;
    }
};

/*
Input edges have no direction guarantee

So if you don’t add reverse edge:

connectivity depends on input order

traversal becomes incomplete
*/
===
typical task:
for every node u 
compute something assumin u is root

eg.
  sum of dist from u to all nodes
eg.
  num of nodes in subtree of u 
eg.
  dp value depending on children
===

q.
for every node u compute 
sum(dist(u,v)) for all v

run bfs/dfs trating u as a root
O(n^2)

---

insight:
when root moves 1->2
nodes in subtree of 2 becomes close +1                      <--- +1, -1  distance shifts systematically
node outside become further -1


                  when root moves across edge u->v

  nodes in v's subtree                    nodes outside that suubtree  
     -1                                             +1


===
when root moves across edge (u->v)

two grps form
  1) nodes in v's subtree
  2) nodes outside v's subtree (all other nodes)

so if we know 

subtree_size[v]
total_node

===

if ans[u] = sum of dist from u
and we move root u->v

ans[v] = ans[u] - 1 * subtree_size[v]  + 1 * (n - subtree_size[v])
====

algo:
two dfs passes

dfs1: calc subtree size  (post-order)  & ans[u]

dfs2: re root   ans[remianing] - ___ + ____









===
Q1
“Am I combining children values?”
→ Tree DP

Q2
“Am I jumping upward fast?”
→ Binary Lifting

Q3
“Do I need answer for every node as root?”
→ Re-rooting

  ====

Counterexample (small, concrete)

Take n = 5

Case 1: chain (worst shape)
0 - 1 - 2 - 3 - 4

Depths from root 0:

0, 1, 2, 3, 4

Sum = 0 + 1 + 2 + 3 + 4 = 10

Case 2: star (flat shape)
    1
    |
2 - 0 - 3
    |
    4

Depths from root 0:

0, 1, 1, 1, 1

Sum = 0 + 1 + 1 + 1 + 1 = 4
=====

Who you are (role)
What you can do (specific skills)
Proof (projects / systems built)
