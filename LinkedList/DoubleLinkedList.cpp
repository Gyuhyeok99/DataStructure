#include <string>

using namespace std;

class Node{
private:
    int elem;
    Node* prev;
    Node* next;
    friend class DLinkedList;
};

class DLinkedList{
private:
    Node* header;
    Node* trailer;
public:
    DLinkedList(){
        header = new Node;
        trailer = new Node;
        header->next = trailer;
        trailer->prev = header;
    }
    ~DLinkedList() {
        while(!empty()){
            removeFront();
        }
        delete header;
        delete trailer;
    }
    bool empty() const{
        return header->next == trailer;
    }
    int front() const {
        return header->next->elem;
    }
    int back() const {
        return trailer->prev->elem;
    }

    void add(Node* v, int e){
        Node* u = new Node;
        u->elem = e;

        u->next = v;
        u->prev = v->prev;
        v->prev->next = u;
        v->prev = u;
    }
    void addFront(int e){
        add(header->next, e);
    }
    void addBack(int e){
        add(trailer, e);
    }
    void remove(Node* v){
        Node* u = v->prev;
        Node* w = v->next;
        u->next = w;
        w->prev = u;
        delete v;
    }
    void removeFront() {
        remove(header->next);
    }
};