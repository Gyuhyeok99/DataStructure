#include <iostream>
#include <string>
using namespace std;

typedef string Elem;

class StringNode {
private:
    Elem elem;
    StringNode* next; // 다음 노드를 가리키는 것

    friend class StringLinkedList;
};

class StringLinkedList {
private:
    StringNode* head; //가장 앞
    StringNode* tail; //가장 뒤

public:
    StringLinkedList();
    ~StringLinkedList();
    bool empty() const; // 비어있으면 true return
    Elem front() const; // 첫 번째 elem에 저장된 데이터 return
    void addFront(const Elem& e); //헤드에서 삽입 연산
    void removeFront(); // 헤드에서 삭제 연산
    void addBack(const Elem& e); // 테일에서 삽입 연산
    void removeBack(); // 테일에서 삭제 연산

};
StringLinkedList::StringLinkedList() {
    head = NULL;
    tail = NULL;
}

StringLinkedList::~StringLinkedList() {
    while(!empty()){
        removeFront();
    }
}
bool StringLinkedList::empty() const {
    return head == NULL;
}

Elem StringLinkedList::front() const {
    if(empty()) {
        return NULL;
    }
    return head->elem;
}

void StringLinkedList::addFront(const Elem& e) {
    StringNode* v = new StringNode;
    if(empty()) {
        tail = v;
    }
    v->elem = e;
    v->next = head;
    head = v;
}

void StringLinkedList::removeFront() {
    if(empty()) {
        return;
    }
    StringNode* old = head;
    head = old->next;
    delete old;
    if(empty()) {
        tail = NULL;
    }
}

void StringLinkedList::addBack(const Elem &e) {
    StringNode* v = new StringNode;
    v->elem = e;
    v->next = NULL;
    if(empty()) {
        head = tail = v;
    }
    else {
        tail->next = v;
        tail = v;
    }
}

void StringLinkedList::removeBack() {
    if(empty()) {
        return;
    }
    StringNode* current = head;
    if(current == tail) {
        head = tail = NULL;
        delete current;
    }
    else {
        while(current->next != tail) {
            current = current->next;
        }
        tail = current;
        delete tail->next;
        tail->next = NULL;
    }
}
