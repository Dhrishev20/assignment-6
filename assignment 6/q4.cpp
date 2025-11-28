#include <iostream>

using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node* prev;

    Node(char val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};
bool isPalindrome(Node* head) {
    if (head == nullptr) {
        return true;
    }

    Node* left = head;
    Node* right = head;

    while (right->next != nullptr) {
        right = right->next;
    }

    while (left != right && left->prev != right) {
        if (left->data != right->data) {
            return false;
        }
        left = left->next;
        right = right->prev;
    }

    return true;
}
int main() {
    Node* n1 = new Node('L');
    Node* n2 = new Node('E');
    Node* n3 = new Node('V');
    Node* n4 = new Node('E');
    Node* n5 = new Node('L');

    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;
    n3->next = n4;
    n4->prev = n3;
    n4->next = n5;
    n5->prev = n4;

    Node* head1 = n1;

    cout << "Input: L <-> E <-> V <-> E <-> L" << endl;
    cout << "Output: " << (isPalindrome(head1) ? "True" : "False") << endl;

    Node* h1 = new Node('H');
    Node* h2 = new Node('E');
    Node* h3 = new Node('L');
    Node* h4 = new Node('L');
    Node* h5 = new Node('O');

    h1->next = h2;
    h2->prev = h1;
    h2->next = h3;
    h3->prev = h2;
    h3->next = h4;
    h4->prev = h3;
    h4->next = h5;
    h5->prev = h4;
    Node* head2 = h1;
    cout << "\nInput: H <-> E <-> L <-> L <-> O" << endl;
    cout << "Output: " << (isPalindrome(head2) ? "True" : "False") << endl;

    return 0;
}