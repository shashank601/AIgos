
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* node1, ListNode* node2) { // true means keep
            return node1->val > node2->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq;


        ListNode* ans = new ListNode();
        ListNode* copy = ans;

        for (auto& list : lists) {
            if (list) {
                pq.push(list); //
            }
        }        

        while (!pq.empty()) {
            ListNode* node = pq.top(); pq.pop();
            if (node->next) {  // node && node->next  <-- node check is redundant , we are not pushing null nodes
                pq.push(node->next);
            }
            // if (copy) {        node is not null,  copy is never null
                copy->next = node;
                copy = copy->next;
            // }
        }

        return ans->next;
    }
};


query:
i wanted to know what the issue in merging smallest list first and
keep doing it untill we have one fina list left.
i have read it somewhere it reduces the comparison cost by posponting longer list for end, 
why just brute with pq.

ans:
For evenly sized lists, “smallest-first” doesn’t matter much → PQ per-node merge is simpler.
For uneven lists, smallest-first significantly reduces total comparisons.

also in contraints:
0 <= lists[i].length <= 500
