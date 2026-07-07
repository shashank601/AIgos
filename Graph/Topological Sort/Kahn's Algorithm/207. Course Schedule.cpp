class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in(numCourses);

        vector<vector<int>> adj(numCourses);

        for (auto edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);
            in[edge[0]]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (in[i] == 0) {
                q.push(i);                            <-- if graph is one cycle,  in degree of all nodes will be 1, q will be empety
            }
        }

        int cnt = 0;

        while (!q.empty()) {
            int i = q.front(); q.pop();
            cnt++;

            for (auto neigh : adj[i]) {
                in[neigh]--;
                if (in[neigh] == 0) q.push(neigh);
            }
        }

        return numCourses == cnt;

        // for (int i = 0; i < numCourses; i++) {         <-- remove this unnecessary scan by using cnt
        //     if (in[i] != 0) {
        //         return false;
        //     } 
        // }
        // return true;


        // return q.empty();      <-- useless bcz eventually queue will be empty



    }
};

=========


count == numCourses → no cycle.
count < numCourses → cycle exists.
