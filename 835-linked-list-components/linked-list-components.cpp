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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end());
        ListNode* temp= head;
        bool streak = false;
        int cnt = 0;
        while(temp!=NULL){
            if(s.count(temp->val) && streak == false){
                streak =true;
                cnt++;
            }
            else if(s.count(temp->val)==0 && streak == true) streak = false;
            temp = temp->next;
        }
        return cnt;
    }
};