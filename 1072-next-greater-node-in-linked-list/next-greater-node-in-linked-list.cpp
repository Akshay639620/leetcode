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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        stack<int> s;
        ListNode* temp = head;
        while (temp != NULL) {
            ans.push_back(temp->val);
            temp = temp->next;
        }
        int n = ans.size();
        vector<int> nge(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && s.top() <= ans[i]) {
                s.pop();
            }
            if (!s.empty())
                nge[i] = s.top();
            s.push(ans[i]);
        }
        return nge;
    }
};