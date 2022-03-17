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
    // find size of list and roate only k%n times.
    Node *temp = head, *tail;
    int n = 0;
    while (temp) {
        tail = temp;
        temp = temp->next;
        n++;
    }
    k = k % n;
    if (k == 0) return head;
    // i.e n=5, k=5 k%n=0;
    // n=5, k=1 then 1%5 = 1
    // n=5, k=20 then k%n = 0
    temp = head;
    while (--k > 0) {
        temp = temp->next;
    }
    temp->next->prev = NULL;
    head->prev = tail;
    tail->next = head;
    head = temp->next;
    temp->next = NULL;

    return head;
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
    cout << "NULL\n";
}

int main() {
    Node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);

    int n = 21;
    cout << "\nBefore Rotation : \n";
    display(head);
    head = rotate(head, n);
    cout << "\nAfter Rotation : \n";
    display(head);
    cout << "\n\n";

    return 0;
}