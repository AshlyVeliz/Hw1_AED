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
    int _size;

public:
    ForwardList() : head(nullptr), _size(0) {}

    bool empty() {
        return head == nullptr;
    }

    int size() const {
        return _size;
    }

    T front() {
        if (!head) throw runtime_error("Lista vacía");
        return head->val;
    }

    void push_front(T value) {
        Node* newNode = new Node{value, head};
        head = newNode;
        _size++;
    }

    T back() {
        if (!head) throw runtime_error("Lista vacía");
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
        _size++;
    }

    T pop_front() {
        if (empty()) throw runtime_error("La lista está vacía");
        Node* temp = head;
        T val = head->val;
        head = head->next;
        delete temp;
        _size--;
        return val;
    }

    T pop_back() {
        if (empty()) throw runtime_error("La lista está vacía");

        if (head->next == nullptr) {
            T val = head->val;
            delete head;
            head = nullptr;
            _size--;
            return val;
        }

        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }

        T val = current->next->val;
        delete current->next;
        current->next = nullptr;
        _size--;
        return val;
    }

    T operator[](int index) {
        if (index < 0 || index >= _size) throw out_of_range("El índice excede el tamaño de la lista");
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->val;
    }

    void clear() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
        _size = 0;
    }

    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void sort() {
        head = mergeSort(head);
    }

private:
    Node* findMiddle(Node* node) {
        if (!node) return nullptr;
        Node* slow = node;
        Node* fast = node;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    Node* merge(Node* left, Node* right) {
        if (!left) return right;
        if (!right) return left;

        Node dummy(0);
        Node* tail = &dummy;

        while (left && right) {
            if (left->val <= right->val) {
                tail->next = left;
                left = left->next;
            } else {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }

        tail->next = (left) ? left : right;

        return dummy.next;
    }

    Node* mergeSort(Node* node) {
        if (!node || !node->next) return node;

        Node* middle = findMiddle(node);
        Node* right = middle->next;
        middle->next = nullptr;

        Node* left = mergeSort(node);
        right = mergeSort(right);

        return merge(left, right);
    }
};
