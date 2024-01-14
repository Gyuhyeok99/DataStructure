#include <iostream>
using namespace std;
typedef int Elem;

class Node {
private:
    Elem elem;
    Node* next;

    friend class LinkedList;
};

class LinkedList {
private:
    Node* head;
    Node* tail;
public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    int empty() const {
        if(head == NULL) {
            return 1;
        }
        else {
            return 0;
        }
    }
    int front() const {
        if(empty()) {
            return -1;
        }
        return head->elem;
    }

    void addFront(const Elem& elem) {
        Node* v = new Node;
        v->elem = elem;
        if(empty()) {
            tail = v;
        }
        v->next = head;
        head = v;
    }

    int removeFront() {
        if(empty()) {
            return -1;
        }
        Node* old = head;
        Elem e = old->elem;
        head = head->next;
        delete old;
        if(empty()) {
            tail = NULL;
        }
        return e;
    }
};

int main() {
    int n;
    cin >> n;
    string cmd;
    LinkedList linkedList;
    int x;
    for(int i = 0; i < n; i++) {
        cin >> cmd;
        if(cmd == "addFront"){
            cin >> x;
            linkedList.addFront(x);
        }else if(cmd == "removeFront"){
            cout << linkedList.removeFront() << endl;
        }else if(cmd == "front"){
            cout << linkedList.front() << endl;
        }else if(cmd == "empty"){
            cout << linkedList.empty() << endl;
        }
    }
}