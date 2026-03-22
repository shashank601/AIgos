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
                rank[p1]++;
            }
        }
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        

        int n = s.size();
        
        parent.assign(n, -1);
        rank.assign(n, 0);

        for (auto& pair : pairs) {
            Union(pair[0], pair[1]);
        }

        unordered_map<int, vector<int>> comp;

        for (int i = 0; i < n; i++) {
            comp[find(i)].push_back(i);
        }

        for (auto& [root, indexes] : comp) {
            vector<char> letters;
            for (auto& idx : indexes ) {
                letters.push_back(s[idx]);
            }

            sort(letters.begin(), letters.end());
            sort(indexes.begin(), indexes.end());
            int i = 0;
            for (auto& idx : indexes) {
                s[idx] = letters[i++];
            }

        }
        return s;



    }
};

===

greedy fails
Swaps can interact. One swap may prevent a future swap that would give a better overall order.
===


the idea is 

make component of indixes => all indexes that are indirectly connected forms a componennt

now we take out all idx of a component  
take out chars in a temp vector

once done just sort idx and letters and re-place them at new idxes.

in this way we will sort globally
(greedy was considering only local swaps, not the consequences)
===

  
