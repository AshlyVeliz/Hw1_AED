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

<<<<<<< HEAD
    // 4 ultimos ejercicios 

    int size() const {
        // 23 til 28
        Node* temp = new Node(); 
        temp = head;
        if (!temp) return 0;
        if(temp->next) return 1;
        int count = 1;
        Node* curr = head;
        
        while (curr->next !=nullptr) {
            count++;
            curr = curr->next;
        }
        return count;
    }


    void clear() {
        // clear forward
        Node* temp = head;
        Node* aux = new Node();
        while(head){
            aux = head;
            head = head ->next;
            delete aux;
        }
    }

    // merge sort using private functions

    Node* findMiddle(Node* head) {
        if (!head) return nullptr;
        Node* slow = head;
        Node* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    Node* merge(Node* left, Node* right) {
        if (!left) return right;
        if (!right) return left;
    
        Node dummy(0, nullptr); // Dummy node to simplify merging
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
    
        if (left) tail->next = left;
        if (right) tail->next = right;
    
        return dummy.next;
    }

    Node* mergeSort(Node* head) {
        if (!head || !head->next) return head;

        Node* middle = findMiddle(head);
        Node* left = head;
        Node* right = middle->next;
        middle->next = nullptr; 

        left = mergeSort(left);
        right = mergeSort(right);

        return merge(left, right);
    }
    void sort() { // Para poder llamar a la funcion
        head = mergeSort(head);
    }

    

    // last reverse node
    void reverse(Node* head){
        Node* next = nullptr;
        Node* curr = head;
        Node* prev = nullptr;
        while (curr){
            next = curr->next;
            curr->next = prev;
            // advance one step // one node
            prev = curr; 
            curr = next;
        }
        head = prev; // because head is null
    }

};
=======
    bool empty() {
        return head == nullptr;
    }
    T pop_front() {
        if (empty()) throw runtime_error("La lista está vacía");
        Node* temp = head;
        T val = head->val;
        head = head->next;
        delete temp;
        size--;
        return val;
    }
    T pop_back() {
        if (empty()) throw runtime_error("La lista está vacía");
        if (head->next == nullptr) {
            T val = head->val;
            delete head;
            head = nullptr;
            size--;
            return val;
        }
        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        T val = current->next->val;
        delete current->next;
        current->next = nullptr;
        size--;
        return val;
    }

    T operator[](int index) {
        if (index < 0 || index >= size) throw out_of_range("El índice excede el tamaño de la lista");
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->val;
    }

};
>>>>>>> 8302aad (ejercicios 5 - 8 (Darlene))
