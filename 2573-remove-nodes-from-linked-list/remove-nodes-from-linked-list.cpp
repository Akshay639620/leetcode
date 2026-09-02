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
    ListNode* removeNodes(ListNode* head) {
        ListNode* temp = head;
        vector<ListNode*> v;
        while (temp != NULL) {
            while (!v.empty() && v.back()->val < temp->val) {
                v.pop_back();
            }
            v.push_back(temp);
            temp = temp->next;
        }
        for(int i =0; i<v.size()-1; i++){
            v[i]->next = v[i+1];
        }
        v.back()->next = NULL;
        return v[0];
    }
};