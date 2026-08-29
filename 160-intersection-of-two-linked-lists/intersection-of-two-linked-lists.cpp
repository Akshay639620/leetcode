/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* collison(ListNode* headA, ListNode* headB, int d) {
        while(d){
            d--;
            headB = headB->next;
        }
        while(headA !=NULL && headB !=NULL){
            if(headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }

public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* t1 = headA;
        ListNode* t2 = headB;
        int c1 = 0, c2 = 0;
        while (t1 != NULL) {
            c1++;
            t1 = t1->next;
        }
        while (t2 != NULL) {
            c2++;
            t2 = t2->next;
        }
        if (c1 < c2){
            return collison(headA, headB, c2 - c1);
        }
            return collison(headB, headA, c1 - c2);

    }
};