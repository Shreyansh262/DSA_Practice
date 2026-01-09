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
    bool isPalindrome(ListNode* head) {
        stack<int> curr;
        ListNode* temp = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            curr.push(temp->val);
            temp = temp->next;
        }
        if (fast != nullptr)
            temp = temp->next;
        while (temp != nullptr) {
            if (temp->val == curr.top())
                curr.pop();
            else
                return false;
            temp = temp->next;
        }
        return true;
    }
};