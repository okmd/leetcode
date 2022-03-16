#include <iostream>
#include <queue>
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
// custom comparator
class Comp {
   public:
    bool operator()(pair<int, Node *> p1, pair<int, Node *> p2) {
        return p1.first > p2.first;
    }
};

Node *merge(vector<Node *> lists) {
    Node *head = new Node(0);
    Node *temp = head;
    priority_queue<pair<int, Node *>, vector<pair<int, Node *>>, Comp> heap;  // min heap
    // push each list head in heap
    for (int i = 0; i < lists.size(); i++) {
        // atleast one node is present in each list : assumed
        heap.push({lists[i]->data, lists[i]});
    }
    // now each node as per value and merge to list
    while (!heap.empty()) {
        pair<int, Node *> top = heap.top();
        heap.pop();
        temp->next = new Node(top.first);
        temp = temp->next;
        Node *node = top.second->next;
        if (node) {
            heap.push({node->data, node});
        }
    }
    // node point to dummy node
    // so original list is
    return head->next;
}

int main() {
    // 1-2-3
    // 3-5-7
    // 1-2-3-3-5-7
    Node *l1 = new Node(1);
    l1->next = new Node(2);
    l1->next->next = new Node(300);
    Node *l2 = new Node(3);
    l2->next = new Node(5);
    l2->next->next = new Node(7);
    vector<Node *> lists = {l1, l2};
    Node *mr = merge(lists);
    Node *temp = mr;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}
