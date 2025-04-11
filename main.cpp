#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class ForwardList {
private:
    struct Node {
        T val;
        Node* next;
        Node(T a, Node* next = nullptr) : val(a), next(next) {}
    };

    Node* head;
    int size;

public:
    ForwardList() : head(nullptr), size(0) {}

    T front() {
        if (!head) throw runtime_error("Lista vacia");
        return head->val;
    }

    void push_front(T value) {
        Node* newNode = new Node{value, head};
        head = newNode;
        size++;
    }

    T back() {
        if (!head) throw runtime_error("Lista vacia");
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        return temp->val;
    }

    void push_back(T value) {
        Node* newNode = new Node{value, nullptr};
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }
};
