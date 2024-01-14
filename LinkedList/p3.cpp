#include <iostream>
using namespace std;
class Node {
private:
    int elem;
    Node* next = nullptr;
    friend class Linked;
};

class Linked {
private:
    Node* head;
    Node* tail;
    int size;
public:
    Linked() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    bool empty() const {
        return size == 0;
    }
    void addBack(int e) {
        Node* v = new Node;
        v->elem = e;
        if (empty()) {
            head = tail = v;
            v->next = v;
        } else {
            v->next = head;
            tail->next = v;
            tail = v;
        }
        size++;
    }
    void print() const {
        Node* current = head;
        for (int i = 0; i < size; i++) {
            std::cout << current->elem << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
    void remove(int idx) {
        if(idx >= size){
            idx = idx % size;
        }
        Node* cur = head;
        Node* prev = nullptr;

        for (int i = 0; i < idx; i++) {
            prev = cur;
            cur = cur->next;
        }

        if (cur == head) {
            head = cur->next;
            tail->next = head;
        } else if (cur == tail) {
            tail = prev;
            tail->next = head;
        } else {
            prev->next = cur->next;
        }
        delete cur;
        size--;
    }
};

int main() {

    int num;
    cin >>num;
    int x;
    string cmd;
    for(int i = 0; i < num; i++){
        Linked list;
        for(int i = 0; i < 10; i++){
            cin >> x;
            list.addBack(x);
        }
        for(int i = 0; i < 3; i++){
            cin >> cmd;
            if(cmd == "Delete"){
                cin >> x;
                list.remove(x);
            }

        }
        list.print();
    }
    return 0;
}