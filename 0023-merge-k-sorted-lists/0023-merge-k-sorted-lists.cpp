/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // Custom comparator for the min-heap
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // Min-heap: smallest value has highest priority
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Min-heap to store the current head of each list
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        // Push initial heads of all non-empty lists into the heap
        for (ListNode* node : lists) {
            if (node != nullptr) {
                pq.push(node);
            }
        }

        // Dummy head for the result linked list
        ListNode dummy(0);
        ListNode* tail = &dummy;

        // Extract the smallest node and push the next node of that list
        while (!pq.empty()) {
            ListNode* smallest = pq.top();
            pq.pop();

            tail->next = smallest;
            tail = tail->next;

            if (smallest->next != nullptr) {
                pq.push(smallest->next);
            }
        }

        return dummy.next;
    }
};