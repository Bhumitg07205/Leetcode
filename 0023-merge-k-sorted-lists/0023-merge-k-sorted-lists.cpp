class Solution {
    struct compare {
        bool operator()(const ListNode* l, const ListNode* r) {
            return l->val > r->val;
        }
    };
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        
        for (ListNode* list : lists) {
            if (list != nullptr) {
                pq.push(list);
            }
        }
        
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (!pq.empty()) {
            ListNode* top = pq.top();
            pq.pop();
            
            tail->next = top;
            tail = tail->next;
            
            if (top->next != nullptr) {
                pq.push(top->next);
            }
        }
        
        return dummy.next;
    }
};