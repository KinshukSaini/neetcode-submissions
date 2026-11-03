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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        ListNode* head = new ListNode();
        ListNode* ptr = head;
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> q;
        
        for(int i = 0; i < k; i++){
            if(lists[i]) q.push({lists[i]->val, lists[i]});
        }

        while(!q.empty()){
            auto p = q.top();
            int val = p.first;
            ListNode* node = p.second;
            q.pop();
            ptr->next = node;
            ptr = ptr->next;
            if(node->next) q.push({node->next->val, node->next});
        }
        return head->next;
    }
};








