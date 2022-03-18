// basic step
// 1. count all 0,1,2 then change the content of ll
// single list can;t be traversed from the end
// 2. Merge sort:O(nlogn)
// 3. cant change value so change links
// Create 3 ll for, 0, 1 and 2;s

Node *segregate(Node *head) {
    if (!head) return head;

    Node *zerosH = new Node(-1);
    Node *zeros = zerosH;
    Node *onesH = new Node(-1);
    Node *ones = onesH;
    Node *twosH = new Node(-1);
    Node *twos = twosH;
    Node *temp = head;
    while (temp) {
        int data = temp->data;
        if (data == 0) {
            zeros->next = temp;
            zeros = zeros->next;
        } else if (data == 1) {
            ones->next = temp;
            ones = ones->next;
        } else {
            twos->next = temp;
            twos = twos->next;
        }
        temp = temp->next;
    }
    // if 0's or 2;s are not presnet then it will handle autoamtically
    //  mapping zeros to either ones or twos list.
    if (onesH->next) {
        zeros->next = onesH->next;
    } else {
        zeros->next = twosH->next;
    }
    // mapping ones to twos
    ones->next = twosH->next;
    twos->next = NULL;
    head = zerosH->next;
    // delete z
    delete zerosH;
    delete onesH;
    delete twosH;

    return head;
}