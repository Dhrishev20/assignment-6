#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

void displayList(Node* head) {
    if (head == nullptr) {
        cout << "The list is empty." << endl;
        return;
    }

    Node* temp = head;

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << head->data << endl;
}

int main() {
    Node* head = new Node(20);
    head->next = new Node(100);
    head->next->next = new Node(40);
    head->next->next->next = new Node(80);
    head->next->next->next->next = new Node(60);
    
    head->next->next->next->next->next = head;

    cout << "Input: 20 -> 100 -> 40 -> 80 -> 60" << endl;
    
    cout << "Output: ";
    displayList(head);

    return 0;
}