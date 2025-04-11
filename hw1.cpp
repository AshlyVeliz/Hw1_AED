#include <bits/stdc++.h>

using namespace std;

template <typename T>
class ForwardList {

    private:
        // Sorting the LL

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

    public:
    struct Node{
        T val;
        Node* next;
        Node(): val(0), next(nullptr){}
        Node(T a, Node* n): val(a), next(n){} // Constuctores de ese tipo no emplean ; para finalizar

    };

    Node* head;
    int size;

    ForwardList() : head(nullptr), size(0) ;{}

    ~ForwardList(){
        clear(); // limpia la memoria dinamica (?) y estatica dentro de la lista
    }



    // my part

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