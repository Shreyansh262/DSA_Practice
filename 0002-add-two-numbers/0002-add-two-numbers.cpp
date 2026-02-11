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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* ans = new ListNode((temp1->val + temp2->val)%10);
        ListNode* temp = ans;
        int carry = (temp1->val + temp2->val)/10;
        while(temp1->next && temp2->next){
            temp1 = temp1->next;
            temp2 = temp2->next;
            temp -> next = new ListNode((temp1->val + temp2->val + carry)%10);
            carry = (temp1->val + temp2->val + carry)/10;
            temp = temp->next;
        }
        while(temp1->next){
            temp1 = temp1->next;
            temp -> next = new ListNode((temp1->val + carry)%10);
            carry = (temp1->val + carry)/10;
            temp = temp->next;
        }
        while(temp2->next){
            temp2 = temp2->next;
            temp -> next = new ListNode((temp2->val + carry)%10);
            carry = (temp2->val + carry)/10;
            temp = temp->next;
        }
        if(carry != 0) temp -> next = new ListNode(carry);
        return ans;
    }
};