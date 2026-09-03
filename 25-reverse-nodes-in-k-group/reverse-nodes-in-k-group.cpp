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
private:
    ListNode* findKthNode(ListNode* temp, int k) {
        k -= 1;
        while (temp != NULL && k > 0) {
            k--;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* reverse(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        while (temp != NULL) {
            ListNode* move = temp->next;
            temp->next = prev;
            prev = temp;
            temp = move;
        }
        return prev;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevnode = NULL;
        while (temp != NULL) {
            ListNode* kthnode = findKthNode(temp, k);
            if (kthnode == NULL) {
                if (prevnode) prevnode->next = temp;
                    break;
                
            }
            ListNode* nextnode = kthnode->next;
            kthnode->next = NULL;
            reverse(temp);
            if (temp == head) {
                head = kthnode;
            } else {
                prevnode->next = kthnode;
            }
            prevnode = temp;
            temp = nextnode;
        }
        return head;
    }
};