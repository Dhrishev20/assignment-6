#include <iostream>

using namespace std;
struct DoublyNode {
    int data;
    DoublyNode* next;
    DoublyNode* prev;
};

int getDoublySize(DoublyNode* head) {
    int count = 0;
    DoublyNode* temp = head;

    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}
struct CircularNode {
    int data;
    CircularNode* next;
};

int getCircularSize(CircularNode* head) {
    if (head == nullptr) {
        return 0;
    }

    int count = 0;
    CircularNode* temp = head;

    do {
        count++;
        temp = temp->next;
    } while (temp != head);

    return count;
}
int main() {
    
    cout << "--- Doubly Linked List Size ---" << endl;

    DoublyNode* d_node1 = new DoublyNode();
    d_node1->data = 10;
    DoublyNode* d_node2 = new DoublyNode();
    d_node2->data = 20;
    DoublyNode* d_node3 = new DoublyNode();
    d_node3->data = 30;

    d_node1->next = d_node2;
    d_node1->prev = nullptr;

    d_node2->next = d_node3;
    d_node2->prev = d_node1;

    d_node3->next = nullptr;
    d_node3->prev = d_node2;

    DoublyNode* doublyHead = d_node1;
    cout << "Size of the Doubly Linked List is: " << getDoublySize(doublyHead) << endl;

    cout << "\n--- Circular Linked List Size ---" << endl;

    CircularNode* c_node1 = new CircularNode();
    c_node1->data = 100;
    CircularNode* c_node2 = new CircularNode();
    c_node2->data = 200;

    c_node1->next = c_node2;
    c_node2->next = c_node1; // Make it circular

    CircularNode* circularHead = c_node1;
    cout << "Size of the Circular Linked List is: " << getCircularSize(circularHead) << endl;

    return 0;
}