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

bool isCircular(Node* head) {
    if (head == nullptr) {
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}

int main() {
    Node* n1 = new Node(2);
    Node* n2 = new Node(4);
    Node* n3 = new Node(6);
    Node* n4 = new Node(7);
    Node* n5 = new Node(5);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n1; 

    Node* head1 = n1;

    cout << "Input: 2->4->6->7->5 (Circular)" << endl;
    cout << "Output: " << (isCircular(head1) ? "True" : "False") << endl;

    Node* h1 = new Node(10);
    Node* h2 = new Node(20);
    Node* h3 = new Node(30);

    h1->next = h2;
    h2->next = h3;

    Node* head2 = h1;

    cout << "\nInput: 10->20->30 " << endl;
    cout << "Output: " << (isCircular(head2) ? "True" : "False") << endl;

    return 0;
}