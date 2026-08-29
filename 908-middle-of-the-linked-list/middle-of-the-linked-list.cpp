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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int middle;
        int n = 0;
        while (temp != NULL) {
            n++;
            temp = temp->next;
        }
        middle = n/2 + 1;
        temp = head;
        while(temp!=NULL){
            middle--;
            if((middle) == 0) break;
            temp = temp->next;
        }
        return temp;
    }
};