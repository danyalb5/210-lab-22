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
int main() {
    srand(time(0));  // Randomize seed for random numbers
    DoublyLinkedList list;

    // Add some nodes to the list
    int size = rand() % 16 + 5;  // Random number between 5 and 20
    for (int i = 0; i < size; ++i) {
        list.push_back(rand() % 90 + 10);  // Push random integers between 10 and 99
    }

    cout << "Initial List forward: ";
    list.print();

    cout << "Initial List backward: ";
    list.print_reverse();

    // Test pop_front()
    cout << "\nPopping front...\n";
    list.pop_front();
    list.print();

    // Test pop_back()
    cout << "\nPopping back...\n";
    list.pop_back();
    list.print();

    // Test delete_val()
    cout << "\nDeleting value 50 if present...\n";
    list.delete_val(50);  // Attempt to delete the value 50
    list.print();

    // Test delete_pos()
    cout << "\nDeleting node at position 2...\n";
    list.delete_pos(2);  // Delete the node at position 2
    list.print();

    return 0;
}

