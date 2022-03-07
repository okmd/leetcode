// Idea deletion can;t be done in arrays in o(1) time.
// can not go back in singly linked list when element is deleted.
// so doubly linked list must be used.
// maintain a middle pointer and change the ponter when the element is deleted or added.

#include <iostream>
using namespace std;

class Node {
   public:
    int data;
    Node *left, *right;
    Node(int val = 0) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
// Assuming right node to be mid when size is even.
class Stack {
   public:
    Node *mid, *top;
    int size;
    Stack() {
        top = NULL;
        mid == NULL;
        size = 0;
    }
    void push(int val) {
        Node *temp = new Node(val);
        if (size == 0) {
            top = temp;
            mid = top;
        } else {
            top->right = temp;
            temp->left = top;
            top = top->right;
            if (size & 1)
                mid = mid->right;
        }
        size++;
    }
    void pop() {
        if (size = 0) return;
        if (size == 1) {
            top = NULL;
            mid = NULL;

        } else {
            top = top->left;
            top->right = NULL;
            if (!size & 1) {  // even length list
                mid = mid->left;
            }
        }
        size--;
    }
    int get_mid() {
        if (size == 0) return INT_MIN;
        return mid->data;
    }
    void pop_mid() {
        if (size == 0) return;
        if (size == 1) {
            top = NULL;
            mid == NULL;
        } else if (size == 2) {
            top = top->left;
            mid = mid->left;
            top->right = NULL;
        } else {
            mid->left->right = mid->right;
            mid->right->left = mid->left;
            // move mid pointer to left or right based on the size of list
            // if odd -> mode right as assumed next
            // if even then move left.
            mid = (size & 1) ? mid->right : mid->left;
        }
        size--;
    }
    void show() {
        Node *temp = top;
        while (temp) {
            cout << "<-" << temp->data;
            temp = temp->left;
        }
        cout << " END\n";
    }
};

int main() {
    Stack st;
    st.push(11);
    st.push(22);
    st.push(33);
    st.push(44);
    st.push(55);
    st.show();
    st.pop_mid();
    st.show();
    st.pop_mid();
    st.show();
    st.pop_mid();
    st.show();
    cout << st.get_mid() << endl;
    st.pop_mid();
    cout << st.get_mid() << endl;
    return 0;
}