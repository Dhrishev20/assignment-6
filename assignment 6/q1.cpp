#include <iostream>

using namespace std;

class DNode {
public:
    int data;
    DNode* next;
    DNode* prev;

    DNode(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    DNode* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int data) {
        DNode* newNode = new DNode(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int data) {
        DNode* newNode = new DNode(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        DNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertAfter(int key, int data) {
        DNode* temp = head;
        while (temp != nullptr && temp->data != key) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node with data " << key << " not found." << endl;
            return;
        }

        DNode* newNode = new DNode(data);
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next = newNode;

        if (newNode->next != nullptr) {
            newNode->next->prev = newNode;
        }
    }

    void insertBefore(int key, int data) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        if (head->data == key) {
            insertAtBeginning(data);
            return;
        }

        DNode* temp = head;
        while (temp != nullptr && temp->data != key) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node with data " << key << " not found." << endl;
            return;
        }

        DNode* newNode = new DNode(data);
        newNode->next = temp;
        newNode->prev = temp->prev;
        
        if (temp->prev != nullptr) {
            temp->prev->next = newNode;
        }
        temp->prev = newNode;
    }

    void deleteNode(int key) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        DNode* temp = head;
        while (temp != nullptr && temp->data != key) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node with data " << key << " not found." << endl;
            return;
        }

        if (temp == head) {
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
        } else {
            temp->prev->next = temp->next;
            if (temp->next != nullptr) {
                temp->next->prev = temp->prev;
            }
        }
        
        delete temp;
        cout << "Node with data " << key << " deleted." << endl;
    }

    void search(int key) {
        DNode* temp = head;
        int pos = 1;
        while (temp != nullptr) {
            if (temp->data == key) {
                cout << "Node with data " << key << " found at position " << pos << "." << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node with data " << key << " not found." << endl;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        DNode* temp = head;
        cout << "List (forward): NULL <-> ";
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

class CNode {
public:
    int data;
    CNode* next;

    CNode(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    CNode* last;

public:
    CircularLinkedList() {
        last = nullptr;
    }

    void insertAtBeginning(int data) {
        CNode* newNode = new CNode(data);
        if (last == nullptr) {
            last = newNode;
            last->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
        }
    }

    void insertAtEnd(int data) {
        CNode* newNode = new CNode(data);
        if (last == nullptr) {
            last = newNode;
            last->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
    }

    void insertAfter(int key, int data) {
        if (last == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        CNode* temp = last->next;
        do {
            if (temp->data == key) {
                CNode* newNode = new CNode(data);
                newNode->next = temp->next;
                temp->next = newNode;
                if (temp == last) {
                    last = newNode;
                }
                return;
            }
            temp = temp->next;
        } while (temp != last->next);

        cout << "Node with data " << key << " not found." << endl;
    }

    void insertBefore(int key, int data) {
        if (last == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        CNode* temp = last->next;
        CNode* prev = last;

        do {
            if (temp->data == key) {
                CNode* newNode = new CNode(data);
                newNode->next = temp;
                prev->next = newNode;
                if (temp == last->next) {
                    
                }
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != last->next);

        cout << "Node with data " << key << " not found." << endl;
    }

    void deleteNode(int key) {
        if (last == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        CNode* curr = last->next;
        CNode* prev = last;

        do {
            if (curr->data == key) {
                if (curr == last && curr->next == last) {
                    last = nullptr;
                } else if (curr == last->next) {
                    prev->next = curr->next;
                } else if (curr == last) {
                    prev->next = curr->next;
                    last = prev;
                } else {
                    prev->next = curr->next;
                }
                
                delete curr;
                cout << "Node with data " << key << " deleted." << endl;
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != last->next);

        cout << "Node with data " << key << " not found." << endl;
    }

    void search(int key) {
        if (last == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        CNode* temp = last->next;
        int pos = 1;
        do {
            if (temp->data == key) {
                cout << "Node with data " << key << " found at position " << pos << "." << endl;
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != last->next);

        cout << "Node with data " << key << " not found." << endl;
    }

    void display() {
        if (last == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        CNode* temp = last->next;
        cout << "List: -> ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != last->next);
        cout << "(back to " << temp->data << ")" << endl;
    }
};

void showDLLMenu(DoublyLinkedList& dll) {
    int choice, data, key;
    while (true) {
        cout << "\n--- Doubly Linked List Menu ---" << endl;
        cout << "1. Insertion" << endl;
        cout << "2. Deletion (by value)" << endl;
        cout << "3. Search (by value)" << endl;
        cout << "4. Display" << endl;
        cout << "5. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int insertChoice;
                cout << "\n--- Insertion Menu ---" << endl;
                cout << "1. As first node" << endl;
                cout << "2. As last node" << endl;
                cout << "3. After a specific node" << endl;
                cout << "4. Before a specific node" << endl;
                cout << "Enter your choice: ";
                cin >> insertChoice;
                cout << "Enter data to insert: ";
                cin >> data;

                switch (insertChoice) {
                    case 1:
                        dll.insertAtBeginning(data);
                        break;
                    case 2:
                        dll.insertAtEnd(data);
                        break;
                    case 3:
                        cout << "Enter data of node to insert after: ";
                        cin >> key;
                        dll.insertAfter(key, data);
                        break;
                    case 4:
                        cout << "Enter data of node to insert before: ";
                        cin >> key;
                        dll.insertBefore(key, data);
                        break;
                    default:
                        cout << "Invalid choice." << endl;
                }
                break;
            case 2:
                cout << "Enter data of node to delete: ";
                cin >> key;
                dll.deleteNode(key);
                break;
            case 3:
                cout << "Enter data of node to search: ";
                cin >> key;
                dll.search(key);
                break;
            case 4:
                dll.display();
                break;
            case 5:
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void showCLLMenu(CircularLinkedList& cll) {
    int choice, data, key;
    while (true) {
        cout << "\n--- Circular Linked List Menu ---" << endl;
        cout << "1. Insertion" << endl;
        cout << "2. Deletion (by value)" << endl;
        cout << "3. Search (by value)" << endl;
        cout << "4. Display" << endl;
        cout << "5. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int insertChoice;
                cout << "Insertion Menu " << endl;
                cout << "As first node" << endl;
                cout << "As last node" << endl;
                cout << "After a specific node" << endl;
                cout << "Before a specific node" << endl;
                cout << "Enter your choice: ";
                cin >> insertChoice;
                cout << "Enter data to insert: ";
                cin >> data;

                switch (insertChoice) {
                    case 1:
                        cll.insertAtBeginning(data);
                        break;
                    case 2:
                        cll.insertAtEnd(data);
                        break;
                    case 3:
                        cout << "Enter data of node to insert after: ";
                        cin >> key;
                        cll.insertAfter(key, data);
                        break;
                    case 4:
                        cout << "Enter data of node to insert before: ";
                        cin >> key;
                        cll.insertBefore(key, data);
                        break;
                    default:
                        cout << "Invalid choice." << endl;
                }
                break;
            case 2:
                cout << "Enter data of node to delete: ";
                cin >> key;
                cll.deleteNode(key);
                break;
            case 3:
                cout << "Enter data of node to search: ";
                cin >> key;
                cll.search(key);
                break;
            case 4:
                cll.display();
                break;
            case 5:
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;
    int choice;

    while (true) {
        cout << "Main Menu" << endl;
        cout << "Doubly Linked List Operations" << endl;
        cout << "Circular Linked List Operations" << endl;
        cout << "Exit" << endl;
        cout << "Enter your choice";
        cin >> choice;

        switch (choice) {
            case 1:
                showDLLMenu(dll);
                break;
            case 2:
                showCLLMenu(cll);
                break;
            case 3:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}