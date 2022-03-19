// Method 1: Insertion sort techniques
// Given each element will lie only in left and right point within k position from current position.
// O(nk) = use insertion sort teachnique
// for each element search k element in left side and place in its position
// Method 2: Min-heap of size k O(NlogK)
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node {
   public:
    int data;
    Node *next, *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
Node* sortInsetion(Node* head, int k) {
    Node *temp = head, *curr;
    int m;
    while (temp) {
        m = k;
        curr = temp;
        while (curr->prev and curr->prev->data > curr->data and m--) {
            int val = curr->prev->data;
            curr->prev->data = curr->data;
            curr->data = val;
            curr = curr->prev;
        }
        temp = temp->next;
    }
    return head;
}
Node* sortHeap(Node* head, int k) {
    // create minheap of size k
    priority_queue<int, vector<int>, greater<int>> heap;
    Node* temp = head;
    Node* ans = head;
    int m = k + 1;
    while (temp and m--) {
        heap.push(temp->data);
        temp = temp->next;
    }
    // As 1st k-elements are inserted in heap
    // so start overwriting from start as this elements are not
    // useful anymore
    // keep pusing and popping
    while (temp) {
        int val = heap.top();
        heap.pop();
        // overwrite to list
        ans->data = val;
        ans = ans->next;
        heap.push(temp->data);
        temp = temp->next;
    }
    // remaining
    while (heap.size()) {
        int val = heap.top();
        heap.pop();
        // overwrite to list
        ans->data = val;
        ans = ans->next;
    }
    // as original list contains the sorted ans
    return head;
}

void push(Node** head_ref, int new_data) {
    // allocate node
    Node* new_node = (Node*)malloc(sizeof(Node));
    // put in the data
    new_node->data = new_data;
    // since we are adding at the beginning,
    // prev is always NULL
    new_node->prev = NULL;
    // link the old list off the new node
    new_node->next = (*head_ref);
    // change prev of head node to new node
    if ((*head_ref) != NULL) (*head_ref)->prev = new_node;
    // move the head to point to the new node
    (*head_ref) = new_node;
}

// Function to print nodes in a given doubly linked list
void printList(Node* head) {
    // if list is empty
    if (head == NULL)
        cout << "Doubly Linked list empty";
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

// Driver program to test above
int main() {
    Node* head = NULL;
    // Create the doubly linked list:
    // 3<->6<->2<->12<->56<->8
    push(&head, 8);
    push(&head, 56);
    push(&head, 12);
    push(&head, 2);
    push(&head, 6);
    push(&head, 3);
    int k = 2;
    cout << "Original Doubly linked list:\n";
    printList(head);
    // sort the biotonic DLL
    head = sortHeap(head, k);
    cout << "\nDoubly linked list after sorting:\n";
    printList(head);

    return 0;
}
