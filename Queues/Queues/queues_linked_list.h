//
//  queues_linked_list.h
//  Queues
//
//  Created by Sunhak Lov on 10/29/24.
//

#ifndef queues_linked_list_h
#define queues_linked_list_h

template <typename T>
struct node{
    T key ;
    node<T>* next = nullptr ;
};

template <typename T>
class queues{
public:
    void enqueue(const T& ) ;
    void dequeue() ;
    void print_queue() ;
    T& front() ;
    T& back() ;
    int size() ;
private:
    node<T>* first = nullptr ;
    node<T>* last = nullptr ;
    int count = 0 ;
};

template <typename T>
void queues<T>::enqueue(const T& value) {
    node<T>* newNode = new node<T> { value } ;
    if(count == 0){
        first = newNode ;
        last = newNode ;
    }
    else {
        last->next = newNode ;
        last = newNode ;
    }
    count++ ;
}

template <typename T>
void queues<T>::dequeue() {
    if (count == 0) {
            std::cout << "Queue is empty; cannot dequeue." << std::endl;
            return;
        }
    else {
        node<T>* temp = first ;
        first = first-> next ;
        delete temp ;
        temp = nullptr ;
        count-- ;
    }
}

template <typename T>
void queues<T>::print_queue() {
    node<T>* temp = first ;
    std::cout << "front of the queue : " ;
    while(temp){
        std::cout << temp->key << " ";
        temp = temp-> next ;
    }
    std::cout << ": last of the queue" << std::endl ;
}

template <typename T>
T& queues<T>::front() {
    if (count == 0) {
        throw std::out_of_range("Queue is empty.");
    }
    return first-> key;
}

template <typename T>
T& queues<T>::back() {
    if (count == 0) {
        throw std::out_of_range("Queue is empty.");
    }
    return last->key;
}

template <typename T>
int queues<T>::size() {
    return count ;
}

#endif /* queues_linked_list_h */
