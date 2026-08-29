/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*,int> mp;
        ListNode *t=headA;
        int cnt = 0;
        while(t!=NULL){
            mp[t] = 1;
            t = t->next;
        }
        t = headB;
        while(t!=NULL){
            if(mp.find(t) != mp.end()) return t;
            t=t->next;
        }
        return NULL;
    }
};