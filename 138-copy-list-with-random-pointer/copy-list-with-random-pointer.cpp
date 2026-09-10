/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    void insert(Node* head) {
        Node* temp = head;
        while (temp != NULL) {
            Node* newnode = new Node(temp->val);
            newnode->next = temp->next;
            temp->next = newnode;
            temp = temp->next->next;
        }
    }
    void copyRandoms(Node* head) {
        Node* temp = head;
        while (temp != NULL) {
        Node* copynode = temp->next;
            if (temp->random) {
                copynode->random = temp->random->next;
            } else {
                copynode->random = nullptr;
            }
            temp = temp->next->next;
        }
    }
    Node*getCopyList(Node*head){
        Node*dummy = new Node(-1);
        Node*res=dummy;
        Node*temp = head;
        while(temp!=NULL){
            res->next = temp->next;
            res=res->next;
            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dummy->next;
    }

public:
    Node* copyRandomList(Node* head) {
        insert(head);
        copyRandoms(head);
        return getCopyList(head);
    }
};