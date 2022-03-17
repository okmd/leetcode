// Given dll and N rotate left by N amount
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node {
   public:
    int data;
    Node *prev, *next;
    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};
Node* rotate(Node* head, int k) {
    // if empty or one node.
    if (!head or !head->next) return head;
    // rotate the list in group of k.
    Node *curr = head, *prev = NULL, *next;
    int m = k;
    while (m-- and curr) {
        next = curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
    }
    prev->prev = NULL;

    Node* other = rotate(curr, k);
    head->next = other;
    // if not the last element, if none then no need to change
    if (other) {
        other->prev = head;
    }
    return prev;
}

void insertAtHead(Node*& head, int data) {
    Node* n = new Node(data);
    if (head == NULL) {
        head = n;
        return;
    }
    n->next = head;
    head->prev = n;
    head = n;
    return;
}
void insertAtTail(Node*& head, int data) {
    if (head == NULL) {
        insertAtHead(head, data);
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    Node* n = new Node(data);
    temp->next = n;
    n->prev = temp;
    return;
}
void display(Node* head) {
    while (head != NULL) {
        cout << head->data << "-->";
        head = head->next;
    }
    cout << "NULL";
}

int main() {
    Node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    int n = 3;
    cout << "\nBefore Rotation : \n";
    display(head);
    head = rotate(head, n);
    cout << "\nAfter Rotation : \n";
    display(head);
    cout << "\n";

    return 0;
}