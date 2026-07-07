class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in(numCourses, 0);
        vector<vector<int>> adj(numCourses);


        for (auto& edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);
            in[edge[0]]++;
        }


        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (in[i] == 0) q.push(i);
        }




        vector<int> ans;
        int n = 0;        
        while (!q.empty()) {
            int i = q.front(); q.pop();
            ans.push_back(i);
        
            for (auto neigh : adj[i]) {
                in[neigh]--;
                
                if (in[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }



        return ans.size() == numCourses ? ans : vector<int>(0); 
    }
};
