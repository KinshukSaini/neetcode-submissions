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
    bool hasCycle(ListNode* head) {
        ListNode* h = head;
        ListNode* t = head;
        bool cycle = false;
        while(h && t){
            if(!(t->next)) break;
            t = t->next->next;
            h = h->next;
            if(t == h){
                cycle = true;
                break;
            }
        }
        return cycle;
    }
};
