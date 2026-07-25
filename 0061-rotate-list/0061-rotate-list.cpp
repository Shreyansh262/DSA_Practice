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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return nullptr;
        if (!head->next)
            return head;
        int c = 1;
        ListNode* temp = head;
        while (c <= k) {
            if (temp->next) {
                temp = temp->next;
            } else {
                k = k % c;
                temp = head;
            }
            c++;
        }
        if (k < c-1 && k > 0) {
            while (k--) {
                if (temp->next) {
                    temp = temp->next;
                } else {
                    temp = head;
                }
            }
        }
        ListNode* h2 = head;
        while (temp->next) {
            h2 = h2->next;
            temp = temp->next;
        }
        temp->next = head;
        ListNode* newhead = h2->next;
        h2->next = nullptr;
        return newhead;
    }
};