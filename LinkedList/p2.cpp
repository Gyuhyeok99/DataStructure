#include <iostream>
using namespace std;
typedef int Elem;

class Node {
private:
    Elem elem;
    Node* next = NULL;

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

    void addBack(const Elem& elem) {
        Node* v = new Node;
        v->elem = elem;
        if(empty()) {
            head = tail = v;
        }
        else {
            tail->next = v;
            tail = v;
        }
    }

    void showList() const {
        if(empty()) {
            cout << -1 << endl;
            return;
        }
        Node* cur = head;
        while(cur != NULL) {
            cout << cur->elem << ' ';
            cur = cur->next;
        }
        cout << endl;
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
        }else if(cmd == "addBack") {
            cin >> x;
            linkedList.addBack(x);
        }else if(cmd == "showList"){
            linkedList.showList();
        }
    }
}