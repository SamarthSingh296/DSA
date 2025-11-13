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
    ListNode* sortList(ListNode* head) {

        if (!head || !head->next) return head;

        // Step 1: Split list into two halves
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* mid = slow->next;
        slow->next = nullptr;

        // Step 2: Sort both halves
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);

        // Step 3: Merge them
        return merge(left, right);
    }

    ListNode* merge(ListNode* a, ListNode* b) {
        if (!a) return b;
        if (!b) return a;

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (a && b) {
            if (a->val < b->val) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }

        // Attach remaining
        tail->next = a ? a : b;
        return dummy.next;
    }
};
