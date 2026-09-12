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
        if (!head || !head->next)
            return head;
        ListNode* h = head;
        int l = k;
        while (--l) {
            head = head->next;
            if (head == nullptr)
                return h;
        }
        ListNode* forward = head->next;
        ListNode* curr = h;
        ListNode* prev = nullptr;

        while (curr != forward) {
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        h->next = reverseKGroup(forward, k);
        return head;
    }
};