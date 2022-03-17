// Given sum
// find pairs of elements in dll which sum to given sum.
// without using extra space
// When the DLL is sorted
#include <iostream>
#include <string>
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
vector<pair<int, int>> pairs(Node *head, int req_sum) {
    vector<pair<int, int>> ans;
    // no node or single node
    if (!head or !head->prev and !head->next) return ans;
    // ateast two nodes are present
    // use to pointer technique
    // when sum<required sum move right, include greater value
    // else move left i.e remove large value to reduce sum
    // find end of list
    Node *tail = head;
    while (tail->next) {
        tail = tail->next;
    }
    Node *temp = head;
    while (temp != tail) {
        if (temp->data + tail->data == req_sum) {
            ans.push_back({temp->data, tail->data});
            temp = temp->next;
            tail = tail->prev;
        } else if (temp->data + tail->data < req_sum) {
            temp = temp->next;
        } else {
            tail = tail->prev;
        }
    }
    return ans;
}
// helper code
void insert(Node **head, int data) {
    Node *temp = new Node(data);
    if (!(*head))
        (*head) = temp;
    else {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}

// Driver program
int main() {
    Node *head = NULL;
    insert(&head, 9);
    insert(&head, 8);
    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 2);
    insert(&head, 1);
    int x = 10;

    vector<pair<int, int>> ans = pairs(head, x);
    if (ans.size() == 0) cout << "Not Found!";
    for (auto pr : ans) {
        cout << "(" << pr.first << ", " << pr.second << ") ";
    }
    cout << endl;
    return 0;
}
