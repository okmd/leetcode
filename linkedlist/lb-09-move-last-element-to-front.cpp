// 1->2->3->4->5
// 5->1->2->3->4
#include <iostream>
#include <vector>
using namespace std;

class Node {
   public:
    int data;
    Node *next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

Node *move(Node *root) {
    if (!root) return NULL;
    if (!root->next) return root;
    Node *temp = root, *prev = NULL;
    while (temp and temp->next) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    // insert temp at head
    temp->next = root;
    root = temp;
    return root;
}

int main() {
    Node *start = new Node(1);
    start->next = new Node(2);
    start->next->next = new Node(3);
    start->next->next->next = new Node(4);
    start->next->next->next->next = new Node(5);
    /* The constructed linked list is:
    1->2->3->4->5 */

    start = move(start);
    while (start) {
        cout << start->data << " ";
        start = start->next;
    }
    cout << endl;

    return 0;
}