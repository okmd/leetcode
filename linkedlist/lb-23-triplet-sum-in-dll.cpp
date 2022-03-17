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
vector<pair<int, int>> pairs(Node *head, Node *exclude, int req_sum) {
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
    while (temp and tail and temp != tail) {
        if (temp == exclude) {
            temp = temp->next;
            continue;
        }
        if (tail == exclude) {
            tail = tail->prev;
            continue;
        }
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
class Triplet {
   public:
    int a, b, c;
    Triplet(int A, int B, int C) {
        a = A;
        b = B;
        c = C;
    }
};
vector<Triplet> triplets(Node *head, int req_sum) {
    // dll is sorted
    vector<Triplet> ans;
    // if null or either 1 or two nodes only
    if (!head or !head->next or !head->next->next) return ans;
    // find tail
    // Node *tail = head;
    // while (tail->next) {
    //     tail = tail->next;
    // }
    // include each element in triplet and remove from dll to find pair
    Node *temp = head;
    while (temp) {
        vector<pair<int, int>> p_ans = pairs(head, temp, req_sum - temp->data);
        if (p_ans.size()) {
            // found pairs for current element
            for (auto p : p_ans) {
                ans.push_back(Triplet(temp->data, p.first, p.second));
            }
        }
        temp = temp->next;
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
    int x = 17;

    vector<Triplet> ans = triplets(head, x);
    if (ans.size() == 0) cout << "Not Found!";
    for (auto pr : ans) {
        cout << "(" << pr.a << ", " << pr.b << ", " << pr.c << ") ";
    }
    cout << endl;
    return 0;
}

// for each element find the pair sum
// i.e for ele = 1, req_sum 10
// when i include 1 then req_sum = 9 i.e find pairs having sum=9
// if pair exits then triplet exists else no triplet for given sum
// n*O(n) = O(n^2)
// if more than one pair exits then consider all for triplets