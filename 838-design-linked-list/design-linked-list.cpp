class MyLinkedList {
private:
    struct Node {
        int val;
        Node* prev;
        Node* next;
        Node(int v) : val(v), prev(nullptr), next(nullptr) {}
    };

    Node* head; // dummy head
    Node* tail; // dummy tail
    int size;

public:
    MyLinkedList() {
        head = new Node(-1);
        tail = new Node(-1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    // Helper: get node at index (0-based)
    Node* getNode(int index) {
        Node* curr;
        if (index < size / 2) {
            curr = head->next;
            for (int i = 0; i < index; i++) curr = curr->next;
        } else {
            curr = tail->prev;
            for (int i = size - 1; i > index; i--) curr = curr->prev;
        }
        return curr;
    }

    int get(int index) {
        if (index < 0 || index >= size) return -1;
        return getNode(index)->val;
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);
        Node* first = head->next;
        newNode->next = first;
        newNode->prev = head;
        head->next = newNode;
        first->prev = newNode;
        size++;
    }

    void addAtTail(int val) {
        Node* newNode = new Node(val);
        Node* last = tail->prev;
        newNode->prev = last;
        newNode->next = tail;
        last->next = newNode;
        tail->prev = newNode;
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index > size) return;
        if (index <= 0) {
            addAtHead(val);
            return;
        }
        if (index == size) {
            addAtTail(val);
            return;
        }
        Node* curr = getNode(index); // node currently at 'index'
        Node* newNode = new Node(val);
        Node* prevNode = curr->prev;

        newNode->prev = prevNode;
        newNode->next = curr;
        prevNode->next = newNode;
        curr->prev = newNode;
        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        Node* curr = getNode(index);
        Node* prevNode = curr->prev;
        Node* nextNode = curr->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        delete curr;
        size--;
    }

    ~MyLinkedList() {
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
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