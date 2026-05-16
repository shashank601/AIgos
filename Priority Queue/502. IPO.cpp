class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

        int n = capital.size();
        vector<pair<int,int>> join;
        for (int i = 0; i < n; i++) {
            join.push_back({capital[i], profits[i]});
        }

        sort(join.begin(), join.end());    <-- this data structure maintains project that are currently in reach(curr avl proj) |separatbed by sep| future locked project may unlock as w inc (sep will move forward and stand at idx that is > w) 
        int sep = 0;

        priority_queue<int> pq;

        while (k--) {

            while (sep < n && join[sep].first <= w){             <-- push unlocked project 
                pq.push(join[sep].second);
                sep++;
            }

            if (pq.empty()) break;   <-- check
            w += pq.top();
            pq.pop();
        }


        return w;
    }
};


====
pq holds unlocked projects not every single project

and on every w inc 
we try pushing new available projects
