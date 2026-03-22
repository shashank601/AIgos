class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int node) {
        int root = node;

        while (parent[root] != -1) {
            root = parent[root];
        }

        while (node != root ) {
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

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();

        parent.assign(n, -1);
        rank.assign(n, 0);

        for (auto& swap : allowedSwaps) {
            Union(swap[0], swap[1]);
        }

        unordered_map<int, vector<int>> comp;

        for (int i = 0; i < n; i++) {
            comp[find(i)].push_back(i);
        }

        int ans = 0;

        for (auto& [root, indexes] : comp) {       <--- each comps is set of idx that act like a highway (elements can move freely)

            unordered_map<int, int> freq;
            for (auto& idx : indexes) {
                freq[source[idx]]++;
            }

            for (auto& idx : indexes) {
                if (freq.count(target[idx]))
                    freq[target[idx]]--;
                
                if (!freq[target[idx]])
                    freq.erase(target[idx]);
            }

            for (auto& [k, f] : freq) {
                ans += f;
            }
        }
        
        return ans;        
    }
};


To minimize Hamming distance, you want as many elements in source to match target as possible.
The way to do that is to count frequencies of numbers in both source and target for that component.

you only need to consider one of the vectors for counting leftovers

Chatgpt style:
no need to remove keys just ensure they dont go negative 
in leftover calc ) will have no ipmcat
int ans = 0;

for (auto& [root, indexes] : comp) {
    unordered_map<int, int> freq;
    
    for (int idx : indexes) freq[source[idx]]++;  
    
    for (int idx : indexes) {
        if (freq[target[idx]] > 0) {
            freq[target[idx]]--;  
        }
    }
    
    for (auto& [val, count] : freq) {
        ans += count;
    }
}
===

locally swaps fails 
dsu is for global ordering

===

Non-root nodes’ rank is ignored
===
summarizing dsu:

dsu is not only about 
a and b connected or
connect a and b

we cant extract alot of infos from this parent vector and given input

like edge count or node count per components

dsu is about connectivity

once i connect relevant nodes i can measure any metric.
  
peace

===
