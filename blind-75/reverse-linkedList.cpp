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
    ListNode* reverseList(ListNode* head) {
        stack<ListNode*> st;
        ListNode* cur = head;
        if(!head || !head->next) return head;

        while(head){
            st.push(head);
            head = head->next;
        }

        ListNode* newHead = st.top();
        st.pop();
        cur = newHead;
        while(!st.empty()){
            cur->next = st.top();
            st.pop();
            cur = cur->next;
        }
        cur->next = nullptr;
        return newHead;
    }
};
