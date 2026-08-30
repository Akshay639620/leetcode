class MyLinkedList {
public:
    class node {
    public:
        int val;
        node* next;

        node(int d) {
            val = d;
            next = NULL;
        }
        node(int d, node* next1) {
            val = d;
            next = next1;
        }
    };

    node* head;
    MyLinkedList() { head = NULL; }

    int get(int index) {
        if (index < 0)
            return -1;
        node* temp = head;
        while (index && temp!=NULL) {
            temp = temp->next;
            index--;
        }
        if (temp == NULL)
            return -1;
        return temp->val;
    }

    void addAtHead(int val) {
        node* newnode = new node(val);
        newnode->next = head;
        head = newnode;
    }

    void addAtTail(int val) {
        if (head == NULL) {
            head = new node(val);
            return;
        }
        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        node* newnode = new node(val);
        temp->next = newnode;
    }

    void addAtIndex(int index, int val) {
        if (index < 0)
            return;
        if (index == 0) {
            node* newnode = new node(val);
            newnode->next = head;
            head = newnode;
            return;
        }

        node* temp = head;
        while (index>1 && temp != NULL) {
            temp = temp->next;
            index--;
        }
        if (temp == NULL)
            return;
        else {
            node* newnode = new node(val);
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }

    void deleteAtIndex(int index) {
        if (head == NULL || index < 0)
            return;
        if (index == 0) {
            node* temp = head;
            head = head->next;
            delete(temp);
            return;
        }
        node* temp = head;
        node* prev = NULL;

        while (index && temp!=NULL) {
            prev = temp;
            temp = temp->next;
            index--;
        }
        if (temp == NULL)
            return;
        else {
            node* del = temp;
            prev->next = temp->next;
            delete (temp);
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */