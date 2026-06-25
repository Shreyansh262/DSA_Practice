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
class compare {
public:
    bool operator()(ListNode* a, ListNode* b) { return (a->val > b->val); }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> store;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr) {
                store.push(lists[i]); 
            }
        }
        
        ListNode* head = new ListNode();
        ListNode* tail = head;
        while (!store.empty()) {
            ListNode* temp = store.top();
            store.pop();
            tail->next = temp;
            tail = tail->next;
            if (temp->next) {
                store.push(temp->next);
            }
        }
        head = head->next;
        return head;
    }
};