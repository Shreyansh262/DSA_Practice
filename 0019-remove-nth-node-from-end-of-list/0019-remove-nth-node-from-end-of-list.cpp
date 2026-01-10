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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* front = dummy;
        ListNode* back = dummy;
        int c = 0;
        while(c<=n){
            front = front->next;
            c++;
        }
        while(front != nullptr){
            front = front->next;
            back = back->next;
        }
        ListNode* temp = back->next;
        back->next = temp->next;
        delete temp;
        return dummy -> next;
    }
};