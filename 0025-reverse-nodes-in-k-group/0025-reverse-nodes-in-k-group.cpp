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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        // Count the length of the sublist
        int length = 0;
        ListNode* current = head;
        while (current) {
            length++;
            current = current->next;
        }

        // If length is less than k, no need to reverse, return head
        if (length < k) return head;

        // Reverse k nodes starting from head
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        current = head;
        int count = 0;

        while (current && count < k) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }

        if (next) {
            head->next = reverseKGroup(next, k);
        }

        // 'prev' is now the head of the reversed sublist
        return prev;
    }
};