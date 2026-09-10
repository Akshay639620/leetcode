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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == NULL || head->next == NULL || left == right)
            return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* preleft = dummy;
        ListNode* currhead = head;
        int l = left;
        while (left > 1) {
            preleft = preleft->next;
            currhead = currhead->next;
            left--;
        }
        ListNode* prev = nullptr;
        ListNode* sublist = currhead;
        for (int i = 1; i <= right - l + 1; i++) {
            ListNode* move = currhead->next;
            currhead->next = prev;
            prev = currhead;
            currhead = move;
        }
        preleft->next = prev;
        sublist->next = currhead;
        return dummy->next;
    }
};