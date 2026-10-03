// COMSC-210 | Lab 17 | Huiluan Yie

#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next = nullptr;
};

//Function prototype
void output(Node *);
void add_front(Node*&);
void add_tail(Node*&);
void delete_node(Node*&);
void insert_node(Node*&);
void delete_entire(Node*&);
Node* get_node(Node*, float);

int main() {
    // declarations
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        Node *newVal = new Node;
        
        // adds node at head
        if (!head) {
            head = newVal;
            newVal->next = nullptr;
            newVal->value = tmp_val;
        }
        else {
            newVal->next = head;
            newVal->value = tmp_val;
            head = newVal;
        }
    }
    output(head);

    // deleting a node
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    // traverse that many times and delete that node
    Node *current = head;
    Node *prev = nullptr;  // start prev as nullptr to detect head deletion

    for (int i = 0; i < (entry - 1); i++) {
        prev = current;
        current = current->next;
    }

    // at this point, delete current and reroute pointers
    if (current) {
        if (prev == nullptr) {
            // deleting the head node
            head = current->next;
        } else {
            prev->next = current->next;
        }
        delete current;
        current = nullptr;
    }
    output(head);

    // insert a node
    cout << "After which node to insert 10000? " << endl;
    count = 1;
    current = head;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    current = head;
    prev = nullptr;  // reset prev to nullptr for same reason

    for (int i = 0; i < entry; i++) {
        prev = current;
        current = current->next;
    }

    // at this point, insert a node between prev and current
    Node *newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;

    if (prev == nullptr) {
        // inserting before the head
        head = newnode;
    } else {
        prev->next = newnode;
    }
    output(head);

    // deleting the linked list
    current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
    output(head);

    return 0;
}

//Function definition
void output(Node *hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node *current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

void add_front(Node*& hd)
{
    // add_front() adds node at head 
    // arguments: a node pointer by reference
    // returns: none

    // get the node to add
    float num;
    Node* n = nullptr;
    cout << "Please enter a number to add to the front of the linked list: ";
    cin >> num;
    n = get_node(num);
    
    // adds node at head
    if (!hd) {
        hd = n;
    }
    else {
        n->next = hd;
        hd = n;
    }
}

void add_tail(Node*& hd)
{
    // add_tail() adds node at tail 
    // arguments: a node pointer by reference
    // returns: none
    
    Node* t = hd;
    // go to the tail of this linked list 
    while (t != nullptr && t->next != nullptr)
    {
        t = t->next;
    }

    // get the node to add
    float num;
    Node* n = nullptr;
    cout << "Please enter a number to add to the tail of the linked list: ";
    cin >> num;
    n = get_node(num);

    // adds node at tail
    if (!t) {
        hd = n;
    }
    else {
        t->next = n;
    }

}

void delete_node(Node*& hd)
{
    // delete_node() deletes a node 
    // arguments: a node pointer by reference
    // returns: none

    cout << "Which node to delete? " << endl;
    output(hd);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    // traverse that many times and delete that node
    Node *current = hd;
    Node *prev = nullptr;  // start prev as nullptr to detect head deletion

    for (int i = 0; i < (entry - 1); i++) {
        prev = current;
        current = current->next;
    }

    // delete the node
    if (current) {
        if (prev == nullptr) {
            // deleting the head node
            hd = current->next;
        } else {
            prev->next = current->next;
        }
        delete current;
        current = nullptr;
    }

}

void insert_node(Node*& hd)
{
    // insert a node
    cout << "After which node to insert? " << endl;
    int count = 1;
    Node *current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    current = head;
    prev = nullptr;  // reset prev to nullptr for same reason

    for (int i = 0; i < entry; i++) {
        prev = current;
        current = current->next;
    }

    // at this point, insert a node between prev and current
    Node *newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;

    if (prev == nullptr) {
        // inserting before the head
        head = newnode;
    } else {
        prev->next = newnode;
    }
    output(head);

}

void delete_entire(Node*& hd)
{

}

Node* get_node(float v)
{
    // get_node() make a new node with the value passed in
    // arguments: a value
    // returns: a node pointer
    Node* new_node = new Node;
    new_node->value = v;
    return new_node;
}

Node* find_node(Node* hd, float target)
{
    // find_node() finds the target in the linked list
    // arguments: the header of the linked list, the target to find
    // returns: a node pointer
    Node* current = hd;
    while (current)
    {
        if (current->value == target)
        {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}