#include <iostream>
using namespace std;

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
        Node(int val, Node* p = nullptr, Node* n = nullptr) {
            data = val;
            prev = p;
            next = n;
        }
    };
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Renamed delete_node to delete_val
    void delete_val(int value) {
        if (!head) return; // Empty list
        Node* temp = head;
        while (temp && temp->data != value)
            temp = temp->next;
        if (!temp) return; // Value not found
        if (temp->prev) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next; // Deleting the head
        }
        if (temp->next) {
            temp->next->prev = temp->prev;
        } else {
            tail = temp->prev; // Deleting the tail
        }
        delete temp;
    }
};
void delete_pos(int position) {
    if (position < 0 || !head) {
        cout << "Invalid position or empty list." << endl;
        return;
    }

    Node* temp = head;
    for (int i = 0; temp != nullptr && i < position; ++i) {
        temp = temp->next;
    }

    if (!temp) {
        cout << "Position exceeds list size." << endl;
        return;
    }

    if (temp->prev) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;  // Deleting the head
    }

    if (temp->next) {
        temp->next->prev = temp->prev;
    } else {
        tail = temp->prev;  // Deleting the tail
    }

    delete temp;
}
void pop_front() {
    if (!head) return; // List is empty
    Node* temp = head;
    head = head->next;
    if (head) {
        head->prev = nullptr;
    } else {
        tail = nullptr; // If head becomes nullptr, tail must also be nullptr
    }
    delete temp;
}

void pop_back() {
    if (!tail) return; // List is empty
    Node* temp = tail;
    tail = tail->prev;
    if (tail) {
        tail->next = nullptr;
    } else {
        head = nullptr; // If tail becomes nullptr, head must also be nullptr
    }
    delete temp;
}

