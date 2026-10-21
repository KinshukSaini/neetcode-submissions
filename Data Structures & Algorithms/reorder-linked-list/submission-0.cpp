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
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        ListNode* temp = head;
        while(temp){
            st.push(temp);
            temp = temp->next;
        }
        ListNode* node = head;
        while(node && !st.empty()){
            if(node == st.top() || node->next == st.top()){
                break;
            }
            st.top()->next = node->next;
            node->next = st.top();
            node = st.top()->next;
            st.pop();
            st.top()->next = NULL;
        }
    }
};
